/*  COMP20200 UNIX PROGRAMMING
 *  Assignment 2 ** Implement a simple shell **
 *  Benjamin Kelly (14700869) benjamin.kelly.1@ucdconnect.ie
 *  
 *  Version 1.0 
 */
/*
    *FEATURE 3* SIGINT==CTR+C is catched and is defined to nothing here
*/

void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
}