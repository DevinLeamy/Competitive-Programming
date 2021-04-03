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
char _;

void flush() {
	cout.flush();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n; cin >> n;
	int turns = 0;
	vector<vector<bool>> taken(n, vector<bool>(n));
	vector<vector<int>> val(n, vector<int>(n, 2));
	for (int i = 0; i < n; i++) {
		for (int j = i % 2; j < n; j += 2) {
			val[i][j] = 1;
		}
	}
	while (turns < n * n) {
		int a; cin >> a;
		PI pos = {0, 0};
		int color = -1;
		bool found = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (taken[i][j])
					continue;
				if (val[i][j] != a) {
					color = val[i][j];
					pos.first = i;
					pos.second = j;
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
		if (!found) {
			color = 3;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!taken[i][j]) {
						pos.first = i;
						pos.second = j;
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
		}
		taken[pos.first][pos.second] = true;
		cout << color << " " << pos.first + 1 << " " << pos.second + 1 << endl;
		flush();
		turns++;
	}
	return 0;
}
