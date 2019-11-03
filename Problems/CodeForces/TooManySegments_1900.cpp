#include <iostream>
#include <vector>

using namespace std;

int line[201], n, k, l, r, minimum = 201, maximum = 0;
vector<int> output;
vector<pair<int,int>> segments;
string outputString;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        l--; r--;
        minimum = min(minimum, l); maximum = max(maximum, r);
        for (int j = l; j <= r;j++) {
            line[j]++;
        }
        segments.push_back({l, r});
    }
    int current = minimum;
    while (current != maximum+1) {
        while (line[current] > k) {
            int longest = -1;
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (segments[i].first <= current && segments[i].second >= current) {
                    if (segments[i].second - current > longest) {
                        longest = segments[i].second - current;
                        index = i;
                    }
                }
            }
            segments[index].first = 1000;
            for (int i = current; i <= current+longest; i++) {
                line[i] = max(line[i]-1, 0);
            }
            output.push_back((index+1));
        }
        current++;
    }
    for (int num : output) {
        outputString += to_string(num); outputString += " ";
    }
    cout << output.size() << endl;
    cout << outputString.substr(0, outputString.length()-1) << endl;
    
    return 0;
}
