#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
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
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	vector<int> count(10);
	string code = "codeforces";
	string ans = "";
	for (int i = 0; i < 10; i++) {
		count[i] = 1;
	}
	ll cur = 1;
	while(cur < n) {
		for (int i = 0; i < 10; i++) {
			cur /= count[i];
			count[i]++;
			cur *= count[i];
			if (cur >= n) { break; }
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count[i]; j++) {
			ans += code[i];
		}
	}
	cout << ans << endl;
	return 0;
}
