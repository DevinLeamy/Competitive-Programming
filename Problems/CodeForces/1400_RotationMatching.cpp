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

int dist[200001];
int a[200001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		a[v] = i;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> v;
		int index = a[v];
		if (index >= i) {
			dist[index-i]++;
			max = std::max(max, dist[index-i]);
		} else {
			dist[(n+(index-i))]++;
			max = std::max(max, dist[(n+(index-i))]);
		}
	}
	cout << max << endl;
	return 0;
}
