#include "util.h"

clock_t print_my_process_time() {
    // 计算进程消耗的时钟滴答数
    // printf("\n\nCLOCKS_PER_SEC=%lu\n", CLOCKS_PER_SEC);
    // printf("_SC_CLK_TCK=%lu\n", sysconf(_SC_CLK_TCK));

    struct tms my_tms;
    clock_t t = times(&my_tms);
    printf("utime = %lu, stime = %lu; ", my_tms.tms_utime, my_tms.tms_stime);

    // 计算进程使用的总的 CPU 时间
    clock_t c = clock();
    printf("sec = %.2fs\n", (double)c/CLOCKS_PER_SEC);
    return c;
}

static clock_t start_c;

clock_t console_time_reset() {
    return start_c = clock();
}

clock_t console_time() {
    clock_t c = clock();
    clock_t take = c - start_c;
    printf("Start at %ld, End at %ld, Take %.3fms, %ld\n", start_c, c, (double)take/CLOCKS_PER_SEC*1000, take);
    start_c = c;
    return c;
}
