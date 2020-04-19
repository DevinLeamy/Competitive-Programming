#include <stdio.h>

int main() {
        int t;
        scanf("%d", &t);
        for(int i = 0; i < t; ++i) {
                int left, right, down, up, x, y, x1, y1, x2, y2;
                scanf("%d%d%d%d", &left, &right, &down, &up);
                int dH = right - left;
                int dV = up - down;
                scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
                x += dH;
                y += dV;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                        if(x1 == x && x == x2 && (right > 0 || left > 0)) {
                                printf("No\n");
                        } else if(y1 == y && y == y2 && (up > 0 || down > 0)) {
                                printf("No\n");
                        } else {
                                printf("Yes\n");
                        }

                } else {
                        printf("No\n");
                }
        }
        return 0;
}
