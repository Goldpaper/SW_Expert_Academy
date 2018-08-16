#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int testcaseNum;
    int ladder[102][102];
    int point;
    for(int i=1; i<=10; i++) {
        cin >> testcaseNum;
        memset(ladder, -1, sizeof(ladder));
        //사다리 세팅
        for(int j=1; j<=100; j++) {
            for(int k=1; k<=100; k++) {
                cin >> ladder[j][k];
            }
        }
        //도착점 찾기
        for(int k=1; k<=100; k++) {
            if(ladder[100][k] == 2) {
                point = k;
                break;
            }
        }
        //endPoint로 부터 출발점까지 이동
        for(int j=99; j>=1; j--) {
            while(ladder[j][point-1] && point >=0) {
                point--;
            }
            while(ladder[j][point+1] && point <=100) {
                point++;    
            }
       }
        cout << "#" <<testcaseNum << " " << point-1 << "\n";
    }
}