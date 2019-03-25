//Display from memory//
//Mohit Rane//
//gcc, linux terminal//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *base_addr, allo_flag, *memptr;
unsigned int total_mem, offset;

int takeinput(void);

int display() 
{
	int locations;

	if(allo_flag == 1)			//verifying if memory was allocated before invoke of display
	{	
		printf("Specify the offset: ");			//memory location to start display from

		offset = takeinput();

		memptr = base_addr + offset;

		printf("Specify the number of data locations: ");	//how many memory location to display from
		locations = takeinput();

		while(locations==0)
		{
			printf("Start from 1.\n 0 is an invalid input\n");
			locations = takeinput();
		}
		
		if(offset >= total_mem) printf("You are writing outside allocated space. Try again.\n");

		if(total_mem<(offset + locations))			//verifying if the location is within user access
		{	
			printf("You are reading outside allocated memory space\n");	
		}
		
		else if(locations==0)
		{
			printf("Start from 1.\n 0 is an invalid input\n");
		}
		
		else
		{
			for(int i=locations; i>0; i--)			//loop for writing into the memory loaction
			{
				printf("Adress: %p --- Value: %x\n", memptr, *memptr);		
				memptr += 1;
			}
		}
	}

	else printf("Please allocate memory before you write to memory.\n");

	return 0;
}
