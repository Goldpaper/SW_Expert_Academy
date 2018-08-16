/*
1900 문제풀이 시작하겠습니다.
1247 최적 경로 문제입니다.
경로 중 가장 짧은 것을 찾으려고 합니다.

회사 집 좌표, 2~10명 사이의 고객의 좌표가 주어짐
회사 -> 고객 -> 집으로 돌아가는 최소 거리를 찾습니다.
일단 입력을 받아 보겠습니다.

이거 맵으로 입력 받아서 푸는 문제가 아닌 것 같은데.

예제를 한번 보도록 하겠습니다.

0 1 2 3 4 5 6 있으면
모두 1 2 3 4 5 를 모두 1로 만든 다음에 6으로 가는 거리를 계산하면 되겠습니다.

dfs 로 풀고 depth == 5 이면, 마지막에 end 와의 거리를 계산하면 되겠습니다.
순열문제입니다. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
}map[10];

int visit[10];
int startX, startY, endX, endY;
int minVal = 2123456789;
int n;

void problemIn() {
	cin >> n;
	cin >> startX >> startY;
	cin >> endX >> endY;
	for (int i = 0; i < n; i++) {
		cin >> map[i].x >> map[i].y;
	}
}

void dfs(int depth, int x, int y, int sum) {
	if (depth == n) {
		sum += (abs(endX - x) + abs(endY - y));
		minVal = min(minVal, sum);
		sum -= (abs(endX - x) + abs(endY - y));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(depth + 1, map[i].x, map[i].y, (sum + abs(map[i].x - x) + abs(map[i].y - y)));
			visit[i] = 0;
		}
	}
}

void solve() {
	dfs(0, startX, startY, 0);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		problemIn();
		solve();
		cout << "#" << tc << " " << minVal << endl;
		minVal = 2123456789;
	}
	return 0;
}