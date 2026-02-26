        scanf("%d", &ch);  
        switch (ch) {  
            case 1: printf("Value: "); scanf("%d", &val); insert(val); 
break; 
            case 2: printf("Delete: "); scanf("%d", &val); 
delete(val); break;  
            case 3: printf("Search: "); scanf("%d", &val); 
printf(search(val) ? "Found \n" : "Not Found \n"); break;  
            case 4: printf("Height: %d \n", height(root)); break;  
            case 5: inorder(root); break;  
            case 6: preorder(root); break;  
            case 7: postorder(root); break;  
            case 8: levelorder(); break;  
            case 9: return 0;  
            default: printf("Invalid \n"); 
        } 
    } 
}