# Project 1 - Interactive Memory Manipulation Utility

Contributors: Mohit Rane and Suman Hosmane

Description:

This program allows the user to manipulate heap and perform various operations.

We have various functionalities incorporated in the project, listed below:

<pre>
> help
</pre>

Invokes the help function which tells the user as to how to use the different functions (just like the general Linux help command) and gives the syntax and purpose of the functions defined.

<pre>
> allo
</pre>

Allocates a block of memory as required by a user. Displays the base address from which the allocation starts from.

<pre>
> free
</pre>

Releases the block of allocated memory in the allocate function.

<pre>
> write
</pre>

Asks for an offset from user and feeds the data provided into the particular offset

<pre>
> display
</pre>

Reads back data in that particular memory location.

<pre>
> random
</pre>

Generates upto 5 random numbers from a seed value provided by the user.
<pre>
> verify
</pre>

Verifies that the previous random pattern with the new set of values from user and if a match occurs, pattern is verified, else displays address of mismatch and values expected and calculated.

<pre>
> exit
</pre>

The entire program is in a loop and the exit command can be invoked to terminate the program.

While making the project we have taken into consideration some of the boundary conditions that could occur such as performing free or any other memory requiring operation without allocating memory.
Or an invalid user input which will show an invalid flag instead of breaking out of the program.

Basic testing is done via a **stdin** test file with all the functions to be tested along with the required parameters for each function. The compiler automatically feeds the parameters after each function invoked in the stdin file.
