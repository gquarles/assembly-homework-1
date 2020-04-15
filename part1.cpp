#include <stdio.h>
#include <iostream>

int main()
{
    int input = 50;
    int sumOfFactors = 0;
    int closeness = 0;
    int hundred = 100;
    int test = 0;

    __asm{
        mov ecx, input
        sub ecx, 1
        top: nop
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
        xexit: nop //Exit Loop
        loop top
    }

    

    __asm {
        //Calculate closeness to pure number
        mov eax, sumOfFactors //Load the sum of factors into eax
        sub eax, input // sumOfFactors - input
        mul hundred // (sumOfFactors - input) * 100
        cmp eax, 0 // If (sumOfFactors - input) * 100 is negative
        jge skip //Jump to skip
        neg eax //Take abs value
        skip: mov edx, 0 //Zero out edx
        div input // ((sumOfFactors - input) * 100) / input
        mov closeness, eax //Load the closeness into the closeness var
    }

    printf("Sum of factors: %d\n", sumOfFactors);
    printf("Input: %d\n", input);
    printf("Closeness: %d\n", closeness);
    
}