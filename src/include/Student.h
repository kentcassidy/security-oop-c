#ifndef STUDENT_H
#define STUDENT_H

#include "GenericTraits.h"
#include "Human.h"
#include <stdint.h>
#include <stdlib.h>

DECLARE_STRUCT(Student, {		
	GenericTraits *impl;	
	char name[256];
	int grade;	
})	

#endif