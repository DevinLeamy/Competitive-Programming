#include <iostream>
#include <vector>
using namespace std;


int main() {
    int q, n, p;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n;
        vector<int> goTo(n);
        
        for (int j = 0; j < n; j++) {
            cin >> p;
            goTo[j] = p-1;
        }
        vector<bool> counted(n);
        vector<int> ans(n);
        for (int j = 0; j < n; j++) {
            if (!counted[j]) {
                vector<int> set;
                set.push_back(j);
                int cycle = 0;
                while (!counted[j]) {
                    set.push_back(j);
                    counted[j] = true;
                    j = goTo[j];
                    cycle++;
                }
                for (int num : set) {
                    ans[num] = cycle;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
