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
	int a, b, c, lim, count = 0;
	cin >> a >> b >> c >> lim;
	for (int i = 0; i <= lim/a; i++) {
		for (int j = 0; j <= lim/b; j++) {
			for (int z = 0; z <= lim/c; z++) {
				if (i * a + j*b + z*c <= lim && (i > 0 || j > 0 || z > 0)) {
					count++;
					cout << i << " Brown Trout, " << j << " Northern Pike, " << z << " Yellow Pickerel" << endl;
				}
			}
		}
	}
	cout << "Number of ways to catch fish: " << count << endl;
	return 0;
}
