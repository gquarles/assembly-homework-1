#include <stdio.h>
#include <iostream>

int main()
{
    int input = 12;
    int sumOfFactors = 0;
    int closeness = 0;
    int hundred = 100;
    int test = 0;


    printf("%d\n", test);

    for (int i = 1; i < input; i++) {
        if (input - i * (input / i) == 0) {
            sumOfFactors += i;
        }
        __asm {

        }
    }

    printf("Sum of factors: %d\n", sumOfFactors);

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

    printf("Input: %d\n", input);
    printf("Closeness: %d\n", closeness);
    
}