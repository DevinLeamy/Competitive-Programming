#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> values;
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {cin >> v; values.push_back(v);}
	for (int i = 0; i < n; i++) {
		int current = i;
		for (int j = i+1; j < n; j++) {
			if (values[j] < values[current]) {
				current = j;
			}
		}
		int temp = values[i];
		values[i] = values[current];
		values[current] = temp;
	}
	for (int val : values) {
		cout << val << endl;
	}
}
