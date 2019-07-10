#include <stdio.h>

unsigned long int next = 1;

/* rand 函数：返回值在0～32767 之间的伪随机数  */
int rand(void) {
  next = next * 1103515247 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

/* srand 函数：为rand()函数设置种子数 */
void srand(unsigned int seed) {
  next = seed;
}

int main(){

  srand(100);


	printf("%d %d %d\n", rand(), rand(), rand());
	return 0;
}
