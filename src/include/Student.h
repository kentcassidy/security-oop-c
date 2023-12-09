#ifndef STUDENT_H
#define STUDENT_H

#include "GenericTraits.h"
#include "Human.h"
#include <stdint.h>
#include <stdlib.h>

DECLARE_STRUCT(Student, {		
	// Must not be a pointer for sake of destructor
	GenericTraits *impl;
	Human human_sub; // Wholly unnecessary (Human would otherwise only include name), but demonstrates inheritance
	int grade;	
})	

#endif