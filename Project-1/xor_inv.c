#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int allo_flag, *memptr;
int *base_addr;
unsigned int total_mem, offset;

int takeinput(void);
// A function that inverts all the bits using xor
int xor_inv()
{
	unsigned value[100], count;	//Value array stores the original value stored by user. Count stores number of memory locations in question
	char decision_input[4];		//decision_input is used for decision between inverting already stored values or new input values
	double time_taken;		//time_taken stores the time taken for xor operation

	//Shows error if user tries to access this function before allocating memory	
	if(allo_flag == 0)
	{
		printf("Please allocate memory before you invert.\n");
	}

	//If user allocated memory, then the code moves forward	
	else
	{
		printf("Enter the offset: ");
		offset = takeinput();

		//Shows error if offset value exceeds total memory allocated		
		if(offset > (total_mem - 1))
		{
			printf("You are reading outside allocated memory space! Try again.\n");
		}

		//If offset is within limits, code moves forward
		else
		{
			memptr = base_addr + offset;	//Memory pointer pointing to the starting address

			printf("Enter number of memory locations whose values are to be inverted starting from offset: ");
			count = takeinput();
			
			if(count == 0)
			{
				printf("Start from 1.\n0 is an invalid input.\n");
				return 0;
			}

			if(total_mem>=(offset + count))
			{
				while(1)	//Infinite loop used to make the user enter valid input
				{					
					printf("Type \"Yes\" for inverting already present values, or \"No\" for adding a new value to invert: ");
					scanf("%s", decision_input);

				
					if((strcmp(decision_input, "Yes") == 0) || (strcmp(decision_input, "y") == 0) || (strcmp(decision_input, "Y") == 0) || (strcmp(decision_input, "yes") == 0))
					{
						//Starts measuring time
						clock_t t;
						t = clock();

						//Original values stored in value array while memptr points towards inverted value
						for(int i=0; i<count; i++)
						{
							value[i] = *memptr;
							*memptr ^= 0xffffffff;
							printf("Address of result[%d]: %p --- ", i+1, memptr);
							printf("Original value: %x ----- Inverted value: %x\n", value[i], *memptr);

							memptr += 1;
						}

						//Stops measuring time				
						t = clock() - t;
						time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

						//Prints the time taken for execution
						printf("It took %f seconds to execute \n", time_taken);

						break;
					}

					else if((strcmp(decision_input, "No") == 0) || (strcmp(decision_input,"N") == 0) || (strcmp(decision_input,"no") == 0) || (strcmp(decision_input,"n") == 0)) 
					{
						printf("Enter the values\n");	//User manually inputs values for inversion

						//Scans values for inversion in a loop. Original values stored in value array.
						for(int i=0; i<count; i++)
						{
							printf("Value %d: ", i+1);
							scanf("%x", &value[i]);
							*memptr = value[i];
							memptr += 1;
						}

						memptr = base_addr + offset;	//memptr pointing to the original address

						//Starts measuring time
						clock_t t;
						t = clock();

						//Data pointed by memptr inverted and output displayed						
						for(int i=0; i<count; i++)
						{
							*memptr ^= 0xffffffff;
							printf("Address of result[%d]: %p --- ", i+1, memptr);
							printf("Original value: %x ----- Inverted value: %x\n", value[i], *memptr);

							memptr += 1;
						}

						//Stops measuring time
						t = clock() - t;
						time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

						//Prints the time taken for execution
						printf("It took %f seconds to execute \n", time_taken);

						break;
					}

					else
					{
						printf("Invalid input, please try again.\n");
					}
				}
			}

			//Shows error
			else printf("Offset + locations exceeding total allocated memory! Try again.\n");
		}
	}

	return 0;
}
