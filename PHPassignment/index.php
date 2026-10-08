<?php
// ---------- SETTINGS ----------
$api_key = "";
$model   = "gemini-3.8-flash";

$conn = mysqli_connect("localhost", "root", "");

mysqli_query($conn, "CREATE DATABASE IF NOT EXISTS codelens");
mysqli_select_db($conn, "codelens");
mysqli_query($conn, "CREATE TABLE IF NOT EXISTS history (
    id INT AUTO_INCREMENT PRIMARY KEY,
    language VARCHAR(20),
    code TEXT,
    result TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)");

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['code'])) {
    $code     = $_POST['code'];
    $language = $_POST['language'];

    $prompt = "You are a code analyzer. Analyze the following $language code. 
Find:
1. Errors (syntax errors, bugs, security issues)
2. Warnings (potential problems, bad practices)  
3. Improvements (better ways to write the code, performance tips)

Format your response EXACTLY like this (use these exact headers):
## Errors
- error description (line X)

## Warnings  
- warning description (line X)

## Improvements
- improvement suggestion

## Score
X/100

Here is the code:
```
$code
```";

    // Call Gemini API
    $url = "https://generativelanguage.googleapis.com/v1beta/models/$model:generateContent";

    $data = json_encode([
        "contents" => [
            ["parts" => [["text" => $prompt]]]
        ]
    ]);

    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, [
        "Content-Type: application/json",
        "x-goog-api-key: $api_key"
    ]);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_TIMEOUT, 60);
    $response = curl_exec($ch);
    $curl_error = curl_error($ch);
    curl_close($ch);

    // Handle errors
    if ($response === false) {
        $result = "cURL Error: " . $curl_error;
    } else {
        $json = json_decode($response, true);
        if (isset($json['candidates'][0]['content']['parts'][0]['text'])) {
            $result = $json['candidates'][0]['content']['parts'][0]['text'];
        } elseif (isset($json['error']['message'])) {
            $result = "API Error: " . $json['error']['message'];
        } else {
            $result = "Unexpected response: " . $response;
        }
    }

    // Save to database
    $safe_code   = mysqli_real_escape_string($conn, $code);
    $safe_result = mysqli_real_escape_string($conn, $result);
    $safe_lang   = mysqli_real_escape_string($conn, $language);
    mysqli_query($conn, "INSERT INTO history (language, code, result) VALUES ('$safe_lang', '$safe_code', '$safe_result')");
}
$history = mysqli_query($conn, "SELECT * FROM history ORDER BY created_at DESC LIMIT 5");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>CodeLens - AI Code Analyzer</title>
</head>
<body>

<header>
    <h1>🔍 Code<span>Lens</span></h1>
    <p>Paste your code → Get AI-powered analysis, errors &amp; improvements</p>
</header>

<div class="container">
    <div class="form-box">
        <form method="POST">
            <label>📝 Select Language:</label>
            <select name="language">
                <option value="PHP" <?= (isset($language) && $language == 'PHP') ? 'selected' : '' ?>>PHP</option>
                <option value="JavaScript" <?= (isset($language) && $language == 'JavaScript') ? 'selected' : '' ?>>JavaScript</option>
                <option value="Python" <?= (isset($language) && $language == 'Python') ? 'selected' : '' ?>>Python</option>
                <option value="HTML" <?= (isset($language) && $language == 'HTML') ? 'selected' : '' ?>>HTML</option>
                <option value="CSS" <?= (isset($language) && $language == 'CSS') ? 'selected' : '' ?>>CSS</option>
                <option value="Java" <?= (isset($language) && $language == 'Java') ? 'selected' : '' ?>>Java</option>
                <option value="C++" <?= (isset($language) && $language == 'C++') ? 'selected' : '' ?>>C++</option>
            </select>

            <label>💻 Paste Your Code:</label>
            <textarea name="code" placeholder="Paste your code here..."><?= isset($code) ? htmlspecialchars($code) : '' ?></textarea>

            <button type="submit" class="btn">⚡ Analyze Code</button>
        </form>
    </div>
    <?php if (isset($result)): ?>
    <div class="result-box">
        <h2>📊 Analysis Result</h2>
        <div class="result-content"><?= nl2br(htmlspecialchars($result)) ?></div>
    </div>
    <?php endif; ?>
    <?php if (mysqli_num_rows($history) > 0): ?>
    <div class="history-box">
        <h2>📜 Recent Analysis History</h2>
        <?php while ($row = mysqli_fetch_assoc($history)): ?>
        <div class="history-item">
            <span class="lang-tag"><?= htmlspecialchars($row['language']) ?></span>
            <small><?= $row['created_at'] ?></small>
            <pre><?= htmlspecialchars(substr($row['code'], 0, 100)) ?>...</pre>
        </div>
        <?php endwhile; ?>
    </div>
    <?php endif; ?>

</div>
<footer>&copy; 2026 CodeLens — AI-Powered Code Analyzer</footer>
</body>
</html>