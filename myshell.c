// Imports
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// Defining a variable to access the array of environment variables provided to the program from inside the main method
extern char **environ;

void echo(char value[])
{
    // Create a char array called temp to assemble the output in
    char temp[1000];

    // Copy rest of command to temp
    strncpy(temp, value + 5, 995);

    // Create a char array called result, copy the contents of temp to result and append a newline char to it
    char result[995];
    strcpy(result, temp);
    strcat(result, "\n");
    printf(result);
}

// Function to implement the ability to check if a command word is used within a longer string
bool StartsWith(const char *a, const char *b)
{
    if (strncmp(a, b, strlen(b)) == 0)
        return 1;
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    // Start an infinite loop
    bool done = false;
    while (done == false)
    {
        // Create a char array to hold input and take input from user
        char userinput[100];
        printf("myshell> ");
        gets(userinput);

        // Check for echo command
        if (StartsWith(userinput, "echo"))
        {
            echo(userinput);
        }

        // Check for environ command
        if (strcmp(userinput, "environ") == 0)
        {
            // Loop through environ array of environment variables
            int i = 0;
            while (environ[i])
            {
                printf("%s\n", environ[i++]);
            }
        }

        if (strcmp(userinput, "clr") == 0)
        {
            system("cls");
        }

        if (strcmp(userinput, "pause") == 0)
        {
            printf("Press [Enter] key to continue.\n");
            while (getchar() != '\n');
        }

        // Check for quit command
        if (strcmp(userinput, "quit") == 0)
        {
            done = true;
        }
    }
}