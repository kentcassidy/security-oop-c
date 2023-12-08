
#include "Rectangle.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void *new_Rectangle(char *string) {
	// Allocate for this Int struct
	Rectangle *rectangle_obj = malloc(sizeof(Rectangle));
	if (rectangle_obj == NULL) {
		fprintf(stderr, "Error: Couldn't create Rectangle struct\n");
		return NULL;
	}

	// Allocate for contained GenericTraits struct
    rectangle_obj->impl = malloc(sizeof(GenericTraits));
    if (rectangle_obj->impl == NULL) {
        fprintf(stderr, "Error: Couldn't create GenericTraits struct\n");
        free(rectangle_obj);
        return NULL;
    }

    // Initialize the GenericTraits struct with Int's functions
    rectangle_obj->impl->new = new_Rectangle;
    rectangle_obj->impl->dump = dump_Rectangle;
    rectangle_obj->impl->cmp = cmp_Rectangle;
    rectangle_obj->impl->drop = drop_Rectangle;

	// Initialize actual rectangle
	char string_cpy[255];
	strcpy(string_cpy, string);
	char *token;
	token = strtok(string_cpy, " ");
	rectangle_obj->height = (int64_t)atoi(token);
	token = strtok(NULL, " \n");
	rectangle_obj->width = (int64_t)atoi(token);
	
	return rectangle_obj;
}

void dump_Rectangle(void *self, FILE *fp) { // TODO Proper name dump
	Rectangle *this = (Rectangle *)self;
	fprintf(fp, "%ld %ld\n", this->height, this->width);
}

int cmp_Rectangle(void *self, void *other) { // TODO Proper comparison
	Rectangle *rectangle_self = (Rectangle *)self;
	Rectangle *rectangle_other = (Rectangle *)other;
	int result;

	if ((rectangle_self->height * rectangle_self->width) < (rectangle_other->height * rectangle_other->width)) {
		result = -1;
	} else if ((rectangle_self->height * rectangle_self->width) > (rectangle_other->height * rectangle_other->width)) {
		result = 1;
	} else {
		if (rectangle_self->height < rectangle_other->height) {
			result = -1;
		} else if (rectangle_self->height > rectangle_other->height) {
			result = 1;
		} else {
			if (rectangle_self->width < rectangle_other->width) {
				result = -1;
			} else if (rectangle_self->width > rectangle_other->width) {
				result = 1;
			} else {
				result = 0;
			}
		}
	}

	return result;
}



DEFINE_STRUCT(Rectangle)