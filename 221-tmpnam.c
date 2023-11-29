#include <stdio.h>

int main(){
    printf("L_tmpnam=%d, TMP_MAX=%d\n", L_tmpnam, TMP_MAX);

    // tmpnam() 已经被废弃，被 stdlib 中的mkstemp取代
    char buffer[L_tmpnam];
    printf("%s %s\n", tmpnam(buffer), buffer); 
    printf("%s\n", tmpnam(NULL));
	return 0;
}
