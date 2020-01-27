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

int frequency[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, r; cin >> n; int highest = -1 ; int lowest = -1;
	loopX(n) { cin >> r; frequency[r]++; highest = max(highest, frequency[r]); }
	PI highT = {-1, -1}; PI lowT = {-1, -1};
	loopX(1001) {
		if (frequency[i] == highest && highT.first == -1) {highT.first = i;}
		else if (frequency[i] == highest && highT.first != -1) {highT.second = i;}
		else if (frequency[i] != highest) {lowest = max(lowest, frequency[i]);}
	}
	if (highT.second != -1) { cout << abs(highT.first - highT.second) << endl; return 0;}
	loopX(1001) {
		if (frequency[i] == lowest && lowT.first == -1) {lowT.first = i;}
		else if (frequency[i] == lowest && lowT.first != -1) {lowT.second = i;}
	}
	if (lowT.second == -1) {cout << abs(highT.first - lowT.first) << endl;}
	else { cout << max( abs( highT.first - lowT.first ), abs( highT.first - lowT.second ) ) << endl;}
	return 0;
}
