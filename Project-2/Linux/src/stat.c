/* --------------------------------------------
 * File: Current program statistics
 * Authors: Mohit & Suman
 *
 * Gives information on the current states of circular buffers,
 * head and tail pointers, number of characters, etc
 *--------------------------------------------
*/

#include "stat.h"

int stat(char param[30])
{
	if(buff_count == 0)
	{
		printf("No stats to display.\n");
		return EXIT_FAILURE;
	}

	printf("\n");
	printf("Current Stats\n-------------\n\n");
	printf("Number of Circular Buffers:\t%d\n\n", buff_count);
	printf("Buffer # \t Buffer Size \t No. of Char in Buffer \t Buffer Start Add \t Buffer End Add\n");
	printf("-------- \t ----------- \t --------------------- \t ---------------- \t --------------\n");
	for(int i=0;i<buff_count;i++)
	{
		printf("   %d     \t      %d      \t           %d           \t  %p  \t %p\n", i+1, buff_size[i], buff_char_count[i], base_addr[i], (base_addr[i] + buff_size[i]));
	}

	/*---------Showing actual buffers----------*/
	for(int i=0;i<buff_count;i++)
	{
		printf("\nCircular Buffer %d contents\n", i+1);

		//points head
		printf("\t ");
		for(int j=0; j<head[i]-base_addr[i]; j++)
			printf("    ");
		printf(" H\n");

		printf("\t ");
		for(int j=0; j<head[i]-base_addr[i]; j++)
			printf("    ");
		printf(" |\n");

		//shows actually buffer
		printf("\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n\t|");
		for(int j=0; j<buff_size[i]; j++)
		{
			if(*(base_addr[i]+j) == '\0')
				printf("   |");
			else
				printf(" %c |", *(base_addr[i]+j));
		}
		printf("\n\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n");

		//points tail
		printf("\t ");
		for(int j=0; j<tail[i]-base_addr[i]; j++)
			printf("    ");
		printf(" |\n");

		printf("\t ");
		for(int j=0; j<tail[i]-base_addr[i]; j++)
			printf("    ");
		printf(" T\n");
	}

	/*---------PART 5----------*/
	//a flag to check if unique character already exist in buffer
	int8_t uniq_flag;

	for(int i=0;i<buff_count;i++)
	{
		 app_char_addr[i] = (int*) malloc(256 * sizeof(int));		//keep track of characters in the buffer
		 app_cnt_addr[i] = (int*) malloc(256 * sizeof(int));    //keep track of character count in the buffer
	}

	for(int i=0;i<buff_count;i++)
	{
		for(int j=0;j<buff_size[i];j++)
		{
			if(*(base_addr[i]+j) == '\0')
				continue;

			else
			{
				for(int k=0;k<256;k++)
				{
					uniq_flag = 1;
					//increase count of unique char which already occured earlier
					if(*(base_addr[i] + j) == *(app_char_addr[i] + k))
					{
						*(app_cnt_addr[i] + k) = *(app_cnt_addr[i] + k) + 1;
						uniq_flag = 0;
						break;
					}
				}

				if(uniq_flag == 1)
				{
					*(app_char_addr[i] + no_of_uniq_char[i]) = *(base_addr[i] + j);
					*(app_cnt_addr[i] + no_of_uniq_char[i]) = 1;
					no_of_uniq_char[i] = no_of_uniq_char[i] + 1;
				}
			}
		}
	}

	for(int i=0;i<buff_count;i++)
	{
		printf("\nBuffer_%d\n",i+1);
		printf("CHARACTER\tCOUNT\n---------\t-----\n");

		for(int j=0;j<no_of_uniq_char[i];j++)
		{
			printf("    ");   			
			putchar(*(app_char_addr[i] + j));
			printf("    ");
			printf("\t  %d   \n",*(app_cnt_addr[i] + j));
				//printf("    %c    \t  %d  \n",*(app_char_addr[i] + j), *(app_cnt_addr[i] + j));
		}
	}

	int32_t* rem_ptr;
	rem_ptr = (int*) malloc(sizeof(int));
	for(int i=0;i<buff_count;i++)
	{
		app_char_addr[i] = rem_ptr;
		app_cnt_addr[i] = rem_ptr;
		no_of_uniq_char[i] = 0;
	}

	return EXIT_SUCCESS;
}
