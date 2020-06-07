#include <iostream>
#include <vector>

using namespace std;

int main(){
   string top, bottom;
   cin >> top >> bottom;
   int N = top.length();
   vector< vector<bool> > isTaken;
   for (int i = 0; i < 2; i++) {
      isTaken.push_back( vector<bool>() );
   }
   for (int i = 0; i < N; i++) {
      isTaken[0].push_back((top[i] == 'X'));
      isTaken[1].push_back((bottom[i] == 'X'));
   }
   int count = 0;
   vector<bool> full;
   full.push_back(true);
   full.push_back(true);
   for (int i = 0; i < N; i++) {
      if (!full[0] && !full[1]){
         if (!isTaken[0][i]) {
            count++;
            full[0] = true;
             full[1] = isTaken[1][i];
         } else if (!isTaken[1][i]) {
            count++;
             full[0] = isTaken[0][i];
            full[1] = true;
         } else {
             full[0] = isTaken[0][i];
             full[1] = isTaken[1][i];
         }
      } else if (!isTaken[0][i] && !isTaken[1][i]) {
         if (!full[0] || !full[1]) {
            count++;
            full[0] = true;
            full[1] = true;
         } else {
            full[0] = false;
            full[1] = false;
         }
      } else {
         full[0] = isTaken[0][i];
         full[1] = isTaken[1][i];
      }
   }
   cout << count << endl;

   return 0;
}
