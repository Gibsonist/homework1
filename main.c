#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "ctype.h"

#define SIZE 256

int checkForNonDigits(char string[]);
void convertToBinary(unsigned long long n);

int main()
{
    //input variable
    char input[SIZE];

    //variable cleanout and user input
    for(int i = 0; i < SIZE; i++)
        input[i] = '\0';
    printf("Input decimal number to convert to binary:");
    fgets(input, SIZE, stdin);

    //checking if input has no mistakes
    bool noErrors = true;
    switch (checkForNonDigits(input))
    {
        case 1:
            printf("Empty input! Program ended with errors");
            noErrors = false;
            break;
        case 2:
            printf("Wrong input! Program ended with errors");
            noErrors = false;
            break;
        case 3:
            printf("Overflow error, too many numbers! Program ended with errors");
            noErrors = false;
            break;
        default:
            break;
    }
    if(!noErrors)
        return 1;

    //converting input to integer
    unsigned long long inputNumber = atoi(input);

    printf("Your binary number:");
    //output binary
    convertToBinary(inputNumber);

    printf("\nProgram ended with no errors\n");
    return 0;
}

int checkForNonDigits(char string[])
{
    int counter = 0;
    if(string[0] == '\n') //check for empty input
    {
        return 1;
    }
    for(int i = 0; string[i + 1] != '\0'; i++) //check for non digits
    {
        if(!isdigit(string[i]))
        {
            return 2;
        }
        counter++;
    }

    if (counter > 18) //overflow check
        return 3;

    return 0;
}

void convertToBinary(unsigned long long n) //recursive decimal to binary converter
{
    if (n / 2 != 0)
        convertToBinary(n / 2);
    printf("%d", n % 2);
}