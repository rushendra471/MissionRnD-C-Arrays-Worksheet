
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	*lessCount = 0;
	*moreCount = 0;
	if (Arr == NULL || len <= 0)
		return NULL;
	if (score < Arr[0]){
		*lessCount = 0;
		*moreCount = len;
		return 0;
	}
	else if (score>Arr[len - 1]){
		*lessCount = len;
		*moreCount = 0;
		return 0;
	}
	int low = 0, high = len - 1, mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (Arr[mid] == score){
			if (Arr[mid - 1] == score)
				high = mid - 1;
			else if (Arr[mid + 1] == score)
				low = mid + 1;
			else{
				*lessCount = mid;
				*moreCount = len - mid - 1;
				break;
			}
		}
		else if (score > Arr[mid] && score < Arr[mid + 1]){
			*lessCount = mid + 1;
			*moreCount = len - mid - 1;
			break;
		}
		else if (score < Arr[mid] && score > Arr[mid - 1]){
			*lessCount = mid;
			*moreCount = len - mid;
			break;
		}
		else if (score>Arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
}
