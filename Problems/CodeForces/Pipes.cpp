#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int Q;
   cin >> Q;
   for (int i = 0; i < Q; i++)
   {
      long long N;
      vector< vector<bool> > dp;  // dp[i][j] -> can water reach the jth pos in the ith row
      cin >> N;
      string row1, row2;
      cin >> row1 >> row2;
      string rows[2];
      rows[0] = row1;
      rows[1] = row2;
      int current[3];
      current[0] = 0;
      current[1] = 0;
      current[2] = 0;
      bool good = true;
      for (int i = 0; i < N; i++)
      {
         char character = rows[current[0]][current[1]];
         if (character == '1' || character == '2')
         {
            current[1]++;
         } else {
            if (current[2] != current[0])
            {
               current[1]++;
               current[2] = current[0];
            } else {
               i--;
               current[2] = current[0];
               current[0] = (current[0] == 0)? 1 : 0;
               char newCharacter = rows[current[0]][current[1]];
               if (newCharacter == '1' || newCharacter == '2')
               {
                  good = false;
                  break;
               }
            }
         }
      }
      char character = rows[current[0]][current[1]];
      if (current[0] == 0 || !good)
      {
         cout << "NO" << endl;
      } else {
         if (character == '1' || character == '2')
         {
            cout << "YES" << endl;
         } else if (current[2] == current[0])
         {
            cout << "YES" << endl;
         } else {
            cout << "NO" << endl;
         }
      }




   }
   return 0;
}
