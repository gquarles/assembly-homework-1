//CSC Programming Assignment #4
//Author:Griffin Quarles
//Description:
/*
    This program uses inline assembly for all of its logic
    the program will ask the user for a integer greater than 1
    then calculate all of the factors for that number, add
    the factors together and get the percentage of closeness
    to the originial number as a way to calculate how pure a
    number is
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main()
{
    //Declare variables
    int input;
    int sumOfFactors;
    int closeness;
    int hundred = 100;
   
    //Ask for input
    printf("Please input an integer greater than 1: ");
    scanf("%d", &input);

    while (input > 1) {
        //Initalize variables
        sumOfFactors = 0;
        closeness = 0;

        __asm {
            mov ecx, input //Load input into loop counter
            sub ecx, 1 //Decrement loop counter
            top: nop //Head of for loop
            mov eax, input //load input
            mov edx, 0 //0 edx
            div ecx //input / i
            mul ecx // i * (input / i)
            mov ebx, input
            sub ebx, eax //input - i* (input / i)
            cmp ebx, 0 // if input - i* (input / i) == 0
            jne xexit //If it is not, exit the loop
            mov eax, sumOfFactors //load sumOfFactors
            add eax, ecx //Add factor to sum of factors
            mov sumOfFactors, eax //Save to sumOfFactors
            xexit : nop //Exit if statement
            loop top //Loop back

            //Calculate closeness to pure number
            mov eax, sumOfFactors //Load the sum of factors into eax
            sub eax, input // sumOfFactors - input
            mul hundred // (sumOfFactors - input) * 100
            cmp eax, 0 // If (sumOfFactors - input) * 100 is negative
            jge skip //Jump to skip
            neg eax //Take abs value
            skip : mov edx, 0 //Zero out edx
            div input // ((sumOfFactors - input) * 100) / input
            mov closeness, eax //Load the closeness into the closeness var
        }

        //Print outputs from the assembly
        printf("Sum of factors: %d\n", sumOfFactors);
        printf("Input: %d\n", input);
        printf("Closeness: %d\n", closeness);

        //Ask for input
        printf("\nPlease input an integer greater than 1: ");
        scanf("%d", &input);

    }
    
}