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
		ll n, k, l; cin >> n >> k >> l;
		vector<ll> vals(n);
		bool works = true;
		for (int i = 0; i < n; i++) {
			cin >> vals[i];
			if (vals[i] > l) {
				works = false;
			}
		}
		ll cur = k;
		bool dec = true;
		for (int j = 0; j < n; j++) {
			ll add = cur;
			if (vals[j] + add > l) {
				if (!dec || l - vals[j] > cur) {
					works = false;
					break;
				} else {
					cur = l - vals[j];
					cur--;
					if (cur == -1) {
						dec = false;
						cur = 1;
					}
				}
			} else {
				if (l - vals[j] >= k) {
					cur = k;
					dec = true;
					continue;
				} else {
					if (dec) {
						cur--;
						if (cur == -1) {
							dec = false;
							cur = 1;
						}
					} else {
						cur++;
						if (cur == k+1) {
							dec = true;
							cur = k-1;
						}
					}
				}
			}
		}
		if (works) {
			cout << "Yes" << endl;
		} else{
			cout << "No" << endl;
		}
		
		
	}
	return 0;
}
