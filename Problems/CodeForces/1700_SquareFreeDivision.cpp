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
#define view2(a, b) cout << "DEBUG: " << a << " " << b << endl;
using namespace std;
char _;

vector<ll> primes;
ll MAXP = sqrt(10000001ll) + 10ll;
void generate_primes() {
	vector<bool> is_prime(MAXP, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for (ll i = 2; i <= MAXP; i++) {
		for (ll j = i + i; j <= MAXP; j += i) {
			is_prime[j] = false;
		}
	}
	for (ll i = 0; i <= MAXP; i++) {
		if (is_prime[i])
			primes.pb(i);
	}
}
int solve() {
	int n, k; cin >> n >> k;
	vector<ll> vals(n);
	vector<ll> short_rep(n);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	for (int i = 0; i < n; i++) {
		ll short_rep_i = 1;
		for (int j = 0; j < (int) primes.size() && vals[i] != 1; j++) {
			int cnt = 0;
			while (vals[i] % primes[j] == 0) {
				vals[i] /= primes[j];
				cnt++;
			}
			cnt %= 2;
			if (cnt == 1)
				short_rep_i *= primes[j];
		}
		if (vals[i] != 1)
			short_rep_i *= vals[i];
		short_rep[i] = short_rep_i;
	}
	int total_segs = 1;
	set<ll> seg;
	for (int i = 0; i < n; i++) {
		if (seg.find(short_rep[i]) != seg.end()) {
			total_segs++;
			seg.clear();
		}
		seg.insert(short_rep[i]);
	}
	return total_segs;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	generate_primes();
	loop(t) {
		cout << solve() << "\n";
	}
	return 0;
}
