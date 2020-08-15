#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
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

ll findSubarraySum(vector<int> &arr, int n, int sum) {
	unordered_map<ll, ll> prevSum;
	ll res = 0;
	ll currsum = 0;
	for (int i = 0; i < n; i++) {
		currsum += arr[i];
	if (currsum == sum)
	    res++;
	if (prevSum.find(currsum - sum) != prevSum.end())
		res += (prevSum[currsum - sum]);
		prevSum[currsum]++;
	}

	return res;
}
  

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> vals;
		for (int i = 0; i < n; i++) {
			int val = s[i] - '0';
			vals.pb(val - 1);
		}
		cout << findSubarraySum(vals, n, 0) << endl;
	}
	return 0;
}
