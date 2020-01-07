#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int negativeValues[100001];
int positiveValues[100001];
int main() {
    int N, a;
    cin >> N;
    int maximum = -1;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a >= 0) {
            positiveValues[a]++;
            maximum = max(positiveValues[a], maximum);
        } else {
            negativeValues[abs(a)]++;
            maximum = max(negativeValues[abs(a)], maximum);
        }
    }
    vector<int> output;
    string outputString = "";
    for (int i = 0; i < 100001; i++) {
        if (positiveValues[i] == maximum) {
            output.push_back(i);
        } else if (negativeValues[i] == maximum) {
            output.push_back(i * -1);
        }
    }
    sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++) {
        outputString += to_string(output[i]) + " ";
    }
    
    cout << outputString << endl;
    
    
    return 0;
}
