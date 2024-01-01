/*
1832. 判断句子是否为全字母句 https://leetcode.cn/problems/check-if-the-sentence-is-pangram/
全字母句 指包含英语字母表中每个字母至少一次的句子。
*/
#include <stdio.h>
#include <stdbool.h>


bool checkIfPangram(char * sentence){
	int map = 0b11111111111111111111111111;
	while (*sentence != '\0') {
		map = map & ~(1 << (*sentence - 'a'));
		if (!map) {
			return true;
		}
		// printf("%c-%d-%d\n", c, pos, mask);
		sentence++;
	}
	return false;
}


int main(int argc, char *argv[]) {
	char *sentence = "abcdefghijklmnopqrstuvwxyz";
	bool result = checkIfPangram(sentence);
	printf("result is %d", result);
}