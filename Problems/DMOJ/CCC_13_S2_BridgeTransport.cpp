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

int sum(vector<int> me) { int count = 0; loopX(me.size()) {count += me[i];} return count;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int w, n, weight; cin >> w >> n;
	vector<int> onTrack; int t = -1; bool over = false;
	loopX(n) {
		if (sum(onTrack) > w) {over = true;}
		if (!over) {t = i;}
		cin >> weight; onTrack.pb(weight);
		if (onTrack.size() > 4) {onTrack.erase(onTrack.begin());}
	}
	if (t == n-1) {cout << n << endl;}
	else {cout << t << endl;}
	
	return 0;
}
