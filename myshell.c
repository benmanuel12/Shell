#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



void echo(char value[])
{
    printf("Starting");
    char temp[100];
    //strncpy(temp, value, (int) value + 5);
    char* result[strlen(temp) + 2] = "hello";
    strcpy(result, temp);
    strcat(result, "\n");
    printf(result);
}

int main()
{
    bool done = false;
    while (done == false)
    {
        char userinput[100];
        printf("myshell> ");
        gets(userinput);

        // copy off front 5 characters
        char front[6];
        strncpy(front, userinput, 5);
        // if its "echo " then
        if (strcmp(front, "echo @") == 0)
        {
            printf("Echoing");
            echo(userinput);
        }

        if (strcmp(userinput, "quit") == 0)
        {
            done = true;
        }
    }
    return 0;
}