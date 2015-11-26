/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int left = 0, right = len - 1, i;
	while (left < right){
		if (Arr[left] > Arr[left + 1])
			for (i = right; i > left; i--)
				if (Arr[i] < Arr[i - 1]){
					len = Arr[i];
					Arr[i] = Arr[left];
					Arr[left] = len;
					return 0;
				}
		else if (Arr[right] < Arr[right - 1])
			for (i = left; i < right; i++)
				if (Arr[i]>Arr[i + 1]){
					len = Arr[i];
					Arr[i] = Arr[right];
					Arr[right] = len;
					return 0;
				}
		left++;
		right--;
	}
}