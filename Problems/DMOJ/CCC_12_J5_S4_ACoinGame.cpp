// 30/50 marks
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

bool check(vector<vector<int>>);
int n, c;
bool isValid(int, int, vector<vector<int>>);
int main() {
	//Move largest into position followed by second largest followed by third largest
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> n; if (n == 0) {break;}
		vector< vector< vector<int> > > visited;
		vector< vector<int> > setUp; vector<bool> correct;
		vector<int> nums;
		loopX(n) {
			setUp.pb(vector<int>()); correct.pb(false);
			cin >> c; setUp[i].pb(c); nums.pb(c);
		}
		sort(nums.begin(), nums.end());
		queue< pair< vector< vector<int> >, int > > current;
		current.push( {setUp, 0});
		visited.pb(setUp);
		int minTurns = -1;
		while (current.size()) {
			pair< vector< vector<int> >, int > value = current.front(); current.pop();
			vector< vector<int> > state = value.first; int turns = value.second;
			
			if (check(state)) {cout << turns << endl; minTurns = turns; break;}
			for (int i = 0; i < state.size(); i++) {
				if (state[i].size() == 0) {continue;}
				int coin = state[i].back();
				if (nums[i] == coin) {
					if (i == n-1) {correct[i] = true;continue;}
					else if (correct[i] || correct[i+1]) {continue;}
				}
				if (isValid(i-1, coin, state)) {
					state[i].pop_back(); state[i-1].pb(coin);
					if (find(visited.begin(), visited.end(), state) == visited.end()) {
						current.push({state, turns+1}); visited.pb(state);
					}
					state[i].pb(coin); state[i-1].pop_back();
				}
				if (isValid(i+1, coin, state)) {
					state[i].pop_back(); state[i+1].pb(coin);
					if (find(visited.begin(), visited.end(), state) == visited.end()) {
						current.push({state, turns+1}); visited.pb(state);
					}
					state[i].pb(coin); state[i+1].pop_back();
				}
			}
		}
		if (minTurns == -1) {cout << "IMPOSSIBLE" << endl;}
	}
	return 0;
}
bool check(vector<vector<int>> state) {
	int lastCoin = -1;
	for (vector<int> stack : state) {
		if (stack.size() != 1) {return false;}
		int coin = stack.back();
		if (coin < lastCoin) {return false;}
		lastCoin = coin;
	}
	return true;
}
bool isValid(int x, int coin, vector< vector<int> > state) {
	if (x < 0 || x >= n) {return false;}
	if (state[x].size() == 0 || state[x].back() > coin) {return true;}
	return false;
}
