#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loopX(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> chores; int time, cs, c;
	cin >> time >> cs;
	loopX(cs) {
		cin >> c;
		chores.pb(c);
	}
	sort(chores.begin(), chores.end());
	int current = 0;
	while (time > 0) {
		if (current == chores.size()) {break;}
		if (time >= chores[current]) {
			time -= chores[current]; current++;
		} else {break;}
	}
	cout << current << endl;
	return 0;
}
