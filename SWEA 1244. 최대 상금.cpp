/*****************************
 DFS�� Ȱ��
******************************/

#include <iostream>

using namespace std;


void change() {
	
}

int main() {
	int testCase;	//�׽�Ʈ ���̽�
	int number;		//�������� ����
	int numBoard[6];	//������
	int changeNum;		//��ȯ Ƚ��

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