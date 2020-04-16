// asm23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main() {

	int a[20] = { 100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12 };
	int n = 20;
	int temp;
	int location;

	for (int i = 1; i < n; i++) {
		__asm {
			mov ecx, i //Load iterator into ecx
			mov eax, a[ecx*4] //Load a[i]
			mov temp, eax       //temp = a[i]
			dec ecx //dec location
			mov location, ecx   //location = i - 1
			inc ecx //Inc ecx after saving location
		}

		while (location >= 0 && a[location] > temp) {
			__asm {
				mov eax, location //Load in location
				mov ebx, a[eax*4] //Load in the var from array into ebx
				inc eax //incrment location
				mov a[eax*4], ebx //Save var in array  //a[location + 1] = a[location];
				dec eax //Decrement by 2               //location--;
				dec eax //eax is location
				mov location, eax //Save location
			}
			
		}

		__asm {
			mov eax, location //Move location into eax
			inc eax //increment eax to go further in the array
			mov ebx, temp //load temp into ebx
			mov a[eax*4], ebx //save a[location + 1] = temp;
		}
	}




	for (int z = 1; z < n; z++) {
		printf("%d ", a[z]);
	}

	return 0;
}