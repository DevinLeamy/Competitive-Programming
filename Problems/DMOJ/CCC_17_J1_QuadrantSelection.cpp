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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y; cin >> x >> y;
	if (x < 0 && y < 0) {cout << "3" << endl;}
	else if (x < 0) {cout << "2" << endl;}
	else if (y < 0) {cout << "4" << endl;}
	else {cout << "1" << endl;}
	return 0;
}
