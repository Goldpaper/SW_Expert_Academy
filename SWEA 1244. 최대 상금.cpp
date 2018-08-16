/*****************************
 DFS를 활용
******************************/

#include <iostream>

using namespace std;


void change() {
	
}

int main() {
	int testCase;	//테스트 케이스
	int number;		//숫자판의 정보
	int numBoard[6];	//숫자판
	int changeNum;		//교환 횟수

	cin >> testCase;
	
	while (testCase--) {
		memset(numBoard, -1, sizeof(numBoard));
		cin >> number >> changeNum;

		int i=6;
		while (number) {
			i--;
			numBoard[i] = number % 10;
			number /= 10;
			change()
		}
	}
}