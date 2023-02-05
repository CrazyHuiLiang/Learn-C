#include <stdio.h>

int test_goto(int test_case) {
	switch (test_case) {
		case 1: {
			goto label1;
		} break;
		
		case 2: {
			goto label2;
		} break;
		default: {
			return 0;
		}break;
	}
	return 0;
	
	label1: return 1;
	label2: return 2;
}

int main(int argc, char *argv[]) {
	printf("testcase1 = %d\n", test_goto(1));
	printf("testcase2 = %d\n", test_goto(2));
	printf("testcase3 = %d\n", test_goto(3));
}