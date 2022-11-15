#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int ac, char **argv)
{
	
	/*the user prompt*/
	char *prompt = "Myshell>#$";
	
	/*to read what the user typed in we need to be able to  to store the address of the buffer holding whatever was typed and store the alocated size in bytes */
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;
	
	/*void variables*/
	(void)ac; (void)argv;
	
	/*make an infinite loop*/
	while (1){

	printf("%s", prompt);
	/*the getline function alocate memory and need to be freed afterwards*/
	nchars_read = getline(&lineptr, &n, stdin);

	/*to check if the getline function failed or reached the EOF or if a  user use CTR + D */
	if (nchars_read == -1){
		printf("shell is Exiting...\n");
		return (-1);
		}
	/*To print what the user typed in*/
	printf("%s\n", lineptr);

	free(lineptr);
	}
	
	return (0);

}
