//Free Allocated Memory//
//Suman Hosmane and Mohit Rane//
//gcc, linux terminal//
//https://www.programiz.com/c-programming/c-dynamic-memory-allocation//

#include<stdio.h>
#include<stdlib.h>

extern int allo_flag;
extern unsigned int total_mem;
extern int *base_addr;

int free_mem()
{
	if(allo_flag == 0)			//verifying if memory is allocated before freeing
	{
		printf("Please allocate memory before you free.\n");
	}

	else
	{	
		free(base_addr);		//freeing the base address from which memory allocation started
				
		printf("The previous allocated memory is freed.\n");
		printf("The %d locations from the starting address %p is freed.\n", total_mem, base_addr);
		allo_flag = 0;
	}
	return 0;
}


