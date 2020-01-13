#include <iostream>
#include <vector>

using namespace std;

int main() {
    int c, r, d, x, y, w, p;
    long long minWeight = 10000000;
    cin >> c >> r >> d;
    int count = d;
    vector< vector<pair<int, int> > > adj;
    bool visited[c];
    long long key[c];
    bool destinations[c];
    for (int i = 0; i < c; i++) {
        key[i] = -1;
        visited[i] = false;
        adj.push_back(vector<pair<int, int>>());
        destinations[i] = false;
    }
    for (int i = 0; i < r; i++) {
        cin >> x >> y >> w;
        adj[x-1].push_back(make_pair(y-1, w));
        adj[y-1].push_back(make_pair(x-1, w));
    }
    for (int i = 0; i < d; i++) {
        cin >> p;
        destinations[(p-1)] = true;
    }
    key[0] = 10e12;
    while (count > 0) {
        long long weight = -1;
        long long index = -1;
        for (int i = 0; i < c; i++) {
            if (!visited[i] && key[i] >= weight) {
                weight = key[i];
                index = i;
            }
        }
        visited[index] = true;
        if (destinations[index]) {
            count--;
        }
        minWeight = minWeight > weight ? weight : minWeight;
        for (pair<int, int> edge : adj[index]) {
            if (!visited[edge.first]) {
                if (edge.second > key[edge.first]) {
                    key[edge.first] = edge.second;
                }
            }
        }
    }
    cout << minWeight << endl;
    return 0;
}
