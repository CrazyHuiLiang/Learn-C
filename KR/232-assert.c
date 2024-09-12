
#define NDEBUG // 设置 NDEBUG 后，assert 会被忽略
#include <assert.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    assert(2>1);
    assert(1>2); // Assertion failed: 1>2, file KR/232-assert.c, line 5
    system("pause");
    return 0;
}

