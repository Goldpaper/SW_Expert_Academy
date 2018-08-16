#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int map[120], password[10];
int code[10][7] = {
{ 0,0,0,1,1,0,1 },//0
{ 0,0,1,1,0,0,1 },//1
{ 0,0,1,0,0,1,1 },//2
{ 0,1,1,1,1,0,1 },//3
{ 0,1,0,0,0,1,1 },//4
{ 0,1,1,0,0,0,1 },//5
{ 0,1,0,1,1,1,1 },//6
{ 0,1,1,1,0,1,1 },//7
{ 0,1,1,0,1,1,1 },//8
{ 0,0,0,1,0,1,1 }//9
};

int len, start;
int back = 0;

int check() {
	int num = 7, point = 0, total = 0;
	point = back;
	for (int a = 7; a >= 0; a--) {
		for (int i = 0; i < 10; i++) {
			int count = 0;
			for (int j = 0; j < 7; j++) {
				if (code[i][6 - j] == map[point - j]) {
					count++;
				}
				if (count == 7) {
					point -= 7;
					password[num--] = i;
				}
			}
		}
	}

	total = 3 * (password[0] + password[2] + password[4] + password[6]) + password[1] + password[3] + password[5] + password[7];

	if (total % 10 == 0) {
		total = 0;
		for (int i = 0; i < 8; i++) {
			total += password[i];
		}
		return total;
	}
	else {
		return 0;
	}
}


int main() {
	int Test;
	cin >> Test;
	for (int i = 1; i <= Test; i++)
	{
		int a, b, k, Flag = 0;
		back = 0;
		memset(map, 0, sizeof(map));
		memset(password, 0, sizeof(password));
		len = 0; start = 0;
		cin >> a >> b;

		for (int y = 0; y < a*b; y++) {
			scanf_s("%1d", &k);
			if (Flag == 1 && len < 56) {
				map[6 + len++] = k;
			}
			else if (k == 1 && Flag == 0) {
				map[5] = k;
				Flag = 1;
			}
		}

		for (int y = 119; y >= 0; y--) {
			if (map[y] == 1) {
				back = y;
				break;
			}
		}
		cout << "# " << i << check() << endl;
	}

	return 0;
}
