/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */
#include <dirent.h> 
    
void myls() { 
    
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    DIR *dp = NULL; 
    struct dirent *dptr = NULL; 
    unsigned int count = 0; 
    dp = opendir((const char*)cwd); 
    
    for(count = 0; NULL != (dptr = readdir(dp)); count++) 
    { 
        if(dptr->d_name[0] != '.'){ 
            if(count % 2 == 0 || count==0){
                printf("%s\t",dptr->d_name); 
            }
            else
                printf("%s\n",dptr->d_name); 
        }
    } 
    printf("\n");
    closedir(dp);
 }