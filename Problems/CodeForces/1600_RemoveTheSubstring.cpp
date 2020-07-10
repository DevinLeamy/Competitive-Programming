#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#define INF 2147483647
#define LINF 9223372036854775807ll
#define PI pair<int, int>
#define PL pair<long long, long long>
#define ll long long
#define pb push_back
#define loop(h) while(h--)
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	int max = 0;
	for (int i = 0; i < a.length(); i++) {
		for (int j = i; j < a.length(); j++) {
			int index = 0;
			for (int k = 0; k < a.length(); k++) {
				if (k == i) {
					k = j;
					continue;
				}
				if (a[k] == b[index]) {
					index++;
					if (index == b.size()) {
						break;
					}
				}
			}
			if (index == b.size()) {
				max = std::max(max, j - i + 1);
			}
		}
	}
	cout << max << endl;
	return 0;
}
