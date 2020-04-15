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

/*
Please input an integer greater than 1: 4
Sum of factors: 3
Input: 4
Closeness: 25

Please input an integer greater than 1: 32
Sum of factors: 31
Input: 32
Closeness: 3

Please input an integer greater than 1: 50
Sum of factors: 43
Input: 50
Closeness: 14

Please input an integer greater than 1: 51
Sum of factors: 21
Input: 51
Closeness: 58

Please input an integer greater than 1: 64
Sum of factors: 63
Input: 64
Closeness: 1

Please input an integer greater than 1: 81
Sum of factors: 40
Input: 81
Closeness: 50

Please input an integer greater than 1: 500
Sum of factors: 592
Input: 500
Closeness: 18

Please input an integer greater than 1: 8128
Sum of factors: 8128
Input: 8128
Closeness: 0

Please input an integer greater than 1: 90000
Sum of factors: 224743
Input: 90000
Closeness: 149
*/