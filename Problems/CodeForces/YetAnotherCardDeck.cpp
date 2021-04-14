#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
#define view(h) cout<<"DEBUG: " << h << endl
using namespace std;
char _;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int n, q; cin >> n >> q;
	vector<int> cards(n);
	vector<int> cnts(55, -1);
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	for (int i = 0; i < n; i++) {
		if (cnts[cards[i]] == -1)
			cnts[cards[i]] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int v; cin >> v;
		cout << cnts[v] + 1 << " ";
		for (int j = 1; j <= 50; j++) {
			if (j == v || cnts[j] == -1)
				continue;
			if (cnts[v] > cnts[j])
				cnts[j]++;
		}
		cnts[v] = 0;
	}
	
	return 0;
}
