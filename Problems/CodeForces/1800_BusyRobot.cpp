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

int solve() {
	int n; cin >> n;
	queue<PL> cmds;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		cmds.push(make_pair(a, b));
	}
	int ans = 0;
	ll t = 0; // Current time / time of previous commmand
	ll current_loc = 0;
	ll end_loc = 0; // Desired location
	ll prev_des = -1; // Desired location of previous command
	bool last = false;
	while (!cmds.empty()) {
		PL cmd = cmds.front(); cmds.pop();
		ll time = cmd.first, place = cmd.second;
		ll frame_start = current_loc; // t_{i - 1}
		ll dist = min(abs(current_loc - end_loc), time - t);
		
		if (end_loc <= current_loc)
			current_loc -= dist;
		else
			current_loc += dist;
		
		ll frame_end = current_loc;
		if (frame_start <= prev_des && prev_des <= frame_end)
			ans++;
		else if (frame_start >= prev_des && prev_des >= frame_end)
			ans++;
		
		if (current_loc == end_loc) {
			end_loc = place;
			last = true;
		} else {
			last = false;
		}
		t = time;
		prev_des = place;
	}
	if (last)
		ans++;
	else if (current_loc <= prev_des && prev_des <= end_loc)
		ans++;
	else if (current_loc >= prev_des && prev_des >= end_loc)
		ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int t; cin >> t;
	loop(t) {
		printf("%d\n", solve());
	}
	return 0;
}
