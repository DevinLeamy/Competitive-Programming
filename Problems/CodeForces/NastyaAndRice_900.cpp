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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		bool works = false;
		for (int j = (a - b)*n; j <= abs(a + b)*n; j++) {
			if (abs(c-d) <= j && abs(c+d) >= j) {
				works = true;
			}
				
		}
		if (works) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}

	}
	return 0;
}
