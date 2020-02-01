#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> docked; int g, p, d; cin >> g >> p; int count = 0;
	for (int i = 1; i <= g; i++){docked.pb(-i);}
	sort(docked.begin(), docked.end());
	loop(p) {
		cin >> d;
		int pos = upper_bound(docked.begin(), docked.end(), -1 * (d+1)) - docked.begin() ;
		if (pos >= docked.size() || docked[pos] > d) {break;}
		count++;
		docked.erase(upper_bound(docked.begin(), docked.end(), -1 * (d+1)));
	}
	cout << count << endl;
	return 0;
}
