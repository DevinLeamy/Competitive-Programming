#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> &vect, int low, int high) {
	if (high - low == 1) {
		return {vect[low]};
	}
	vector<int> output;
	int mid = (high + low)/2;
	vector<int> a = mergeSort(vect, low, mid);
	vector<int> b = mergeSort(vect, mid, high);
	int currentA = 0; int currentB = 0;
	while (currentA != a.size() || currentB != b.size()) {
		if (currentA == a.size()) {
			output.push_back(b[currentB]); currentB++;
		} else if (currentB == b.size()) {
			output.push_back(a[currentA]); currentA++;
		} else {
			if (a[currentA] < b[currentB]) {
				output.push_back(a[currentA]); currentA++;
			} else {
				output.push_back(b[currentB]); currentB++;
			}
		}
	}
	return output;
}
int main() {
	vector<int> values;
	int n, v; cin >> n;
	for (int i = 0; i < n; i++) {cin >> v; values.push_back(v);}
	values = mergeSort(values, 0, values.size());
	for (int val : values) {
		cout << val << endl;
	}
}
