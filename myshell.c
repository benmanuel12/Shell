#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



void echo(char value[])
{
    char temp[1000];
    strncpy(temp, value + 5, 995);
    char result[995] = "hello";
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
            echo(userinput);
        }

        if (strcmp(userinput, "quit") == 0)
        {
            done = true;
        }
    }
    return 0;
}