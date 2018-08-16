#include <iostream>
#include <cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;

int main() {
	int arr[1000];
	int T, x, tmp;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int result = 0;
		memset(arr, 0, sizeof(arr));

		cin >> x;
		for (int j = 0; j<x; j++) {
			cin >> arr[j];
		}
		for (int j = 2; j<x - 2; j++) {
			tmp = arr[j] - max(max(arr[j - 1], arr[j - 2]), max(arr[j + 1], arr[j + 2]));
			result += 0 > tmp ? 0 : tmp;
		}
		cout << "#" << i << " " << result << "\n";
	}
}