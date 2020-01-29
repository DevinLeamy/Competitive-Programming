#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> values;
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {cin >> v; values.push_back(v);}
	for (int i = 0; i < n; i++) {
		int current = i;
		while (values[current] <= values[current-1] && current != 0) {
			int temp = values[current];
			values[current] = values[current-1];
			values[current-1] = temp;
			current--;
		}
		
	}
	for (int val : values) {
		cout << val << endl;
	}
}
