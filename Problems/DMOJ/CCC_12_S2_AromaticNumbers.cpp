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


vector<pair<char, int>> ties = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
int getR(char value) {loopX(7) {if (value == ties[i].first) {return ties[i].second;}}return -1;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int lastBase = 2147483647; int total = 0; string num; cin >> num;
	int lastValue = -1;
	for (int i = 0; i < num.length(); i += 2) {
		int A = num[i] - '0'; int R = getR(num[i+1]);
		total += A*R;
		if (R > lastBase) {
			total -= lastValue*2;
			
		};
		lastValue = A * R;
		lastBase = R;
	}
	cout << total << endl;
	return 0;
}
