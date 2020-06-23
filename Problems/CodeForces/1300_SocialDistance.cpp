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
	int t; cin >> t;
	loop(t) {
		int n, k, count = 0; cin >> n >> k;
		string tab; cin >> tab;
		vector<pair<int, int>> distance(n);
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (tab[i] == '1') { last = i; continue; }
			if (last == -1 || abs(last - i) > k) {
				distance[i].first = k;
			}
		}
		last = -1;
		for (int i = n-1; i >= 0; i--) {
			if (tab[i] == '1') { last = i; continue; }
			if (last == -1 || abs(last - i) > k) {
				distance[i].second = k;
			}
		}
		for (int i = 0; i < n; i++) {
			if (distance[i].first == k && distance[i].second == k) {
				count++;
				i += k;
			}
		}
		cout << count << endl;
	}
	return 0;
}
