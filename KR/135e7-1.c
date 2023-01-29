//
// Created by Crazyhuiliang on 2019-03-28.
//

#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
    printf("begin \n");

    for (int i = 0; i < argc; i++) {

        const char *arg = argv[i];
        int j = 0;
        char c;
        while ((c = arg[j++]) != '\0') {
            printf("%c", toupper(c));
        }
        putchar('\n');
        j = 0;
        while ((c = arg[j++]) != '\0') {
            printf("%c", tolower(c));
        }
    }

    printf("\nend\n");
    return 0;
}
