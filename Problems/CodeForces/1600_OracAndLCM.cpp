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

vector<vector<int>> vals;
vector<int> primeFacts(int n) {
	vector<int> ans(500);
	int temp = n;
	for (int i = 2; i <= sqrt(temp); i++) {
		while (n % i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	if (n != 1) { vals[n][1]++; }
	return ans;
}

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a; cin >> n;
	
	for (int i = 0; i < 200000; i++) { vals.pb(vector<int>(18)); }
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (isPrime(a)) { vals[a][1]++; continue; }
		vector<int> facts = primeFacts(a);
		for (int j = 2; j < 500; j++) {
			for (int z = 1; z <= facts[j]; z++) {
				vals[j][z]++;
			}
		}
	}
	ll ans = 1;
	for (int i = 2; i < 200000; i++) {
		for (int j = 17; j >= 1; j--) {
			if (vals[i][j] >= n-1) {
				ans *= pow(i, j);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
