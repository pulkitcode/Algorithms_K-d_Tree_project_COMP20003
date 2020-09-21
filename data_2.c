#include "data_2.h"
#include <ctype.h>

//------ CREDITS : AVO SAMPLE SOLUTION  -----------------

#define NUM_FIELDS 11  // number of fields, assigned for simplicity
static char *firstRow[NUM_FIELDS];

//get the First line of the file
void data_get_header(FILE *f) {

	int i = 0;

	for (i=0; i<NUM_FIELDS-1; i++) {
		firstRow[i]= getfield(f,C);
	}
	
	firstRow[i]= getfield(f,NL);
}

///PREPROCESSING

// chop the last char of s if it is delim	
void chop(char *s, char delim) {
	
	int length = strlen(s)- 1;

	// first: shop \n or \r (Windows problem!) 

	for (; length>=0 && isspace(s[length]) ; length--) {
		s[length]= '\0';
	}

	if (s[length]==delim)  s[length]= '\0';
}

// copying s top t, reducing "" to "
//     return 0 if s contains final "
//            1 otherwise (ie. s not yet finished)
int scopy(char *t, char *s, char deli) {
	char *str= t;
	char *str2= s;
	
	char prev=' ';

	while (*str2) {
		//If character '/' comes and no '/' before or ahead
		if (*str2==Q && prev!=Q && (*(str2+1)!=Q) ) {
			*str= '\0'; 
			return 0;
		}
		if (*str2==Q && prev==Q) {
			prev= ' ';
			str2++;
			continue;
		}
		prev= *str2;
		*str++= *str2++;
	}
	*str= '\0';
    return 1;
}

// get & return next csv field, which might or might not start with "
//    the field deds withj "deli", which can be  a comma or a newline
char *getfield(FILE *f, char deli) {
	char *str=NULL;

	size_t size= 0;

	// get first component
    if (getdelim(&str, &size, deli, f) <=0 ) {
		if (str) free(str);
		return NULL;
	}  
	if (*str != Q) {  // simple return for field not starting with "
		chop(str, deli);
		return str;
	}

	char line[FIELD_LEN+3]; // buffer, +3 for possible \r \n \0
	int cont= scopy(line, str+1, deli);  // add first component to buffer

	while (cont) {
		char *p= line+strlen(line);
		getdelim(&str, &size, deli, f);
		cont= scopy(p, str, deli);
	}
    free(str);
	return my_strdup(line);
}	

//get a line from input data file as a data node
node_t *get_next_data(FILE *f) {
	char *s= getfield(f,C);
	if (!s) return NULL;

	node_t *d= my_malloc(sizeof(*d));
    d->year= s;
	d->bid= getfield(f,C);
	d->pid= getfield(f,C); 
	d->bpid= getfield(f,C);
	d->clue= getfield(f,C);
	d->name= getfield(f,C);
	d->code= getfield(f,C);
	d->desc= getfield(f,C);
	d->x= getfield(f,C);
	d->y= getfield(f,C);
	// To localize reading errors, read until \n here
	d->loc= getfield(f,NL);
	return d;
}

//free the data alloted
void free_data(node_t *d) {
	free(d->year); free(d->bid); free(d->pid); free(d->bpid);
    free(d->clue);
	free(d->name);
	free(d->code); 
	free(d->desc);
	free(d->x); free(d->y);
 	free(d->loc);
	free(d);
}

//Used to change a string to a double
double changeStringToDouble(char* data){
    	char *ptr1;
		double x_double;
   		x_double = strtod(data, &ptr1);
   		
		return x_double;
}
