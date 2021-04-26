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

PI solve() {
	string s; cin >> s;
	int n = (int) s.size();
	PI start = {0, 0};
	PI pos = start;
	set<PI> potential;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U')
			pos.first++;
		else if (s[i] == 'D')
			pos.first--;
		else if (s[i] == 'R')
			pos.second++;
		else
			pos.second--;
		potential.insert(pos);
	}
	for (auto iter = potential.begin(); iter != potential.end(); iter++) {
		PI ob = *iter;
		PI cur = start;
		for (int i = 0; i < n; i++) {
			PI temp = cur;
			if (s[i] == 'U')
				cur.first++;
			else if (s[i] == 'D')
				cur.first--;
			else if (s[i] == 'R')
				cur.second++;
			else
				cur.second--;
			if (cur.first == ob.first && cur.second == ob.second)
				cur = temp;
		}
		if (cur.first == 0 && cur.second == 0)
			return ob;
	}
	return start;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		PI res = solve();
		printf("%d %d\n", res.second, res.first);
	}
	return 0;
}
