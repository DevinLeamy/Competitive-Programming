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
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, x, a;
		cin >> n >> x;
		int even = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a % 2 == 0) { even++; }
		}
		int odd = n - even;
		if (even == n) {
			cout << "No" << endl;
			continue;
		}
		odd--;
		x--;
		odd -= odd % 2;
		x -= min(x - x % 2, odd);
		if (x > even) { cout << "No" << endl; }
		else { cout << "Yes" << endl; }
	}
	return 0;
}
