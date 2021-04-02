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

ll trees[200005];
int n, m;

vector<ll> func(int max_dist) {
	int threshold = max_dist - 1; // If someone can be placed this close, place them
	vector<ll> max_d_pos;
	vector<ll> pos;
	
	for (ll i = trees[0] - threshold; i < trees[0]; i++)
		pos.pb(i);
	for (ll i = trees[n - 1] + 1; i <= trees[n - 1] + threshold; i++)
		pos.pb(i);
	
	max_d_pos.pb(trees[0] - max_dist);
	max_d_pos.pb(trees[n - 1] + max_dist);
	
	for (int i = 0; i < n - 1; i++) {
		if (pos.size() >= m)
			return pos;
		ll dist = trees[i + 1] - trees[i] - 1;
		if (dist >= 2*max_dist) {
			max_d_pos.pb(trees[i] + max_dist);
			max_d_pos.pb(trees[i + 1] - max_dist);
		} else if (dist == 2 * max_dist - 1) {
			max_d_pos.pb(trees[i] + max_dist);
		}
		ll cur_l = trees[i] + 1;
		ll last_placed = cur_l;
		while (cur_l - trees[i] <= threshold && trees[i + 1] - cur_l >= cur_l - trees[i]) {
			pos.pb(cur_l);
			last_placed = cur_l;
			cur_l++;
		}
		cur_l = max(last_placed + 1, trees[i + 1] - threshold);
		for (ll j = cur_l; j < trees[i + 1]; j++) {
			pos.pb(j);
		}
			
	}
	if (pos.size() + max_d_pos.size() < m)
		return {};
	while (pos.size() < m) {
		pos.pb(max_d_pos.back());
		max_d_pos.pop_back();
	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> trees[i];
	sort(trees, trees + n);
	int left = 1;
	int right = m / 2 + m % 2;
	while (left < right) {
		int mid = (left + right) / 2;
		vector<ll> res = func(mid);
		if (res.empty())
			left = mid + 1;
		else
			right = mid;
	}
	
	vector<ll> res = func(left);
	ll sum = 0;
	sort(res.begin(), res.end());
	int cur = 0;
	int idx = 0;
	while (idx != m) {
		ll dist = abs(res[idx] - trees[cur]);
		if (cur < n && abs(res[idx] - trees[cur + 1]) < dist) {
			cur++;
			continue;
		}
		idx++;
		sum += dist;
	}
	
	cout << sum << endl;
	for (ll val : res)
		printf("%lld ", val);
	printf("\n");
	return 0;
}
