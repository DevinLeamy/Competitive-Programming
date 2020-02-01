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
	int a = 0; string result;
	loop(6) {
		cin >> result; a += (result == "W")? 1 : 0;
	}
	if (a >= 5) {cout << "1" << endl;}
	else if (a >= 3) {cout << "2" << endl;}
	else if (a >= 1) {cout << "3" << endl;}
	else {cout << "-1" << endl;}
	return 0;
}
