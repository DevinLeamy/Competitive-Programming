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

bool solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if (2 * k == n)
		return false;
	
	string front = s.substr(0, k);
	string back = s.substr(n - k, k);
	reverse(back.begin(), back.end());
	
	return (front == back);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
