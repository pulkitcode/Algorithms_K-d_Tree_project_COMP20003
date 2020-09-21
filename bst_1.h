
#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

#include "utils_1.h"
#include "data_1.h"
//#include "llist.h"


typedef struct tree tree_t;
typedef struct node node_t;


struct node {
    
    char *year, *bid, *pid, *bpid;  // 0-3
	char *clue, *name;              // 4, 5
	char *code;                     // 6
	char *desc;                     // 7
	char *x, *y;                    // 8,9
	char *loc;
    node_t *foot;
	
};

struct tree {
    double key_x;
    double key_y;
    tree_t *right;
    tree_t *left;
    node_t *list;
    
};

void print_data(node_t *d, FILE *f, double x_key, double y_key);
node_t* insertLinkedlist(node_t* abc, node_t* list);
tree_t* insert(tree_t* node, double key_x, double key_y, node_t*abc, unsigned depth2);
tree_t *makeNode(double x_coordinate, double y_coordinate, node_t* abc);
double distancePoints(double x1, double y1, double x2, double y2);
tree_t* searchTree(tree_t *root, double *x_double,double *y_double, unsigned depth,tree_t *closestNode, double *prevDist, int*count);

#endif