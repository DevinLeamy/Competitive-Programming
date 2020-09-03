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
	vector<int> vals(9);
	for (int i = 0; i < 9; i++) cin >> vals[i];
	int min = vals[0];
	for (int num : vals) min = std::min(min, num);
	ll digits = n / min;
	if (digits == 0) {
		cout << -1 << endl;
		return 0;
	}
	string ans = "";
	ll rem = n;
	ll toPlace = digits;
	for (int i = 8; i >= 0; i--) {
		int cost = vals[i];
		while ((rem - cost)/min == toPlace - 1 && toPlace > 0 && rem >= cost) {
			ans += to_string(i + 1);
			rem -= cost;
			toPlace--;
		}
	}
	cout << ans << endl;
	return 0;
}
