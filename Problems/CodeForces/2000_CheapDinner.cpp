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
#define LINF 9223372036854775ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
using namespace std;
char _;

bool solve(vector<pair<ll, int> > &row1, vector<pair<ll, int> > &row2, vector<vector<int> > aadj) {
	sort(row1.begin(), row1.end());
	int n = (int) row1.size();
	int m = (int) row2.size();
	// Update row2
	if (row1[0].first == LINF)
		return false;
	
	for (int i = 0; i < m; i++) {
		if (aadj[i].size() == n) {
			row2[i].first = LINF;
			continue;
		}
		int cur = 0;
		while (binary_search(aadj[i].begin(), aadj[i].end(), row1[cur].second)) // Make sure aadj[i] is sorted!
			cur++;
		if (row1[cur].first == LINF) {
			row2[i].first = LINF;
			continue;
		}
		row2[i].first += row1[cur].first;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	vector<vector<pair<ll, int> > > vals;
	vector<int> len(4);
	for (int i = 0; i < 4; i++)
		cin >> len[i];
	
	for (int i = 0; i < 4; i++) {
		int n = len[i];
		vals.pb(vector<pair<ll, int> >(n));
		for (int j = 0; j < n; j++) {
			cin >> vals[i][j].first;
			vals[i][j].second = j;
		}
	}
	vector<vector<int> > aadj1(len[1], vector<int>()),
						 aadj2(len[2], vector<int>()),
					     aadj3(len[3], vector<int>());
	
	
	for (int i = 0; i < 3; i++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int a, b; cin >> a >> b;
			a--; b--;
			if (i == 0)
				aadj1[b].pb(a);
			else if (i == 1)
				aadj2[b].pb(a);
			else
				aadj3[b].pb(a);
		}
	}
	for (int i = 0; i < len[1]; i++)
		sort(aadj1[i].begin(), aadj1[i].end());
	
	for (int i = 0; i < len[2]; i++)
		sort(aadj2[i].begin(), aadj2[i].end());
	
	for (int i = 0; i < len[3]; i++)
		sort(aadj3[i].begin(), aadj3[i].end());
	
	bool works = true;
	works &= solve(vals[0], vals[1], aadj1);
	works &= solve(vals[1], vals[2], aadj2);
	works &= solve(vals[2], vals[3], aadj3);
	
	ll min = LINF;
	for (pair<ll, int> val : vals[3])
		min = std::min(val.first, min);
	
	if (!works || min == LINF) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << min << endl;
	return 0;
}
