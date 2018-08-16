#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int wall[100];  //가로 길이
    int T = 10;     //Testcase    
    int dumpCnt;
    
    for(int i=1; i<T; i++) {
        cin >> dumpCnt;
        for(int j=0; j<100; j++) {
            cin >> wall[j];
        }
        while(dumpCnt--) {
            //비효율의 끝.. 실제로는 4개의 포인터로 한번만 정렬해도 해결 가능
            sort(wall, wall+sizeof(wall));
            wall[0]++;
            wall[99]--;
        }
        sort(wall, wall+sizeof(wall));
        cout << "#" << i << " " << wall[99]-wall[0] << "\n";
    }
}