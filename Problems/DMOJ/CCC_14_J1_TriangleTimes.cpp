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
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180) {cout << "Error" << endl;}
	else if (a == b && b == c) {cout << "Equilateral" << endl;}
	else if (a != b && b != c && a != c) {cout << "Scalene" << endl;}
	else {cout << "Isosceles" << endl;}
	return 0;
}
