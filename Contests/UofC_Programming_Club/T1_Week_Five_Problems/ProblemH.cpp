#include <iostream>
#include <vector>

using namespace std;
class DisjointSet {
      public:
      vector<int> depth;
      vector<int> parents;
      vector<int> size;
      int N;
      DisjointSet(int n) {
         N = n;
         for (int i = 0; i < N; i++) {
            depth.push_back(0);
            parents.push_back(i);
            size.push_back(1);
         }
      }
      int findSet(int x) {
         if (parents[x] != x) {
            parents[x] = findSet(parents[x]);
         }
         return parents[x];
      }
      int unionSets(int x, int y) {
         int xRep = findSet(x);
         int yRep = findSet(y);
         if (xRep == yRep) {
            return xRep;
         }
         int temp = size[xRep];
         size[xRep] += size[yRep];
         size[yRep] += temp;
         if (depth[xRep] > depth[yRep]) {
            parents[yRep] = xRep;
            return xRep;
         } else if (depth[yRep] > depth[xRep]) {
            parents[xRep] = yRep;
            return yRep;
         } else {
            depth[xRep] += 1;
            parents[yRep] = xRep;
            return xRep;
         }
      }
};
int main() {
   int N, L, A, B, R;
   cin >> N >> L;
   DisjointSet groups = DisjointSet(L);
   for (int i = 0; i < N; i++) {
      cin >> A >> B;
      A--;
      B--;
      R = groups.unionSets(A, B);
      if (groups.size[R] <= 0) {
         cout << "SMECE" << endl;
      } else {
         groups.size[R]--;
         cout << "LADICA" << endl;
      }
   }
   return 0;
}
