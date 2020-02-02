#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string moves, comb; int m, p; vector<pair<string, int>> val;
	cin >> moves; cin >> m;
	loop(m) {
		cin >> comb >> p;
		val.pb({comb, p});
	}
	int currentPoints = moves.length();
	loop(moves.length()) {
		string currentBest = ""; int points = 0;
		for (pair<string, int> com : val) {
			string move = com.first;
			if (i + move.length() - 1 < moves.length() && moves.substr(i, move.length()) == move) {
				if (currentBest.length() < move.length()) {
					currentBest = move;
					points = com.second;
				}
			}
		}
		if (currentBest.length() == 0) {continue;}
		i += currentBest.length() - 1; currentPoints += points;
	}
	cout << currentPoints << endl;
	
	return 0;
}
