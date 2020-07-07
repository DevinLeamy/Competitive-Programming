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
	int n; cin >> n;
	ll a;
	vector<ll> preF; preF.pb(0);
	ll count = 0;
	for (int i = 0; i < n; i++) { cin >> a; preF.pb(preF[i] + a); }
	vector<int> start;
	vector<int> end;
	for (int i = 0; i < n-1; i++) {
		ll sum = preF[i + 1];
		ll rem = preF[n] - sum;
		if (rem == sum * 2) { start.pb(i); }
		if (rem * 2 == sum) { end.pb(i); }
	}
	int ptr = 0;
	for (int i = 0; i < start.size(); i++) {
		int index = start[i];
		while (ptr != end.size() && index >= end[ptr]) {
			ptr++;
		}
		count += end.size() - ptr;
	}
	cout << count << endl;
	return 0;
}
