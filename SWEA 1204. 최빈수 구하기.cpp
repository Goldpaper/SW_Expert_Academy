#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int T, testcaseNum, max, tmp;
    int student[101];
    int studentNum = 1000;

    cin >> T;
    while(T--) {
        max = 0;
        memset(student, 0, sizeof(student));
        cin >> testcaseNum;
        for(int i=0; i<studentNum; i++) {
            cin >> tmp;
            student[tmp]++;
        }
        for(int i=0; i<=100; i++) {
            max = student[max] <= student[i] ? i : max;
        }
        cout << "#" << testcaseNum << " " << max << "\n";
    }
}