#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
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
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	vector<double> sides(6);
	for (int i = 0; i < 6; i++)
		cin >> sides[i];
	ll base = sides[2] + sides[3] + sides[4];
	ll cnt = base * base;
	cnt -= sides[0] * sides[0];
	cnt -= sides[2] * sides[2];
	cnt -= sides[4] * sides[4];
	cout << cnt << endl;
	return 0;
}
