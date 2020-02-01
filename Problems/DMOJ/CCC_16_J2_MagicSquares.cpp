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
	vector<int> current = {0, 0, 0, 0}; int value; int sum = -1; bool magic = true;
	for (int i = 0; i < 4; i++) {
		int row = 0;
		for (int j = 0; j < 4; j++) {
			cin >> value;
			current[j] += value; row += value;
		}
		if (sum == -1) {sum = row;}
		else if (sum != row) {magic = false;}
	}
	loop(4) {
		if (current[i] != sum) {magic = false;}
	}
	if (magic) {cout << "magic" << endl;}
	else {cout << "not magic" << endl;}
	return 0;
}
