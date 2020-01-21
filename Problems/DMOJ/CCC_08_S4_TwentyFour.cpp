#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ans = -1;
void recure(int index, int current, int next, vector<int> cards) {
    if (index == 3) {
        ans = max(ans, current + next > 24 ? -1 : current + next);
        ans = max(ans, current - next > 24 ? -1 : current - next);
        ans = max(ans, current * next > 24 ? -1 : current * next);
        if (next != 0 && current % next == 0) {
            ans = max(ans, current / next > 24 ? -1 : current / next);
        }
    } else {
        recure(index+1, current + next, cards[index+1], cards);
        recure(index+1, current * next, cards[index+1], cards);
        recure(index+1, current - next, cards[index+1], cards);
        if (next != 0 && current % next == 0) {recure(index+1, current / next, cards[index+1], cards); }
        recure(index+1, current, next * cards[index+1], cards);
        recure(index+1, current, next - cards[index+1], cards);
        recure(index+1, current, next + cards[index+1], cards);
        if (next % cards[index+1] == 0) {recure(index+1, current, next / cards[index+1], cards);}
    }
}

int main() {
    int card, N;
    cin >> N;
    for (int k = 0; k < N; k++) {
        vector<int> cards;
        ans = -1;
        for (int j = 0; j < 4; j++) {
            cin >> card;
            cards.push_back(card);
        }
        do {
            recure(1, cards[0], cards[1], cards);
        } while (next_permutation(cards.begin(), cards.begin() + 4));
        recure(1, cards[0], cards[1], cards);
        cout << ans << endl;
    }
    return 0;
}
