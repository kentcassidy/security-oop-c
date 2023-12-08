#ifndef STUDENT_H
#define STUDENT_H

#include "GenericTraits.h"
#include "Human.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct Student {
	GenericTraits *impl;
	int grade;
	char *name;
} Student;

void *new_Student(char *);
void dump_Student(void *self, FILE *fp);
int cmp_Student(void *self, void *other);
void drop_Student(void *self);

void __attribute__((constructor)) register_Student();

#endif