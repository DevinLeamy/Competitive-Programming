#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)

char _;
using namespace std;
int N[2001];
int H[4002];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int biggest = 0;
	int n, l; scan(n);
	loop(n) { scan(l); N[l]++; biggest = max(biggest, l);}
	int currentLongest = 0; int count = 0;
	for (int i = 1; i <= biggest; i++) { if (N[i] == 0) {continue;}
		for (int j = i; j <= biggest; j++) { if (N[j] == 0) {continue;}
			if (j == i) {
				H[i+j] += (N[i] + N[j])/4;
				continue;
			}
			H[i+j] += (min(N[i], N[j]));
		}
	}
	loop(biggest*2+1) {
		if (H[i] > currentLongest) {
			currentLongest = H[i];
			count = 1;
		} else if (H[i] == currentLongest) {
			count++;
		}
	}
	cout << currentLongest << " " << count << endl;
	return 0;
}
