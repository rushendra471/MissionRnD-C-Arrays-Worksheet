/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct student {
	char name[10];
	int score;
};
void strcopy(char *s1, char *s2){
	int i = -1;
	while (s1[++i] != '\0')
		s2[i] = s1[i];
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students==NULL||len<=0)
		return NULL;
	int i, j;
	char *t;
	t = (char *)malloc(sizeof(char));
	for (i = 0; i < len - 1; i++){
		for (j = 0; j < len - i -1; j++){
			if (students[j].score < students[j + 1].score){
				strcopy(students[j].name, t);
				strcopy(students[j].name, students[j+1].name);
				strcopy(t,students[j+1].name);
				
				int temp = students[j].score;
				students[j].score = students[j + 1].score;
				students[j + 1].score = temp;
			}
		}
	}
}