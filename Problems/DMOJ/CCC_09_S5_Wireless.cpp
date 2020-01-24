// 7.5/15 Points 

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
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

bool isValid(int, int, int, int, int);
int getMin(int, int, int);
int r, c, k;
int main() {
	ios_base::sync_with_stdio(0);
	int h, g, rad, b, minL;
	cin >> r >> c >> k; int currentHigh = 0; int count = 0;
	vector< vector<int> > city;
	doH(r) {city.pb(vector<int>(c));fill(city[i].begin(), city[i].end(), 0);
		
	}
	for (int i = 0; i < k; i++) {
		cin >> h >> g >> rad >> b; h--; g--;
		for (int j = max(0, g-rad); j <= min(r, g + rad); j++) {
			minL = getMin(j, rad, g);
			for (int l = max(0, h-minL); l <= min(c, h+minL); l++) {
				if (isValid(g, h, j, l, rad)) {
					city[j][l] += b;
					if (currentHigh < city[j][l]) {count = 0; currentHigh = city[j][l];}
					if (city[j][l] == currentHigh) {count++;}
				}
			}
		}
	}
	cout << currentHigh << endl;
	cout << count << endl;
	return 0;
}
bool isValid(int row, int col, int rowI, int colI, int rad) {
	if (rowI < 0 || rowI >= r || colI < 0 || colI >= c) {return false;}
	int diffRow = abs(row-rowI);
	int diffCol = abs(col - colI);
	double value = sqrt( (diffCol * diffCol) + (diffRow * diffRow) );
	if (value > rad) {return false;}
	else {return true;}
}
int getMin(int row, int rad, int g) {
	int returnValue = sqrt( (rad*rad) - ( (g-row) * (g-row) ) );
	return returnValue;
}
