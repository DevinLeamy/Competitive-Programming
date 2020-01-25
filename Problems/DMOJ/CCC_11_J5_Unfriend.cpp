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
	int n, x; cin >> n;
	vector<int> friends = {1, 1, 1, 1, 1, 1};
	for (int i = 0; i < n-1; i++) {
		cin >> x; friends[x-1] *= (friends[i] + 1);
	}
	cout << friends[n-1] << endl;
	return 0;
}
