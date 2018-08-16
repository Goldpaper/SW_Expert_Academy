/*****************************
두번째는 그리디적인 방법으로 풀었다.

결국 앞에 올수록 큰 수가 와야 한다, 따라서 맨 앞자리 부터 가장 큰 수로 채우는 방법이다.

가장 왼쪽 자리부터 시작해서 가장 큰 값을 찾는다, 만약 가장 큰 값이 자기 자신이면 그 다음으로 이동한다.

근데 만약 가장 크지 않다면 가장 큰 값과 바꿔주고, 바꾼 횟수를 1 늘려준다. 그러다가 가장 왼쪽값이 주어진 숫자의 

맨 오른쪽에서 두번째가 되면, 

오른쪽에서 첫번째값과 계속 바꿔주기만 하면 된다. 이때 자릿수를 늘려주지 않고, 교환 횟수만 늘려주게 된다.

10의 자리와 1의 자리만 계속 바꿔준다는 뜻이다, 이미 앞의 자릿수 100,1000,10000...은 가장 큰 수부터 채워져 있다.

그런 방식으로 문제를 풀었다.
******************************/

#include<iostream>
#include<string>
#include<string.h>

using namespace std;

string n;
int k, ans;
int D[1000000];

void go(string &m,int pos,int cnt) {
    if (cnt == k) {
        int ret = stoi(m);
        if (ret > ans) {
            ans = ret;
        }
        return;
    }
 
    if (pos == m.size() - 2) {
        string tmp = m;
        swap(tmp[pos+1], tmp[pos]);
        go(tmp, pos, cnt + 1);
        return;
    }
 
 
    int big = -1;
    for (int i = pos+1; i < m.size(); i++) {
        if (m[i] - '0' > big) {
            big = m[i] - '0';
        }
    }
 
    if (m[pos] - '0' == big) {
        go(m, pos + 1, cnt);
    }
 
    for (int i = pos + 1; i < m.size(); i++) {
        if (m[i] - '0' == big) {
            string tmp = m;
            swap(tmp[i], tmp[pos]);
            go(tmp, pos + 1, cnt + 1);
        }
    }
 
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
 
    for (int t = 1; t <= tc; t++) {
        str = "";
        k = 0, ans = 0;
        cin >> str >> k;
    
        go(str,0,0);
 
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
