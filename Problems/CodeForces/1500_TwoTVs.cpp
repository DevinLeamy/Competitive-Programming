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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;
 
bool solve() {
	int n; cin >> n;
	vector<ll> starts(n), ends(n);
	for (int i = 0; i < n; i++) {
		cin >> starts[i] >> ends[i];
	}
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	
	int sp = 0;
	int ep = 0;
	int watching = 0;
	while (sp != n) {
		while (ends[ep] < starts[sp]) {
			watching--;
			ep++;
		}
		
		while (sp != n && starts[sp] <= ends[ep]) {
			watching++;
			sp++;
			if (watching > 2)
				return false;
		}
	}
	return true;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	if (solve())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
