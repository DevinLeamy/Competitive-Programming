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

int mod;
int mult(int a, int b) {
	return (a * b) % mod;
}

int facts[4005];
int fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	if (facts[n] != 0)
		return facts[n];
	facts[n] = mult(n, fact(n - 1));
	return facts[n];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n >> mod;
	vector<int> vals(n);
	vector<int> ans;
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	sort(vals.begin(), vals.end());
	vector<int> upper_bounds(n + vals[n - 1] + 5);
	for (int i = vals[0]; i <= vals[n - 1] + n; i++) {
		upper_bounds[i] = (int) (upper_bound(vals.begin(), vals.end(), i) - vals.begin());
	}
	
	for (int i = vals[0]; i <= vals[n - 1]; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			int idx = upper_bounds[i + j];
			if (idx - j <= 0) {
				cnt = 0;
				break;
			}
			cnt = mult(cnt, fact(idx - j));
			if (cnt == 0)
				break;
		}
		if (cnt != 0)
			ans.pb(i);
	}
	
	cout << (int) ans.size() << endl;
	for (int val : ans)
		cout << val << " ";
	cout << endl;
	return 0;
}
