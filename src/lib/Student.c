#include "Student.h"
#include "Human.h"
#include "stdint.h"
#include "string.h"

void *new_Student(char *string) {
	// Allocate for this Int struct
	Student *student_obj = malloc(sizeof(Student));
	if (student_obj == NULL) {
		fprintf(stderr, "Error: Couldn't create Student struct\n");
		return NULL;
	}

	Constructor human_ctor = get_constructor("Human");
	if (human_ctor == NULL) {
        free(student_obj);
        return NULL;
    }

	// Split then initialize - human name* and student portion**
	char string_cpy[255];
	strcpy(string_cpy, string);
	char *token;
	// * Initialize the Human part of Student using the constructor
	token = strtok(string_cpy, " ");
	Human *tmp_human = (Human *)new_Human(token);
    student_obj->human_sub = *tmp_human;
	student_obj->impl = tmp_human->impl;
    if (&(student_obj->impl) == NULL) {
        free(student_obj);
        return NULL;
    }
	// **
	token = strtok(NULL, " \n");
	student_obj->grade = (int32_t)atoi(token);
	free(tmp_human);

    // Initialize the GenericTraits struct with Int's functions
    student_obj->impl->new = new_Student;
    student_obj->impl->dump = dump_Student;
    student_obj->impl->cmp = cmp_Student;
    student_obj->impl->drop = drop_Student;

	return student_obj;
}

void dump_Student(void *self, FILE *fp) { // ORDER??
	Student *this = (Student *)self;
	//fprintf(fp, "%d %s\n", this->grade, this->name);
	fprintf(fp, "%s %d\n", this->human_sub.name, this->grade);
}

int cmp_Student(void *self, void *other) {
	Student *student_self = (Student *)self;
	Student *student_other = (Student *)other;
	int result;

	if (student_self->grade < student_other->grade) {
		result = -1;
	} else if (student_self->grade > student_other->grade) {
		result = 1;
	} else {
		result = strcmp(student_self->human_sub.name, student_other->human_sub.name);
	}

	if (result < 0) {
		return -1;
	} else if (result > 0) {
		return 1;
	} else {
		return 0;
	}
}

DEFINE_STRUCT(Student)