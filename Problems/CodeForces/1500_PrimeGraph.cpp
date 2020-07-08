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


bool isPrime(int n) {
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int nextPrime(int cur) {
	while(1) {
		if (isPrime(cur)) {
			break;
		}
		cur++;
	}
	return cur;
}

bool connected[1000][1000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> edges;
	vector<int> count(n);
	for (int i = 1; i <= n; i++) {
		int next = (i + 1);
		if (next == n + 1) {
			next = 1;
		}
		edges.pb({i, next});
		count[i-1]++;
		count[next-1]++;
		connected[i-1][next-1] = true;
		connected[next-1][i-1] = true;
	}
	int nextPrime = ::nextPrime(n);
	int toAdd = nextPrime - n;
	for (int i = 0; i < n; i++) {
		if (toAdd == 0) break;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (toAdd == 0) break;
			if (isPrime(count[i] + 1) && isPrime(count[j] + 1) && !connected[i][j]) {
				connected[i][j] = true;
				connected[j][i] = true;
				count[i]++;
				count[j]++;
				edges.pb({i + 1, j + 1});
				toAdd--;
			}
		}
	}
	
	cout << edges.size() << "\n";
	for (pair<int, int> edge: edges) {
		cout << edge.first << " " << edge.second << "\n";
	}
	return 0;
}
