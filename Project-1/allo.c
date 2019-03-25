//allocate//
//Suman Hosmane and Mohit Rane//
//gcc, linux terminal//
//https://www.programiz.com/c-programming/c-dynamic-memory-allocation//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

int allo_flag, *base_addr;
unsigned int total_mem, offset;

int takeinput(void);

int allo()
{       
	int locations;
	if(allo_flag == 1)
	{
		printf("You are allocating memory again.\nKindly free memory before allocating a different block.\n");
	}

	else
	{		
		printf("You are allocating memory. Enter number of locations\n");
		locations = takeinput();
		offset = locations - 1;
		
		if (locations == 0)
		{	
			printf("No memory allocated\n");			//error message for null input
		}	

		else
		{
			base_addr = (int*) malloc(locations * sizeof(int));	//allocating memory starting from a base location	
	
			if(base_addr == NULL)
			{
				printf("Error! memory not allocated.\n");		//error message for invalid or out of range input
				return(0);
			}	

			else
			{
				allo_flag = 1;					//flag for tracking memory allocation			
				total_mem = locations;

				printf("%u memory locations allocated\n", locations);
				printf("Allocation address: %p\n", base_addr);
			}
		}
	}	
return 0;
}
