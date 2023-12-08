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

	// Allocate for contained GenericTraits struct
    student_obj->impl = malloc(sizeof(GenericTraits));
    if (student_obj->impl == NULL) {
        fprintf(stderr, "Error: Couldn't create GenericTraits struct\n");
        free(student_obj);
        return NULL;
    }

    // Initialize the GenericTraits struct with Int's functions
    student_obj->impl->new = new_Student;
    student_obj->impl->dump = dump_Student;
    student_obj->impl->cmp = cmp_Student;
    student_obj->impl->drop = drop_Student;

	// Initialize actual student
	char string_cpy[255];
	strcpy(string_cpy, string);
	char *token;
	token = strtok(string_cpy, " ");
	strcpy(student_obj->name, token);
	token = strtok(NULL, " \n");
	student_obj->grade = (int32_t)atoi(token);
	return student_obj;
}

void dump_Student(void *self, FILE *fp) { // ORDER??
	Student *this = (Student *)self;
	//fprintf(fp, "%d %s\n", this->grade, this->name);
	fprintf(fp, "%s %d\n", this->name, this->grade);
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
		result = strcmp(student_self->name, student_other->name);
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