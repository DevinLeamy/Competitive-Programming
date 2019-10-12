#include <iostream>
#include <vector>

using namespace std;

long long getOutput(long long count);
long long MOD = 1000000007;
int main()
{
   int H, W, R, C;
   cin >> H >> W;
   vector< vector<int> > filled;
   for (int i = 0; i <= H; i++)
   {
      filled.push_back(vector<int>(W+1));
   }
   bool good = true;
   for (int i = 0; i <= H; i++)
   {
      for (int j = 0; j <= W; j++)
      {
         filled[i][j] = 0;
      }
   }
   for (int i = 0; i < H; i++)
   {
      cin >> R;
       int current = 0;
       if (filled[i][R] == 1)
       {
           good = false;
           break;
       }
       while (current < W && current < R)
       {
           if (filled[i][current] == -1)
           {
               good = false;
               break;
           }
          filled[i][current] = 1;
          current++;
       }
       filled[i][R] = -1;
   }
   for (int i = 0; i < W; i++)
   {
      cin >> C;
      int current = 0;
      if (filled[C][i] == 1)
      {
          good = false;
          break;
      }
      while (current < H && current < C)
      {
          if (filled[current][i] == -1)
          {
              good = false;
              break;
          }
         filled[current][i] = 1;
         current++;
      }
      filled[C][i] = -1;
   }
   long long count = 0;
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (!filled[i][j])
         {
            count++;
         }
      }
   }
   if (good)
   {
       cout << getOutput(count) << endl;
   } else {
       cout << 0 << endl;
   }
   return 0;
}
long long getOutput(long long count)
{
   long long current = 1;
   for (int i = 0; i < count; i++)
   {
      current *= 2;
      current = current % MOD;
   }
   return current;
}
