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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(10);
	int k; cin >> k;
	int add = (int) pow(2, (int) log2(k)+1);
	vector<vector<int>> mtx = {
		{k + add, k,   k,       0},
		{add,     0,   k,       0},
		{add,     add, k + add, k}
	};
	printf("3 4\n");
	for (vector<int> row : mtx) {
		for (int val : row) {
			printf("%i ", val);
		}
		printf("\n");
	}
	return 0;
}
