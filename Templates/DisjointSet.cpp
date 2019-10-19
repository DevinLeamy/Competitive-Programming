#include <vector>

using namespace std;
class DisjointSet {
      public:
      vector<int> depth;
      vector<int> parents;
      int N;
      DisjointSet(int n) {
         N = n;
         for (int i = 0; i < N; i++) {
            depth.push_back(0);
            parents.push_back(i);
         }
      }
      int findSet(int x) {
         if (parents[x] != x) {
            parents[x] = findSet(parents[x]);
         }
         return parents[x];
      }
      void unionSets(int x, int y) {
         int xRep = findSet(x);
         int yRep = findSet(y);
         if (xRep == yRep) {
            return;
         }
         if (depth[xRep] > depth[yRep]) {
            parents[yRep] = xRep;
         } else if (depth[yRep] > depth[xRep]) {
            parents[xRep] = yRep;
         } else {
            depth[xRep] += 1;
            parents[yRep] = xRep;
         }
      }
};
