// C program to demonstrate insert operation in binary search tree. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

#include "data_2.h"
#include "utils_2.h"
#include "bst_2.h"

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
	char *radii=NULL;


	FILE *f= my_fopen(argv[1], "r");
	data_get_header(f);

	int k = 0;

	tree_t *root = NULL;
	

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
	
    
	//Reading in input to get the keys and radius to be searched
	while ((x_coord=getfield(stdin, S)) && (y_coord=getfield(stdin, S)) && (radii=getfield(stdin, NL))) {
	
		double x_key = changeStringToDouble(x_coord);
		double y_key = changeStringToDouble(y_coord);
		double radius = changeStringToDouble(radii);

		int search = 0;
		int match = 0;
		int count = 0;
		FILE* fp;
    	fp = fopen(argv[2], "w");
		search = searchTreeRadius(root, &x_key, &y_key, depth,radius, &match, fp, &count);
		printf("%s %s --> %d\n", x_coord,y_coord, count);
		
		if(match==0){
			fprintf(fp,"%s %s --> NOT FOUND\n",x_coord,y_coord);
		}
		
		fclose(fp);
    }

	
	
	return 0; 
} 

