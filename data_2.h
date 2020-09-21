#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <string.h>

#include "utils_2.h"
#include "bst_2.h"




#define C ','     
#define Q '\"'   
#define NL '\n'
#define S ' '  
 
#define FIELD_LEN 128

node_t *get_next_data(FILE *f);       // return a next record read from f
double changeStringToDouble(char* data);
void data_get_header(FILE *f);       // get rid off & and store header for late use
void data_free_header();  
void free_data(node_t *d);

char *getfield(FILE *f, char deli);  // get a next field from file f
#endif
