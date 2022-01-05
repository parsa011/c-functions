#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void print_help();

int main(int argc,char *argv[])
{
	if (argc == 1) {
		print_help();
		return 1;
	}
	FILE *fp;
	fp = fopen(argv[1],"r");
	if (!fp) {
    	printf("file not found\n");
	}
	bool in_newline= false,startof_line,print;
	int c;
	while ((c = fgetc(fp)) != -1) {
		if (!in_newline) {
    		do {
				if (c == '\n')
    				break;
    		} while (c = fgetc(fp));
    		in_newline = true;
    		startof_line = true;
    		print = false;
    		continue;
		}
		if (startof_line) {
			print = isalpha(c);
			startof_line = false;
		}
		if (print)
    		putchar(c);
		if (c == '\n') {
    		in_newline = print = startof_line = false;
		}
	}
	fclose(fp);
	return 1;
}

void print_help()
{
	printf("c-functions help :\n");
	printf(" c-functions filename\n");
}
