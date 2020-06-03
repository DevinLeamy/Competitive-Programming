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
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
		int n, a; cin >> n;
		vector<int> grans;
		for (int i = 0; i < n; i++) { cin >> a; grans.pb(a); }
		sort(grans.begin(), grans.end());
		int total = 1;
		int pot = 0;
		for (int i = 0; i < n; i++) {
			if (grans[i] <= total + pot) {
				total += 1 + pot;
				pot = 0;
			} else { pot++; }
		}
		cout << total << endl;
	}
	return 0;
}
