#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define ll long long
#define pb push_back
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int r, c, b;
	cin >> r >> c;
	vector< vector<bool> > og;
	set<string> collector;
	vector<int> order;
	for (int i = 0; i < r; i++) {
		og.pb(vector<bool>());
		if (i != 0) {order.pb(i);}
		for (int j = 0; j < c; j++) {
			cin >> b;
			og[i].pb(b==1);
		}
		if (i == r-1) {
			string bottom = "";
			for (bool value : og[r-1]) {
				bottom += (value)? "1" : "0";
			}
			collector.insert(bottom);
		}
	}
	int count = 0;
	do {
		vector< vector<bool> > on = og;
		for (int i = count; i < order.size(); i++) {
			for (int j = 0; j < c; j++) {
				on[order[i]][j] = (on[order[i]-1][j] == on[order[i]][j])? false : true;
			}
			if (order[i] == r-1) {
				string bottom = "";
				for (bool value : on[r-1]) {
					bottom += (value)? "1" : "0";
				}
				collector.insert(bottom);
			}
		}
		count++;
	} while (count != r);
	cout << collector.size() << endl;
}
