#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int long_inc_sub(vector<int> &vals) {
	int n = (int) vals.size();
	vector<int> last(n, INF);
	int len = 1;
	last[0] = vals[0];
	
	for (int i = 1; i < n; i++) {
		int val = vals[i];
		if (val < last[0]) {
			// new smallest value
			last[0] = val;
		} else if (val > last[len - 1]) {
			// extends largest subsequence
			last[len] = val;
			len++;
		} else {
			int bound = (int) (upper_bound(last.begin(), last.end(), val) - last.begin());
			last[bound] = val;
		}
	}
	return len;
}

int main() {
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
    int long_inc = long_inc_sub(v);
    assert(long_inc == 6);
	return 0;
}
