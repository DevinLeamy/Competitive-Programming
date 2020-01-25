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
	int a, b; cin >> a >> b;
	int count = 2;
	while (true) {
		int temp = a-b; count++;
		if (temp > b) {break;}
		a = b; b = temp;
	}
	cout << count << endl;
	return 0;
}
