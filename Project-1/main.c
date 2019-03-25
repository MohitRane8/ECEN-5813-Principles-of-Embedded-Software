#include <stdio.h>
#include "func.h"
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

//Declaring variable to store base address
extern uint *base_addr;	

//Declaring a variable to store total memory locations
extern uint total_mem;

//Declaring memory address variable
extern uint *memptr;

//Declaring offset to allow user to use functions at particular address
extern uint offset;

//Declaring exit flag which allows program to terminate
extern uint exit_flag;

//Declaring a flag to verify allocation status
extern uint allo_flag;


extern uint rand_num[5];
//Main.c

/*int takeinputhex(void)
{
      while(1)
      {
             int locations;
             char str[10];
             scanf("%s", str);
             if (str[strspn(str, "0123456789abcdefABCDEF")] == 0)
             {
                   locations = atoi(str);
                   return locations;
             }

	     else
             {
                   printf("Enter a valid decimal number.\n\n");
             }
       }
}*/

int takeinput()
{
        while(1)
        {      
	       int locations;
	       char str[10];
               scanf("%s", str);
               if (str[strspn(str, "0123456789")] == 0)
               {
                       locations = atoi(str);
                       return locations;                                                                                                                                               }

               else                                                                                                                                                                    {
                       printf("Enter a valid decimal number.\n\n");
               }
        }
}

int main()
{
	exit_flag = 0;

	allo_flag = 0;
	//Declaring a variable to know if user inputs correctly
	uint wrong_input_flag = 1;

	//Declaring function array pointers
	int (*func_arr[])(int) = {help, allo, free_mem, write, display, xor_inv, rand_gen, verify_pattern, exit_app, clear};

	//Defined a variable for user input
	char user_func_in[10];

	//Declaring strings to compare with user input and call correct function
	char *func_names[] = 
	{
		"help",
		"allo",
		"free",
		"write",
		"display",
		"invert",
		"random",
		"verify",
		"exit",
		"clear"
	};
	
	//finding the array size dynamically
	uint no_of_func = sizeof(func_names)/sizeof(func_names[0]);

	//Greetings
    	printf("Welcome User!\n\n");
	printf("Hello!");
	
	//Calling help function
    	func_arr[0](1);
	printf("\n\n");

	while(1)
	{
		//Scans user input
		printf(">");
		scanf("%s",user_func_in);

		for(uint i=0; i<no_of_func; i++)
		{
			if(strcmp(user_func_in, func_names[i]) == 0)
			{
				wrong_input_flag = 0;
				func_arr[i](1);
				break;
			}
		}

		if (exit_flag == 1)
		{
			printf("See You Later!\n\n");
			if(allo_flag == 1)
			{
			//Frees the memory for reuse before terminating	
				free(base_addr);
				break;
			}
			else
				break;
		}

		if (wrong_input_flag != 0)
		{
			printf("Invalid input. Please try again.\n");
		}

		printf("\n");

		wrong_input_flag = 1;

	}
return 0;
}
