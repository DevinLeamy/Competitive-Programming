#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n, k; cin >> n >> k;
		vector<int> cnts(26);
		string s; cin >> s;
		for (int i = 0; i < n; i++)
			cnts[s[i] - 'a']++;
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			int visited = 0;
			int cur = 0;
			do {
				visited++;
				cur = (cur + k) % i;
			} while (cur != 0);
			int cycles = i / visited;
			for (int b_cnt : cnts) {
				cycles -= max(0, b_cnt / visited);
				if (cycles <= 0) {
					ans = i;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
