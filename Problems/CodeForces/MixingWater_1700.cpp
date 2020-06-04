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

double h, c, n;

double func(ll cups) {
	ll hot = (cups/2 + cups%2) * h;
	ll cold = (cups/2) * c;
	double average = (hot+cold)/(double)(cups);
	return abs(average - n);
}

double ternary_search(double l, double r) {
    double eps = 4;
    while (r - l > eps) {
	    ll m1 = l + (r - l) / 3;
	    ll m2 = r - (r - l) / 3;
	    if (m1 % 2 == 0) { m1++; }
	    if (m2 % 2 == 0) { m2++; }
	    double f1 = func(m1);
	    double f2 = func(m2);
	    if (f1 > f2) { l = m1; }
	    else { r = m2; }
    }
    return l;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	loop(t) {
		cin >> h >> c >> n;
		if (n >= h) {
			cout << "1" << endl;
		} else if (n <= c || 2*n == c+h) {
			cout << "2" << endl;
		} else {
			if (abs(h-n) < abs(c-n)) {
				//Odd number answer
				double min = LINF;
				ll best = ternary_search(1, 999999);
				for (ll i = max(1ll, best-4); i <= best + 4; i++) {
					if (func(i) < min) {
						best = i;
						min = func(i);
					}
				}
				cout << best << endl;
			} else {
				//Even number answer
				cout << "2" << endl;
			}
		}
	}
	return 0;
}
