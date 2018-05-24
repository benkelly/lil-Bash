/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */

void echo(){
    char *arg = strtok(0, DELIMS);
    if (!arg) fprintf(stderr, "echo missing argument.\n");
    if (arg!=NULL){
        while(arg!=NULL){
            //puts(arg);
            printf("%s ", arg);
            arg = strtok(0, DELIMS);
        }
        printf("\n");
    }
}        
