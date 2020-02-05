#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

bool visited[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, options, m; cin >> n; vector<vector<int>> adj(n); int shortestPath = 100000;
	loop(n) {
		cin >> options;
		for (int j = 0; j < options; j++) {
			cin >> m; m--;
			adj[i].pb(m);
		}
	}
	queue<PI> current;
	current.push({0, 1});
	while (!current.empty()) {
		PI page = current.front(); current.pop();
		if (visited[page.first]) {continue;}
		visited[page.first] = true;
		if (adj[page.first].size() == 0) { shortestPath = min(page.second, shortestPath); continue;}
		for (int nextPage : adj[page.first]) {
			if (!visited[nextPage]) {
				current.push({nextPage, page.second+1});
			}
		}
	}
	bool allVisited = true;
	loop(n) {if (!visited[i]) {allVisited = false;}}
	if (allVisited) {cout << "Y" << endl;}
	else {cout << "N" << endl;}
	cout << shortestPath << endl;
	return 0;
}
