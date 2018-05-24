/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */

void mySleep(){
    char *arg = strtok(0, DELIMS);
    int sec = atoi(arg); 
    
    if (!arg) fprintf(stderr, "sleep missing argument.\n");
    else{ 
        sleep(sec);
        fflush(stdout);
    }
}
