#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
const int maxV = 31;

using namespace std;
//Patrick always goes first, loser has nothing to play
bool DP[maxV][maxV][maxV][maxV];
int main() {
    int t, a, b, c, d;
    vector< vector<int> > reactions = {
        {2, 1, 0, 2},
        {1, 1, 1, 1},
        {0, 0, 2, 1},
        {0, 3, 0, 0},
        {1, 0, 0, 1}
    };
    
    for (int i = 0; i < maxV; i++) {
        for (int j = 0; j < maxV; j++) {
            for (int k = 0; k < maxV; k++) {
                for (int l = 0; l < maxV; l++) {
                    for (int m = 0; m < reactions.size(); m++) {
                        int newA = i - reactions[m][0];
                        int newB = j - reactions[m][1];
                        int newC = k - reactions[m][2];
                        int newD = l - reactions[m][3];
                        if (!(newA < 0 || newB < 0 || newC < 0 || newD < 0)) {
                            DP[i][j][k][l] = DP[newA][newB][newC][newD] == false? true : DP[i][j][k][l];
                        }
                    }
                }
            }
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        //Assume Patrick is correct: if he is not then Roland is correct
        if (DP[a][b][c][d]) {
            cout << "Patrick" << endl;
        } else {
            cout << "Roland" << endl;
        }
    }
    
    return 0;
}
