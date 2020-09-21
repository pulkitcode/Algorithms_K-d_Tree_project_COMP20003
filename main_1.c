// C program to demonstrate insert operation in kd tree. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

#include "data_1.h"
#include "utils_1.h"
#include "bst_1.h"

/** Authorization: Pulkit Aggarwal 1018581 
 * A Program to find the closest point to a key using a k-d tree
 * 
 */

//------ CREDITS : AVO SAMPLE SOLUTION  -----------------//

int main(int argc, char *argv[]) 
{ 

	node_t *data;
	char *x_coord=NULL;
	char *y_coord=NULL;

	FILE *f= my_fopen(argv[1], "r");
	data_get_header(f);

	int k = 0;

	tree_t *root = NULL;
	tree_t *search = NULL;
	tree_t *closeNode = root;

	//Insertion starts here
	while ( (data=get_next_data(f)) ) {
        
    	unsigned depth = 0;
       
		//changing string of coordinates to double
   		double x_double = changeStringToDouble(data->x);
   		double y_double = changeStringToDouble(data->y);

        if(k==0) {
        	root = insert(root, x_double, y_double, data,depth);
        	k++; 
    	}
		else {
			insert(root, x_double, y_double, data,depth);
		}
	}	

	fclose(f);
	unsigned depth = 0;
    
	//Reading in input to get the keys to be searched
	while ((x_coord=getfield(stdin, S)) && (y_coord=getfield(stdin, NL))) {
	
		double x_key = changeStringToDouble(x_coord);
		double y_key = changeStringToDouble(y_coord);
		double distance = distancePoints(root->key_x, root->key_y, x_key, y_key);
		int count = 0;
		search = searchTree(root, &x_key, &y_key, depth, closeNode, &distance,&count);
		printf("%s %s -- > %d\n",x_coord,y_coord,count);

		FILE* fp;
		fp = fopen(argv[2], "w");

		//Writing output to the file and looping through the linked lists to print all
		if(search!=NULL){
			
			while(search->list->foot!=NULL){
				
				print_data(search->list,fp,x_key,y_key);
				free_data(search->list);
				search->list = search->list->foot;
			}	
		}

		fclose(fp);
		
	}
	return 0; 
} 