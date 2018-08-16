/*****************************
첫번째는 캐시를 이용해서 푸는 방법이다, 

완전탐색으로 진행하되,  D[n] 은 n번 교환했을 때 최대값 을 저장했다.

따라서 똑같은 n번 교환했을 때 값이 작다면, return 을 해서 돌아가도록 만들었다.

사실 근데 D의 배열을 몇까지 해야할지, 즉 최대교환 횟수가 문제에 주어지지 않아서 처음에 생각을 못했다.

근데 그냥 좀 크게해서 문제를 푸니까 이 문제는 풀 수 있었다.
******************************/

#include<iostream>
#include<string>
#include<string.h>

using namespace std;

string n;
int k, ans;
int D[1000000];

void go(string m, int cnt) {
	int ret = stoi(m);

	if (D[cnt] > ret) {
		return;
	}

	if (cnt == k) {
		if (ret > ans) {
			ans = stoi(m);
		}
		return;
	}

	D[cnt] = ret;


	for (int i = 0; i < m.size(); i++) {
		for (int j = i + 1; j < m.size(); j++) {
			string tmp = m;
			swap(tmp[i], tmp[j]);
			go(tmp, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		memset(D, -1, sizeof(D));
		n = "";
		k = 0, ans = 0;
		cin >> n >> k;
		go(n, 0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
