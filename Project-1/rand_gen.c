//Generates a maximum of 5 random numbers based on a seed value//
//Suman Hosmane and Mohit Rane//



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *base_addr, allo_flag, *memptr;
int rand_num[5];
unsigned int total_mem, offset;

int takeinput(void);

int rand_gen(int a) 
{			
	int inputs, seed,num[5];

	if(allo_flag == 0)
	{
		printf("Please allocate memory before can generate random numbers.\n");		//verifying if memory is allocated before number generation
	}
	
	else
	{
		printf("Enter the offset for random values: ");		//specify start address for random numbers
		offset = takeinput();	
			
		printf("Enter the no. of random values required (maximum is 5): ");
		inputs = takeinput();

		while(inputs == 0)
		{
			printf("Invalid input\n");
			inputs = takeinput();
		}
				
		if((inputs <= 5) && ((offset+inputs)<=total_mem))	//generation of random values without rand()
		{
			printf("Enter a seed value: ");
			seed = takeinput();
			
			clock_t t;
			t= clock();
			num[0]=((((seed*9)/2)+7)*2)%17;
			num[1]=(((seed/2)*10)%11);
			num[2]=(((876*seed)/4)%12)+3;
			num[3]=(((seed+4)*6)-5)%13;
			num[4]=((seed+4)*7677)%18;

			memptr = base_addr + offset;

			for(int i=0; i<inputs; i++)
			{		
				*memptr = num[i];			//writing random values into memory location
				rand_num[i] = *memptr;
				printf("Random number %d: %d --- Address: %p\n", i+1, *memptr, memptr);
				memptr += 1;
			}

			t = clock() - t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
			
			//Prints the time taken for execution
			printf("It took %f seconds to execute \n", time_taken);
			
		}

		else
		{
			printf("Either offset or input exceeds the limit. Try again.\n");
		}
	}	
return 0;
}
