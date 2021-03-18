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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

vector<int> solve(int n, vector<int> vals) {
	vector<PI> sums(5000001, {-1, -1});
	
	// Note that by the pigeon hole principle this executes in
	// O(min( n^2, n + 4 * (2*C) )) given that all possible sums will be
	// be seen at least 4 times by four unique pairs in 4 * (2*C) thus resulting
	// in two non-overlapping pairs, a valid answer.
	for (int i = 0; i < n; i++) {
		ll x = vals[i];
		for (int j = i + 1; j < n; j++) {
			ll sum = x + vals[j];
			if (sums[sum].first == -1) {
				sums[sum] = make_pair(i, j);
			} else {
				PI cur = sums[sum];
				
				if (cur.first == i || cur.first == j || cur.second == i || cur.second == j)
					continue;
				
				return { i, j, cur.first, cur.second };
			}
		}
	}
	return { };
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	
	vector<int> res = solve(n, vals);
	if (!res.empty()) {
		cout << "YES" << endl;
		for (int val : res)
			cout << val + 1 << " ";
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
