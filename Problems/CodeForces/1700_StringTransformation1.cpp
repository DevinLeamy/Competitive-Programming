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
	int t; cin >> t;
	loop(t) {
		int n; cin >> n;
		string a, b; cin >> a >> b;
		bool flag = true;
		vector<vector<bool>> letters;
		for (int i = 0; i < 20; i++)
			letters.pb(vector<bool>(20));
		
		for (int i = 0; i < n; i++) {
			int indexA = a[i] - 'a';
			int indexB = b[i] - 'a';
			if (indexA == indexB) continue;
			if (indexA > indexB) {
				flag = false;
				break;
			}
			letters[indexA][indexB] = true;
		}
		int ans = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (letters[i][j]) {
					ans++;
					for (int k = j+1; k < 20; k++) {
						if (letters[j][k] || letters[i][k]) {
							letters[j][k] = true;
						}
					}
					break;
				}
				
			}
		}
		cout << (!flag? -1 : ans) << endl;
	}
	return 0;
}
