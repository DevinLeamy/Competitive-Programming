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
	int t, d, p; cin >> t >> d >> p; bool isTrue[3] = {false, false, false};
	if (t < -40) {isTrue[0] = true;}
	if (d >= 15) {isTrue[1] = true;}
	if (p > 50) {isTrue[2] = true;}
	int count = 0; loop(3) {if (isTrue[i]) {count++;}}
	if (count >= 2) {cout << "YES" << endl;}
	else {cout << "NO" << endl;}
	return 0;
}
