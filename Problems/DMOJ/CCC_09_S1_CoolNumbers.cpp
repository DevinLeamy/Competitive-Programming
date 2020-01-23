#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	int count = 0;
	int start = (int) cbrt(x);
	int end = (int)cbrt(y) + 1;
	for (int i = start; i <= end; i++) {
		ll value = i * i * i;
		if (value > y) {break;}
		else if (value < x) {continue;}
		if ((int)sqrt(value) == sqrt(value)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
