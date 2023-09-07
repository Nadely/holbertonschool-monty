# <p style="text-align: center;"><span style="color:blue">*Monty*</span></p>

### TABLE OF CONTENTS
- [DESCRIPTION](#description)
- [REQUIREMENTS](#requirements)
- [COMPILATION CMD](#compilation-cmd)
- [RETURN VALUE](#return-value)
- [INSTALLATION](#installation)
- [CHECK MEMORY LEAKS](#check-memory-leaks)
- [AUTHORS](#authors)


### DESCRIPTION

	Monty is a language interpreter used to manipulate data stacks and queues.

	Fuction use in monty :
		push : for push stack
		pall : print all stack
		pint : print previous elemnet
		pop : out stack
		add : function for adding two stacks
		div : function for divide two stacks
		mul : function for multiply two stacks
		sub : function for subtract two stacks
		mod : function for modulo two stacks
		nop : to ignore an instruction
		swap : exchange two stack values
		pchar : print a char with the previous node
		pstr : print a string


### REQUIREMENTS
(compiler, list of authorized functions)

_Compiler_ : GNU

_List of authorized functions :_ The C standard library

### COMPILATION CMD
	gcc -Wall -Werror -Wextra -pedantic *.c -o monty

### RETURN VALUE

	$ : ./monty bytecodes/00.m
	Result of function.

	Example :
				In file 00.m :
				push 1
				push 2
				push 3
				add
				pall

				Output :
				5
				1

### INSTALLATION

	For clone repository : git clone git@github.com:Nadely/holbertonschool-monty.git

### CHECK MEMORY LEAKS

	valgrind ./monty bytecodes/00.m

### AUTHORS

Kevin Pellissard, Nadège Tettelin.

