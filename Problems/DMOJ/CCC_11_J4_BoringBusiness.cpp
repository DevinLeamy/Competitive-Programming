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

bool safe[12][12];
bool go(int, int, int);
int row = -5; int col = -1;
set<PI> visited;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string c; int mag;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			safe[i][j] = true;
		}
	}
	safe[0][3] = false; safe[1][3] = false; safe[2][3] = false; safe[2][4] = false;
	safe[2][5] = false; safe[2][6] = false; safe[3][6] = false; safe[4][6] = false;
	safe[4][7] = false; safe[4][8] = false; safe[3][8] = false; safe[2][8] = false;
	safe[2][9] = false; safe[2][10] = false; safe[3][10] = false; safe[4][10] = false;
	safe[5][10] = false; safe[6][10] = false; safe[6][9] = false; safe[6][8] = false;
	safe[6][7] = false; safe[6][6] = false; safe[6][5] = false; safe[6][4] = false;
	safe[6][3] = false; safe[6][2] = false; safe[5][2] = false; safe[4][2] = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (!safe[i][j]) {visited.insert({-1*(i+1), j-3});}
		}
	}
	while (true) {
		cin >> c >> mag;
		bool safeD;
		if (c == "l"){
			safeD = go(0, -1, mag);
		} else if (c == "r") {
			safeD = go(0, 1, mag);
		} else if (c == "d") {
			safeD = go(-1, 0, mag);
		} else if (c == "u") {
			safeD = go(1, 0, mag);
		} else {break;}
		cout << col << " " << row << ((safeD)? " safe" : " DANGER") << endl;
		if (!safeD) {break;}
	}
	return 0;
}
bool go(int dR, int dC, int mag) {
	bool intersect = false;
	while (mag > 0) {
		row += dR; col += dC;
		mag--;
		for (PI loc : visited) {if (loc.first == row && loc.second == col) {intersect = true;}}
		visited.insert({row, col});
	}
	return !intersect;
}
