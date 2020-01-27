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
	int limit, speed; cin >> limit >> speed;
	int diff = speed - limit;
	if (diff >= 31) {cout << "You are speeding and your fine is $500." << endl;}
	else if (diff >= 21) {cout << "You are speeding and your fine is $270." << endl;}
	else if (diff >= 1) {cout << "You are speeding and your fine is $100." << endl;}
	else {cout << "Congratulations, you are within the speed limit!" << endl;}
	return 0;
}
