#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, g; cin >> n; vector<int> a; vector<int> b;
	loop(n) {cin >> g; a.pb(g);}
	loop(n) {cin >> g; b.pb(g);}
	bool same = false; int count = 0;
	loop(n) {
		if (a[i] == b[i]) {
			if (!same) {
				same = true;
				count++;
			}
		} else {
			same = false;
		}
	}
	cout << count << endl;
	return 0;
}
