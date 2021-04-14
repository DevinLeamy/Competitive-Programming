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
using namespace std;

vector<int> par(100001);

int n, m;
void init_dsu() {
	for (int i = 0; i < n; i++)
		par[i] = i;
}

int find_par(int n) {
	if (par[n] == n)
		return n;
	par[n] = find_par(par[n]);
	return par[n];
}

void union_set(int a, int b) {
	int par_a = find_par(a);
	int par_b = find_par(b);
	if (par_a != par_b) {
		par[par_a] = par_b;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	cin >> n >> m;
	init_dsu();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		union_set(a, b);
	}
	vector<PI> output;
	for (int i = 1; i < n; i++) {
		if (find_par(i) != find_par(0)) {
			output.pb(make_pair(i, 0));
			union_set(i, 0);
		}
	}
	cout << output.size() << endl;
	for (PI val : output) {
		cout << val.first + 1 << " " << val.second + 1 << endl;
	}
	return 0;
}
