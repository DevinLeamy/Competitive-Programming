#include <iostream>
#include <vector>
using namespace std;

int main() {
   int C, R;
   cin >> C >> R;
   string S;
   int count = 1;
   while (C != 0 && R != 0) {
      vector< vector<char> > room;
      int startX = -1;
      int startY = -1;
      int currentD = -1; //-1 = right, 1 = left, -2 = up, 2 = down
      for (int i = 0; i < R; i++) {
         room.push_back(vector<char>());
         cin >> S;
         for (int j = 0; j < C; j++) {
            room[i].push_back(S[j]);
            if (S[j] == '*') {
               startX = i;
               startY = j;
            }
         }
      }
      if (startX == C-1) {
         currentD = 1;
      } else if (startX == 0) {
         currentD = -1;
      } else if (startY == 0) {
         currentD = 2;
      } else {
         currentD = -2;
      }
      bool found = false;
      // cout << "dsfsd" << endl;
      while (!found) {
         switch (currentD) {
            case -1 :
               startX++;
               if (room[startX][startY] == 'x') {
                  room[startX][startY] = '&';
                  found = true;
               } else if (room[startX][startY] == '/') {
                  currentD = -2;
               } else if (room[startX][startY] == '\\') {
                  currentD = 2;
               }
               break;
            case 1:
               startX--;
               if (room[startX][startY] == 'x') {
                  room[startX][startY] = '&';
                  found = true;
               } else if (room[startX][startY] == '/') {
                  currentD = 2;
               } else if (room[startX][startY] == '\\') {
                  currentD = -2;
               }
               break;
            case 2 :
               startY++;
               if (room[startX][startY] == 'x') {
                  room[startX][startY] = '&';
                  found = true;
               } else if (room[startX][startY] == '/') {
                  currentD = 1;
               } else if (room[startX][startY] == '\\') {
                  currentD = -1;
               }
               break;
            case -2 :
               startY--;
               if (room[startX][startY] == 'x') {
                  room[startX][startY] = '&';
                  found = true;
               } else if (room[startX][startY] == '/') {
                  currentD = -1;
               } else if (room[startX][startY] == '\\') {
                  currentD = 1;
               }
               break;
         }

      }
      cout << "HOUSE " << count << endl;
      for (int i = 0; i < R; i++) {
         string row = "";
         for (int j = 0; j < C; j++) {
            row += room[i][j];
         }
         cout << row << endl;
      }
      count++;
      cin >> R >> C;
   }
   return 0;
}
