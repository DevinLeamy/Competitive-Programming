#include <iostream>
using namespace std;

int main()
{
   int Q;
   cin >> Q;
   for (int i = 0; i < Q; i++)
   {
      long long H, N, P;
      cin >> H >> N;
      int count = 0;
      int current = H-1;
      int nextPlatform = -1;
      for (int j = 0; j < N; j++)
      {
         cin >> P;
         P--;
         if (P < nextPlatform)
         {
             count++;
             current = P+1;
             nextPlatform = -1;
         } else if (P == nextPlatform)
         {
             current = P;
             nextPlatform = -1;
         } else if (P < current-1)
         {
             current = P+1;
         }
         if (P == current-1 && nextPlatform == -1)
         {
             nextPlatform = current-2;
         }
      }
      if (nextPlatform > -1)
      {
          count++;
      }
      cout << count << endl;
   }
   return 0;
}
