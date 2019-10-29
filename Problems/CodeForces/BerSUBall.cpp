#include <iostream>
#include <vector>
using namespace std;
 
vector<int> boys(101);
vector<int> girls(101);
int main() {
    int n, m, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        boys[a]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b;
        girls[b]++;
    }
    int count = 0;
    for (int i = 1; i < 101; i++) {
        int boy = boys[i];
        int girl = girls[i];
        if (boy >= girl) {
            count += girl;
            boy -= girl;
            count += min(girls[i+1], boy);
            girls[i+1] -= min(girls[i+1], boy);
        } else {
            count += boy;
            girl -= boy;
            count += min(boys[i+1], girl);
            boys[i+1] -= min(boys[i+1], girl);
        }
    }
    cout << count << endl;
    return 0;
}
