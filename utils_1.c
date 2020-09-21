#include "utils_1.h"

//a function used to malloc space 
void *my_malloc(size_t n){
	assert(n>0);
	void *p= malloc(n);
	assert(p);
	return p;
} 
//a function used to open a file

FILE *my_fopen(const char *fname, const char *mode) {
	FILE *f= fopen(fname, mode);
	assert(f);
	return f;
}

//return a pointer to the string
char *my_strdup(char *s) {
	char *t= strdup(s);
	assert(t);
	return t;
}
