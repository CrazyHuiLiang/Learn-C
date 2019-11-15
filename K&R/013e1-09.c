#include <stdio.h>


int main(int argc, char *argv[]) {
	
	printf("please input something:\n");
	int c;
	int black = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			black = 1;
			continue;
		}
		if (black) {
			putchar(' ');
		}
		black = 0;
		putchar(c);
	}
	
	printf("done");
	return 0;
}