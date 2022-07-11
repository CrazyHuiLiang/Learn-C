#include <stdio.h>

int main(int argc, char *argv[]) {
	struct key {
		char *word;
		int count;
	} keytab[10];
	
	struct key keytab2[5];
	
	struct key2 {
		char *word;
		int count;
	} keytab3[] = {
		"static", 0
	};
	
	struct key2 keytab4[] = {
		{"static", 0}
	};
	
}