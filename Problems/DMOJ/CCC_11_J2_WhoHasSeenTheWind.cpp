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

ll funck(int, int);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, m; cin >> h >> m;
	for (int i = 1; i <= m; i++) {
		if (funck(h, i) <= 0) {
			cout << "The balloon first touches ground at hour:" << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << "The balloon does not touch ground in the given time." << endl;
	return 0;
}
ll funck(int h, int t) {
	return (-6 * pow(t, 4) + h * pow(t, 3) + 2 * (pow(t, 2)) + t);
}
