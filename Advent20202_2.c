// Created by Rome357g for Advent of Code 2020 Day 2.2
// Given input such as 4-5 r: rrrjr, position 4 contains j and position 5 contains r. There can be only one letter at the designated numbers, so XOR?
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // using input.txt in same directory with 1000 passwords
    FILE *fp;
    char buff[1000];
    fp = fopen("input.txt", "r");
    int correctpasswords = 0;
    // This for loop iterates through every single line in the text as independent string
    for (int x = 0; x < 1000; x++)
    {
        // This will load the current line in external file, the compiler tracks what location we are on
        fgets(buff, 255, (FILE *) fp);
        // Creating a char array currentline and copying the buffer memory to it as you can't copy chars directly
        char currentline[50];
        strcpy(currentline, buff);
        // C library function to create a char array going up to "-" in given text
        char *token = strtok(currentline, "-");
        // printf("%s\n", token);
        // the strtok "string token" function works like the fgets function and has to be iterated through until end of line.
        if (token != NULL)
        {
            // So the next token will be whichever comes first, "null" or " "
            char *token2 = strtok(NULL, " ");
            char *token3 = strtok(NULL, ":");
            char *token4 = strtok(NULL, " ");
            // printf("%s\n", token2);
            // printf("%s\n", token3);
            printf("%s\n", token4);

            // Casting the first and second tokens to an integer, in this example 4 and 5
            int lowerboundary = atoi(token) - 1;
            int upperboundary = atoi(token2) - 1;
            // The fourth and fifth letters in this example, 'j' and 'r'
            char firstletter = token4[lowerboundary];
            char secondletter = token4[upperboundary];
            // Control character or 'r' in this example
            char control = token3[0];
            printf(" %c and %c ", firstletter, secondletter);
            printf(" %c ", token3[0]);
            //using exclusive OR (XOR or ^) to only increment if one or the other has the control character exclusively
            if ((control != firstletter) ^ (control != secondletter))
            {
                correctpasswords++;
                printf(" %i ", correctpasswords);
            }
        }
    }
    fclose(fp);
}
