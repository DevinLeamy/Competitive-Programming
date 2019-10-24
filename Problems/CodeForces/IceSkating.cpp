#include <iostream>
#include <vector>

using namespace std;
int main() {
   int N, X, Y;
   cin >> N;
   vector< vector<int> > P;
   for (int i = 0; i < N; i++) {
      cin >> X >> Y;
      P.push_back(vector<int>());
      P[i].push_back(X);
      P[i].push_back(Y);
   }
   vector< vector<int> > group;
   int current = 0;
   int count = 0;
   bool grouped[N+1];
    for (int i = 0; i <= N; i++) {
        grouped[i] = false;
    }
   while (true) {
      bool found = true;
      int temp = count;
      while (found) {
         vector<int> notGrouped;
         found = false;
         for (int i = 0; i < N; i++) {
            if (!grouped[i]){
               int H = group.size();
               for (int j = 0; j < H; j++) {
                  if ((P[i][0] == group[j][0]) || (P[i][1] == group[j][1]))  {
                     group.push_back(P[i]);
                     found = true;
                     grouped[i] = true;
                     break;
                  }
               }
            }
            if (!found && !grouped[i]) {
               if (notGrouped.size() == 0) {
                  notGrouped.push_back(P[i][0]);
                  notGrouped.push_back(P[i][1]);
                  notGrouped.push_back(i);
               }
            }
         }
         if (!found) {
            if (notGrouped.size() == 3) {
               group.clear();
               group.push_back(notGrouped);
               grouped[notGrouped[2]] = true;
               count++;
            }
         }
      }
      if (count == temp) {
         break;
      }
   }
   cout << (count-1) << endl;
   return 0;
}
