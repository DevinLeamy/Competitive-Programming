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
	const string troy = "TroyMartian", vlad = "VladSaturnian", graeme = "GraemeMercurian";
	int ant, eyes; cin >> ant >> eyes;
	if (ant >= 3 && eyes <= 4) {cout << troy << endl;}
	if (ant <= 6 && eyes >= 2) {cout << vlad << endl;}
	if (ant <= 2 && eyes <= 3 ) {cout << graeme << endl;}
	return 0;
}
