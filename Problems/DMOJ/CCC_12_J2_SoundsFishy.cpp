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
	int reading; bool fishRising = true, fishDiving = true, constant = true; int last; cin >> last;
	for (int i = 0; i < 3; i++) {
		cin >> reading;
		if (reading > last) {fishDiving = false; constant = false;}
		else if (reading < last) {fishRising = false; constant = false;}
		else if (reading == last) {fishRising = false; fishDiving = false;}
		last = reading;
	}
	if (fishRising) {cout << "Fish Rising" << endl;}
	else if (fishDiving) {cout << "Fish Diving" << endl;}
	else if (constant) {cout << "Fish At Constant Depth" << endl;}
	else {cout << "No Fish" << endl;}
	
	return 0;
}
