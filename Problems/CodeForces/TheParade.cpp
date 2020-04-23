#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int n; ll k;

bool valid(vector<ll>& h, ll count) {
	ll rows = 0;
	ll rem = 0;
	for (int i = 0; i < n; i++) {
		ll cur = h[i];
		if (rem + h[i] >= count) {
			rows++;
			cur -= count - rem;
		}
		rem = 0;
		rows += cur / count;
		rem = cur % count;
	}
	if (rows >= k) {
		return true;
	}
	return false;
}

ll binarySearch(ll low, ll high, vector<ll>& h) {
	ll mid = (low + high) / 2;
	if (mid == low) {
		return low;
	} else if (low > high) {
		return low;
	}
	
	if (valid(h, mid)) {
		return binarySearch(mid, high, h);
	} else {
		return binarySearch(low, mid - 1, h);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		ll c;
		cin >> n >> k;
		vector<ll> h;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> c;
			h.push_back(c);
			sum += c;
		}
		ll val = binarySearch(0, sum, h);
		if (valid(h, val+1)) {
			ll total = (val + 1) * k;
			cout << total << "\n";
		} else {
			ll total = val * k;
			cout << total << "\n";
		}
	}
	return 0;
}
