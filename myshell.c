#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    bool done = false;
    while (done == false)
    {
        char userinput[100];
        printf("myshell> ");
        gets(userinput);

        // copy off front 5 characters
        char front[] = strncpy(front, userinput, 5);
        // if its "echo " then
        if (strcmp(front, "echo ") == 0)
        {
            // make a pointer to the character after the space after the o in echo
            char backpointer[] = strchr(userinput, 'o') + 2;

            // make an arbitrarily large output
            char output[100001];
            
            // copy everything else from the input to the output
            strncpy(output, userinput, backpointer);

            // copy the output to a new string 2 characters longer
            char *result = malloc(strlen(output) + 2);
            strcpy(result, output);

            // add a new line
            strcat(result, "\n");

            // print it out
            printf(result);
        }

        if (strcmp(userinput, "quit") == 0)
        {
            done = true;
        }
    }
    return 0;
}

void echo(char value[])
{
    puts(value);
}