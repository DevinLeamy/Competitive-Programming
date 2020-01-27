#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loopX(h) for(int i = 0; i < h; i++)

using namespace std;


string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int S(int p, int k) {return 3*(p+1) + k;}
int pos(char c) {int current = 0; while (true) {if (c == alpha[current]) {return current;} current++;} return 0;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; string message, deco = ""; cin >> k >> message;
	loopX(message.length()) {
		int s = (pos(message[i]) - S(i, k));
		deco += (s < 0)? alpha[26 + s] : alpha[s];
	}
	cout << deco << endl;
	return 0;
}
