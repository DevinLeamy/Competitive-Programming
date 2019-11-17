#include <iostream>
#include <vector>

using namespace std;

int sweets[200001];
int main() {
    int n, m, a;
    cin >> n >> m;
    vector<int> sweets;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sweets.push_back(a);
    }
    sort(sweets.begin(), sweets.end());
    string output = "";
    vector<long long> totals;
    totals.push_back(sweets[0]);
    output += to_string(sweets[0]); output += " ";
    long long currentSum = 0;
    vector<long long> presum;
    presum.push_back(sweets[0]);
    for (int i = 0; i < m-1; i++) {
        presum.push_back(sweets[i+1] + presum[i]);
        totals.push_back(sweets[i+1] + totals[i]);
        output += to_string(totals[i+1]); output += " ";
        currentSum += sweets[i+1];
    }
    currentSum += sweets[m];
    for (int i = m; i < n; i++) {
        int remainder = i%m;
        output += to_string(totals[remainder] + presum[i-m] + currentSum); output += " ";
        totals[remainder] = totals[remainder] + presum[i-m] + currentSum;
        presum.push_back(presum[i-1] + sweets[i]);
        currentSum -= sweets[i-(m-1)];
        currentSum += sweets[i+1];
    }
    cout << output << endl;
    return 0;
}
