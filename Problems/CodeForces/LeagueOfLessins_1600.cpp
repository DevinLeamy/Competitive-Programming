#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;

int nums[100000-2][3];
vector<vector<int>> finder(100000);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a;
	cin >> n;
	int count[100000];
	int perm[100000];
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a;
			nums[i][j] = a-1;
			count[a-1]++;
			finder[a-1].push_back(i);
		}
	}
	
	copy(begin(count), end(count), begin(perm));
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (count[i] == 1) {
			cur = i;
			break;
		}
	}
	
	for (int i = 0; i < n-3; i++) {
		int nCur = -1;
		int index = finder[cur][0];
		cout << cur + 1 << " ";
		for (int j = 0; j < 3; j++) {
			int num = nums[index][j];
			count[num]--;
			if (count[num] == 1) {
				nCur = num;
			}
			finder[num].erase(find(finder[num].begin(), finder[num].end(), index));
		}
		cur = nCur;
	}
	
	int lastThree[3] = {-1, -1, -1};
	for (int i = 0; i < 3; i++) {
		if (perm[nums[finder[cur][0]][i]] == 3) {
			lastThree[0] = nums[finder[cur][0]][i];
		}
		if (perm[nums[finder[cur][0]][i]] == 2) {
			lastThree[1] = nums[finder[cur][0]][i];
		}
		if (perm[nums[finder[cur][0]][i]] == 1) {
			lastThree[2] = nums[finder[cur][0]][i];
		}
	}
	cout << lastThree[0] + 1 << " " << lastThree[1] + 1 << " " << lastThree[2] + 1;
	return 0;
}

