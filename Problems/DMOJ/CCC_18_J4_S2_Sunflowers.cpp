#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;
int board[101][101];
int newBoard[101][101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v; board[i][j] = v;
		}
	}
	while (true) {
		if (board[0][0] < board[0][1] && board[0][0] < board[1][0]) {break;}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				newBoard[i][j] = board[n-1-j][i];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = newBoard[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		string line = "";
		for (int j = 0; j < n; j++) {
			line += to_string(board[i][j]); line += " ";
		}
		cout << line << endl;
	}
	return 0;
}
