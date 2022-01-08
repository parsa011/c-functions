#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "prosing.h"

#define AR_LENGTH(a) (sizeof(a) / sizeof(a[0]))

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
    	return 0;
	}
	int c;
	ssize_t read;
	string *str = malloc(sizeof(string));
	while ((read = getline(&str->value, &str->len, fp)) != -1) {
		puts(str->value);
	}
	fclose(fp);
	return 1;
}

void print_help()
{
	printf("c-functions help :\n");
	printf("\t=> c-functions filename\n");
}
