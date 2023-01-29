#include <stdio.h>

/* 当celsius= 0， 20 ... 300 时，分别
打印摄氏温度与华氏温度对照表 
浮点数版本*/
int main(){
	float celsius, fahr;
	int lower, upper, step;
	lower = 0; /*温度表的下限*/
	upper = 300;/*温度表的下限*/
	step  = 20;/*步长*/
	celsius = lower;
	while(celsius <= upper){
		fahr = celsius / (5.0 / 9.0) + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius += step;
//		celsius = (5.0 / 9.0) * (fahr - 32.0);
//		printf("%3.0f %6.1f\n", fahr, celsius);
//		fahr=fahr + step;
	}
	return 0;
}
