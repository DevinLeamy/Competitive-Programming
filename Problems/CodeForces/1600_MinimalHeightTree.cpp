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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		vector<int> vals(n);
		for (int i = 0; i < n; i++) cin >> vals[i];
		
		int cnt = 1;
		int leads = 1;
		int cur = 0;
		int nxt = 0;
		for (int i = 1; i < n; i++) {
			if (vals[i] > cur) {
				cur = vals[i];
				nxt++;
			} else {
				leads--;
				if (leads == 0) {
					leads = nxt;
					nxt = 0;
					cnt++;
				}
				cur = vals[i];
				nxt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
