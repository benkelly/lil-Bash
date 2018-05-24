/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */

    
void pwd(){
    char *arg = strtok(0, DELIMS);
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}        
