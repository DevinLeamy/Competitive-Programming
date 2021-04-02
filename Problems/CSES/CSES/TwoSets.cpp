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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	ll n; cin >> n;
	vector<bool> taken(n + 1);
	int top = n;
	int cnt = 0;
	ll total = n * (n + 1);
	if (total % 4 != 0) {
		cout << "NO" << endl;
		return 0;
	}
	total /= 4ll;
	
	ll cur = 0;
	while (top != 0 && cur != total) {
		ll diff = total - cur;
		while (diff < top)
			top--;
		if (top <= 0)
			break;
		cur += top;
		taken[top] = true;
		cnt++;
		top--;
	}
	if (cur != total) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES" << endl;
	cout << cnt << endl;
	for (int i = n; i >= 1; i--) {
		if (taken[i])
			cout << i << " ";
	}
	cout << endl;
	cout << n - cnt << endl;
	for (int i = n; i >= 1; i--) {
		if (!taken[i])
			cout << i << " ";
	}
	
	return 0;
}
