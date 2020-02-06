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
	int t; cin >> t; ;
	loop(t) {
		set<string> cities; int n; cin >> n; string city;
		for (int j = 0; j < n; j++) {
			cin >> city;
			cities.insert(city);
		}
		cout << cities.size() << endl;
	}
	return 0;
}
