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
	int longest = 1; string word; cin >> word;
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j <= word.length()-i; j++) {
			string sub = word.substr(i, j); string reverseMe = sub;
			reverse(reverseMe.begin(), reverseMe.end());
			if (sub == reverseMe) {longest = max(longest, (int)sub.length());}
		}
	}
	cout << longest << endl;
	return 0;
}
