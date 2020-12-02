// Created by Rome357g for Advent of Code 2020 Day 2.1
// Given input such as 4-5 r: rrrjr, only four to five 'r's can be found in rrrjr, each input password is unique
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // using input.txt in same directory with 1000 passwords
    FILE *fp;
    char buff[1000];
    fp = fopen("input.txt", "r");

    // This for loop iterates through every single line in the text as independent string
    for (int x = 0; x < 1000; x++)
    {
        // This will load the current line in external file, the compiler tracks what location we are on
        fgets(buff, 255, (FILE *) fp);
        // Creating a char array currentline and copying the buffer memory to it as you can't copy chars directly
        char currentline[50];
        strcpy(currentline, buff);
        // Clib function to create a char array going up to "-" in given text
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
            // printf("%s\n", token4);
            // Counting length of fourth token, which for first example is rrrjr and should be 5
            unsigned int y;
            for (y = 1; y < strlen(token4); y++)
            {
              //   printf(" %i ", y);
            }
            // Now we index into the third token, the control character r in this case, and iterate through last token
            // For the current example lettertotal should be 4
            int lettertotal = 0;
            int yy = (int) y;
            for (int z = 0; z < yy; z++)
            {
                if (token3[0] == token4[z])
                {
                    lettertotal++;
                    // printf("%i", lettertotal);
                }
            }
            // printf("%i", lettertotal);
            // Casting the first and second tokens to an integer
            int lowerboundary = atoi(token);
            int upperboundary = atoi(token2);
            // printf("the range is %i to %i", lowerboundary, upperboundary);
            int correctpasswords;

            // If lettertotal (4) is less than or equal to 5 and greater than or equal to 4 we iterate correctpassword count
            if (lettertotal <= upperboundary && lettertotal >= lowerboundary)
            {
                correctpasswords++;
                printf("%i ", correctpasswords);
            }

        }
        // printf("%s", buff);
    }
    fclose(fp);
}
