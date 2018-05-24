/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */

void cd(){
    char *arg = strtok(0, DELIMS);

    if (!arg) fprintf(stderr, "cd missing argument.\n");
    else chdir(arg);
}        
