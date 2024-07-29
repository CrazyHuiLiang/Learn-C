#include "template.h"

int main(int argc, char *argv[]) {
    printf("------------------------------------------------------------\n");
    int code = my_main(argc, argv);
    printf("------------------------------------------------------------\n");
    print_my_process_time();
    printf(">");
    // printf("____________________________________________________________\n");
    return code;
}
