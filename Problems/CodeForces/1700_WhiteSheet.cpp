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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	//If either square is covering the whole sheet
	if (x1 >= x3 && x2 <= x4 && y1 >= y3 && y2 <= y4) { cout << "NO"; return 0; }
	else if (x1 >= x5 && x2 <= x6 && y1 >= y5 && y2 <= y6) { cout << "NO"; return 0; }
	
	//Check for complete rows covered by each square
	if (x1 >= x3 && x2 <= x4 && x1 >= x5 && x2 <= x6) {
		if (y1 >= y3 && y1 < y4) {
			y1 = y4;
		} else if (y2 <= y4 && y2 > y3) {
			y2 = y3;
		}
		if (y1 >= y5 && y2 <= y6) { cout << "NO"; return 0; }
	} else if (y1 >= y3 && y2 <= y4 && y1 >= y5 && y2 <= y6) {
		if (x1 >= x3 && x1 < x4) {
			x1 = x4;
		} else if (x2 <= x4 && x2 > x3) {
			x2 = x3;
		}
		if (x1 >= x5 && x2 <= x6) { cout << "NO"; return 0; }
	}
	cout << "YES";
	return 0;
}
