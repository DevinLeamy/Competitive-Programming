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
	int n, q; cin >> n >> q;
	int r1, c1, r2, c2;
	vector<int> row(n);
	vector<int> col(n);
	vector<int> rowId(n);
	vector<int> colId(n);
	for (int i = 0; i < n; i++) { cin >> row[i]; }
	for (int i = 0; i < n; i++) { cin >> col[i]; }
	for (int i = 1; i < n; i++) {
		if (row[i] % 2 == row[i-1] % 2) { rowId[i] = rowId[i - 1]; }
		else { rowId[i] = rowId[i - 1] + 1; }
		if (col[i] % 2 == col[i-1] % 2) { colId[i] = colId[i - 1]; }
		else { colId[i] = colId[i - 1] + 1; }
	}
	for (int i = 0; i < q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		if (rowId[r1] == rowId[r2] && colId[c1] == colId[c2]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
