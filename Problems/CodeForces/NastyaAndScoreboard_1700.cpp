#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <string>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;
 

bool dp[2001][2001]; // From position i can you spend exactly j sticks
int cost[2001][10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<vector<bool>> nums;
	string num;
	for (int i = 0; i < n; i++) {
		nums.pb(vector<bool>());
		cin >> num;
		for (int j = 0; j < 7; j++) {
			if (num[j] == '0') {
				nums[i].pb(false);
			} else {
				nums[i].pb(true);
			}
		}
	}
	string dig[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<vector<bool>> bits;
	for (int i = 0; i < 10; i++) {
		bits.pb(vector<bool>());
		for (int j = 0; j < 7; j++) {
			if (dig[i][j] == '0') {
				bits[i].pb(false);
			} else {
				bits[i].pb(true);
			}
		}
	}
	dp[n][0] = true;
	for (int i = n-1; i >= 0; i--) {
		for (int l = 9; l >= 0; l--) {
			int count = 0;
			for (int m = 0; m < 7; m++) {
				if (bits[l][m] && !nums[i][m]) {
					count++;
				} else if (!bits[l][m] && nums[i][m]) {
					count = INF;
					break;
				}
			}
			cost[i][l] = count;
			for (int j = 0; j <= k-count; j++) {
				if (dp[i+1][j]) {
					dp[i][j+count] = true;
				}
			}
		}
		
		
	}
	string s = "";
	int m = k;
	for (int i = 0; i < n; i++) {
		if (dp[i][m]) {
			for (int j = 9; j >= 0; j--) {
				if (cost[i][j] <= m && dp[i+1][m - cost[i][j]]) {
					s += to_string(j);
					m -= cost[i][j];
					break;
				}
			}
		}
	}
	if (dp[0][k]) {
		cout << s << "\n";
		return 0;
	}
	cout << "-1\n";
}
