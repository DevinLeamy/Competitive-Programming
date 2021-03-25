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
	vector<int> yang(3), monster(3), costs(3); // HP, ATK, DEF
	
	for (int i = 0; i < 3; i++)
		cin >> yang[i];
	for (int i = 0; i < 3; i++)
		cin >> monster[i];
	for (int i = 0; i < 3; i++)
		cin >> costs[i];
	
	int ans = 0;
	int rem_a = min(yang[1], monster[2]);
	yang[1] -= rem_a;
	monster[2] -= rem_a;

	int a_inc = (yang[1] == 0)? monster[2] + 1 : 0;
	
	ans += a_inc * costs[1];
	yang[1] += a_inc;
	
	rem_a = min(yang[1], monster[2]);
	yang[1] -= rem_a;
	monster[2] -= rem_a;

	if (monster[1] == 0) { // does no damage
		cout << ans << endl;
		return 0;
	}
	// Does at least 1 damage
	int min_inc = INF;
	for (int i = 1; i <= monster[0]; i++) {
		int damage = i * (monster[1] - yang[2]);
		int atk = ceil((double) monster[0] / (double) i);
		int cost = 0;
		cost += max(0, (atk - yang[1])) * costs[1];
		int h_inc = max(0, (damage - yang[0] + 1));
		int d_inc = max(0, (int) ceil( (double) (damage - yang[0]) / (double) i));
		
		if (yang[0] - max(0, damage - d_inc * i) == 0) {
			d_inc++;
		}
		cost += min(h_inc * costs[0], d_inc * costs[2]);
		min_inc = min(min_inc, cost);
	}
	ans += min_inc;
	printf("%d\n", ans);
	return 0;
}
