/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 *  notes:
 *  ~ All required features are implemented :-)
 *  ~ Was unable to have Makefile in own function as had too many varables
 *      to pass in :'(
 */

#include "header.h" // includes libs and global constants

// Function files
#include "functions/pwd.c"
#include "functions/cd.c"
#include "functions/ls.c"
#include "functions/echo.c"
#include "functions/sleep.c"
#include "functions/sigintHandler.c"

int main (int argc, char const *argv[]) {
    
    signal(SIGINT, sigintHandler); // *FEATURE 3* SIGINT==CTR+C is catched
    char line[MAX]; // stores input
    char *cmd; // first word in input ie cmd
    char *arg;
    // set time 
    time_t rawtime;
    struct tm *tm_info;
    char buffer[20];
    time( &rawtime );
    tm_info = localtime( &rawtime );
    strftime(buffer, 20, "[%Y/%m/%d %H:%M]",tm_info); // [YY/MM/DD HH:MM]

    while (1) {
        printf("%s # ", buffer); // PROMPT
        if (!fgets(line, MAX, stdin)) break;

        if ((cmd = strtok(line, DELIMS))) {  // *Feature 1* 
            errno = 0; // Clear errors

            if (strcmp(cmd, "cd") == 0) { // choose dr cmd
                cd();
            }
            if (strcmp(cmd, "ls") == 0) { // show dr cmd
                myls();
            }
            if (strcmp(cmd, "pwd") == 0) { // path way dr cmd
                pwd();
            }
            if (strcmp(cmd, "echo") == 0) { // echo cmd
                echo();
            }
            if (strcmp(cmd, "sleep") == 0) { // sleep cmd
                mySleep();
            }
            else {
                arg = strtok(0, DELIMS);
                if (arg!=NULL) { // make file cmd
                    char output[MAX];
                    strncat(output, line, 30); // adds 1st arg to char
                    strncat(output,  " ", 30);
                    while(arg!=NULL) {
                        if (strcmp(arg, ">") == 0) {
                            //puts(output);
                            char *filename = strtok(0, DELIMS);
                            size_t length = strlen(output); 
                        int f = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666);
                            if (f == -1) perror ("open"); 
                            else
                                write(f, output, length);
                                close(f);
                            break;
                        }
                        strncat(output, arg, 30);// adds args to > to char
                        strncat(output,  " ", 30);
                        arg = strtok(0, DELIMS);
                    }
                }
                if(arg==NULL && (strcmp(cmd, "cd") != 0) && (strcmp(cmd, "ls") != 0) && (strcmp(cmd, "pwd") != 0) && (strcmp(cmd, "echo") != 0) && (strcmp(cmd, "sleep") != 0)) {
                    printf("%s: command not found\n", cmd); // unkown cmd
                }
            }
            if (errno) perror("command failed"); // error prompt 
        }
    }
    return 0;
}