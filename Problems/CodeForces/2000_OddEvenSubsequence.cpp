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

vector<ll> vals(200001);
vector<ll> sorted(200001);
int n, k;

bool func(ll index) {
	//Can you find a valid subsequence were all the element
	//on even or all the elements on odd are smaller than or equal to sorted[index]
	ll max = sorted[index];
	for (int z = 0; z < 2; z++) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (count % 2 == z && vals[i] <= max) {
				count++;
			} else if (count % 2 != z) {
				count++;
			}
		}
		if (count >= k) {
			return true;
		}
	}
	return false;
}

ll binarySearch(ll left, ll right) {
	if (left >= right) {
		return left;
	}
	ll mid = (left + right)/2;
	if (func(mid)) {
		return binarySearch(left, mid);
	} else {
		return binarySearch(mid+1, right);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> vals[i]; sorted[i] = vals[i]; }
	sort(sorted.begin(), sorted.begin()+n);
	cout << sorted[binarySearch(0, n-1)];
	return 0;
}
