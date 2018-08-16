#include <iostream>
#include <cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

int main() {
    int arr[100][100];
    int rowSum[100];
    int colSum[100];
    int T = 10;     //테스트 케이스
    int Tnum;


    for(int i=1; i<=T; i++) {
        int result = 0;
        int leftCross = 0, rightCross = 0;
        memset(arr, 0, sizeof(arr));
        memset(rowSum, 0, sizeof(rowSum));
        memset(colSum, 0, sizeof(colSum));

        cin >> Tnum;
        for(int j=0; j<100; j++) {
            for(int k=0; k<100; k++) {
                cin >> arr[j][k];
                rowSum[j] += arr[j][k];
                colSum[k] += arr[j][k]; 
            }
            leftCross += arr[j][j];
            rightCross += arr[j][99-j];
        }
        for(int j=0; j<100;j++) {
            result = result < max(rowSum[j], colSum[j]) ? max(rowSum[j], colSum[j]) : result;
        }
        cout << "#" << Tnum << " " << max(result, max(leftCross, rightCross)) << "\n";
    }
}