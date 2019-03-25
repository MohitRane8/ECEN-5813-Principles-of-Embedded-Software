//help.c//
//Mohit Rane and Suman Hosmane//

#include<stdio.h>

int help()
{
	printf("You are in the help section.\n");
	printf("The available functions are:\n");
	printf("\t*To go to help section* --------- <help>\n");
	printf("\t*To allocate memory* ------------ <allo>\n");
	printf("\t*To free memory* ---------------- <free>\n"); 
	printf("\t*To write to memory* ------------ <write>\n");
	printf("\t*To display from memory* -------- <display>\n");
	printf("\t*To invert from memory* --------- <invert>\n"); 
	printf("\t*To generate random numbers* ---- <random>\n");
	printf("\t*To verify pattern* ------------- <verify>\n");
 	printf("\t*To exit program* --------------- <exit>\n\n");
	printf("Remember to allocate memory before using any function!");
	return 0;
}
