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
int dp[200001][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, c, a, b;
	cin >> n >> c;
	int stairs[n];
	int elevator[n];
	for (int i = 0; i < n; i++) {dp[i][0] = 100000000; dp[i][1] = 100000000;}
	dp[0][0] = 0; dp[0][1] = 0;
	for (int i = 0; i < n-1; i++) { cin >> a; stairs[i] = a; }
	for (int i = 0; i < n-1; i++) { cin >> b; elevator[i] = b;}
	for (int i = 1; i < n-1; i++) {
		dp[i][0] = min(dp[i][0], dp[i-1][0] + stairs[i-1]); //Case 1
		dp[i][1] = min(dp[i][1], dp[i-1][0] + elevator[i-1]); //Case 2
		dp[i][1] = min(dp[i][1], dp[i-1][1] + elevator[i-1]); //Case 3
		dp[i][0] = min(dp[i][0], dp[i-1][0] + c + elevator[i-1]); //Case 4;
		dp[i][0] = min(dp[i][0], dp[i-1][1] + c + elevator[i-1]);
	}
	dp[n-1][0] = min(dp[n-1][0], dp[n-2][0] + stairs[n-2]);
	dp[n-1][0] = min(dp[n-1][0], dp[n-2][0] + c + elevator[n-2]);
	dp[n-1][0] = min(dp[n-1][0], dp[n-2][1] + c + elevator[n-2]);
	for (int i = 0; i < n; i++) {cout << dp[i][0] << " ";}
	return 0;
}
