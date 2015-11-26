/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void strcopy2(char *s1, char *s2){
	int i = -1;
	while (s1[++i] != '\0')
		s2[i] = s1[i];
}

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || len <= 0 || K<=0)
		return NULL;
	if (K > len)
		K = len;
	int i,j,s;
	struct student **topstudents = (struct student **) malloc(sizeof(struct student *) * K);
	for (i = 0; i < K; i++)
		topstudents[i] = (struct student *) malloc(sizeof(struct student) * K);
	for (i = 0; i < K; i++) 
		*topstudents[i] = students[i];
	for (i = K; i < len; i++) {
		s = 0;
		for (j = 1; j < K; j++) 
		if (topstudents[s]->score > topstudents[j]->score)
				s = j;
		if (students[i].score > topstudents[s]->score)
			*topstudents[s] = students[i];
	}
	return topstudents;
}