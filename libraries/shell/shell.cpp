#include "shell.h"

int numberOfArgs(char[] command) //all commands shall have exactly 1 space between arguments!!
{
	if (command == NULL || command[0] == '\0') //no arguments
		return 0;
	int number = 1; //at least one argument
	for(int i = 0; i < MAX_COMMAND_LENGTH && command[i] != '\0'; i++) 
	{
		if (command[i] == ' ')
			number++;
	}
	return number;
}

char* getArg(char* command, int argNum)
{
	for (int i = 0; i < MAX_COMMAND_LENGTH && command[i] != '\0'; i++) //replace all arg separators with null terminators
	{
		if (command[i] == ' ')
			command[i] = '\0';
	}
	if (command == NULL || command[0] == '\0') //if the argument number was empty or just a null terminator
		return NULL;
	if (numberOfArgs(command) <= argNum) //if the argument number was greater than (or equal to) the number of arguments
		return NULL;
	if (argNum == 1) //if the argument number was trivial (1)
		return command;
	int number = 0;
	for (int i = 0; i < MAX_COMMAND_LENGTH && command[i] != '\0'; i++)
	{
		if (command[i] == ' ') //if there is an argument separator, there must be another argument
		{
			number++;
		}
		if (number == argNum) //if the current argument matches the desired argument
			return command + i + 1; //return the pointer of the desired argument
	}
}