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

int times[101];
int waitTime[101];
bool waiting[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m; cin >> m; string t; int p;
	int currentTime = 0; set<int> friends;
	loop(m) {
		cin >> t >> p;
		if (t == "W") {currentTime+=(p-1); continue;}
		else if (t == "R") {waiting[p] = true; times[p] = currentTime;}
		else if (t == "S") {waiting[p] = false; waitTime[p] += currentTime - times[p];}
		friends.insert(p);
		currentTime += 1;
	}
	for (int h : friends) {
		cout << h << " " << (waiting[h]? -1 : waitTime[h]) << endl;
	}
	return 0;
}
