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
	int n; cin >> n; vector<ll> villages; ll vill; double smallest = 2000000001;
	loop(n) {cin >> vill; villages.pb(vill);} sort(villages.begin(), villages.end());
	for (int i = 1; i < n-1; i++) {
		double left = abs(villages[i] - villages[i-1]) / (double)2;
		double right = abs(villages[i] - villages[i+1]) / (double)2;
		smallest = min(smallest, right + left);
	}
	cout << fixed;
	cout << setprecision(1);
	cout << smallest << endl;
	return 0;
}
