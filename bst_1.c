
#include "data_1.h"
#include "utils_1.h"
#include "bst_1.h"
#define NUM_FIELDS 11 

//function to insert a linked list to a tree node
node_t* insertLinkedlist(node_t* node, node_t* foot){


	node_t* new = (node_t *)malloc(sizeof(node_t));
	assert(new!=NULL);
	new->year = node->year;
	new->bid = node->bid;
	new->pid = node->pid;
	new->bpid = node->bpid;
	new->year = node->year;
	new->clue = node->clue;
	new->name = node->name;
	new->code = node->code;
	new->desc = node->desc;
	new->x = node->x;
	new->y = node->y;
	new->loc = node->loc;

	new->foot = foot;
	
	return new;
	 
}

// A  function to create a new K-D node 
tree_t *makeNode(double x_coordinate, double y_coordinate, node_t* node) { 
	
	tree_t *temp = (tree_t *)malloc(sizeof(tree_t)); 

	temp->key_x = x_coordinate; 
	temp->key_y = y_coordinate;
	temp->left = temp->right = NULL; 
	temp->list = insertLinkedlist(node, node);

	return temp; 
} 

//Getting the euclidean distance between two points
double distancePoints(double x1, double y1, double x2, double y2) {
   double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
   return distance;
}

// A utility function to do traversal of K-D tree and search the coordinate closest to the key 
tree_t* searchTree(tree_t *root, double *x_double,double *y_double, unsigned depth,tree_t *closestNode, double *prevDist, int* count) {

	
	(*count)++;

	//printf("%d\n",count);
	if(root==NULL) {
		//count++;
			
		return closestNode;
	}

	double currDist = distancePoints(root->key_x, root->key_y, *(x_double), *(y_double));
	
	if(currDist==0) {
		//count++;
		return root;
   	}

	double x = fabs(root->key_x - *x_double);
	double y = fabs(root->key_y - *y_double);

	if(currDist <= *prevDist) {
        //count++;
		*prevDist = currDist;
		closestNode = root;
		//count = count+1;
		
	}
	
	
    if(depth%2==0) {
		//count = count+1;
        if(x <= *prevDist) {
			
            closestNode =  searchTree(root->left, x_double, y_double, depth+1, closestNode, prevDist,count);
            closestNode =  searchTree(root->right, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
        else if(*x_double<root->key_x) {
			
            closestNode =  searchTree(root->left, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
        else{
			
            closestNode =  searchTree(root->right, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
        
    }
    else if((depth%2)!=0) {
		
        if(y<=*prevDist) {
			
            closestNode =  searchTree(root->left, x_double, y_double, depth+1, closestNode, prevDist,count);
            closestNode =  searchTree(root->right, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
        else if(*y_double<root->key_y) {   
			  
            closestNode =  searchTree(root->left, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
        else{
			
            closestNode =  searchTree(root->right, x_double, y_double, depth+1, closestNode, prevDist,count);
        }
    }	
	return closestNode;
} 

/* A function to insert a new node with given key in the K-D Tree */
 tree_t* insert( tree_t* node, double key_x, double key_y, node_t* data, unsigned depth) 
{ 
	
	//first node
    if (node == NULL){
		return makeNode(key_x,key_y, data); 
	}
	
	//if next node is equal add to linked list
	else if(key_y==node->key_y && key_x==node->key_x){
		node->list = insertLinkedlist(data,node->list);
		return node;	
	}
	
	//else add to the tree according to the depth
	if(depth%2!=0){

	if ((key_y < node->key_y)) 
		node->left = insert(node->left, key_x,key_y, data,depth+1); 
	else if (key_y > node->key_y) 
		node->right = insert(node->right, key_x,key_y, data,depth+1);

	}

	else if(depth%2==0){

	if ((key_x < node->key_x)) 
		node->left = insert(node->left, key_x,key_y, data,depth+1); 
	else if (key_x > node->key_x) 
		node->right = insert(node->right, key_x,key_y, data,depth+1);

	}
	
	/* return the (unchanged) node pointer */
	return node; 
} 

//print the data function
void print_data(node_t *d, FILE *f, double x_key, double y_key) {
	int i;
	double x = changeStringToDouble(d->x);
	double y = changeStringToDouble(d->y);
	
	
	fprintf(f, "%f %f -- > ", x_key,y_key);
	for (i=0; i<NUM_FIELDS; i++) {
		
		switch (i) {
			case 0:
				fprintf(f,"Census Year: %s || ", d->year);
				break;
			case 1:
				fprintf(f,"Block ID: %s || ", d->bid);
				break;
			case 2:
				fprintf(f,"Property ID: %s || ", d->pid);
				break;
			case 3:
				fprintf(f,"Base property ID: %s || ", d->bpid);
				break;
			case 4:
				fprintf(f,"CLUE small area: %s || ", d->clue);
				break;
			case 5:
				fprintf(f,"Trading Name: %s || ", d->name);
				break;
			case 6:
				fprintf(f,"Industry (ANZSIC4) code: %s || ", d->code);
				break;
			case 7:
				fprintf(f,"Industry (ANZSIC4) description: %s || ", d->desc);
				break;
			case 8:
				fprintf(f,"x coordinate: %.4lf || ", x);
				break;
			case 9:
				fprintf(f,"y coordinate: %.4lf || ", y);
				break;
			case 10:
				fprintf(f,"Location: %s || \n", d->loc);
				break;
		}
	
	}

}
