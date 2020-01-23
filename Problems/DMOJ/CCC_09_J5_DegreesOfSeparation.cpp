#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>
#include <queue>
#define ll long long
#define pb push_back
//#define doH(h) for(int i = 0; i < h; i++)

using namespace std;

vector< set<int> > network;
void makeFriends(int, vector<int>);

int main() {
	ios_base::sync_with_stdio(0);
	int x, y;
	for (int i = 0; i < 50; i++) {network.pb(set<int>());}
	makeFriends(0, {5}); makeFriends(1, {5});
	makeFriends(2, {3, 5, 14, 4}); makeFriends(3, {5, 4, 2});
	makeFriends(4, {5, 2, 3}); makeFriends(5, {0, 6, 4, 3, 2, 1});
	makeFriends(6, {5, 7}); makeFriends(7, {6, 8});
	makeFriends(8, {7, 9, 11}); makeFriends(9, {8, 10});
	makeFriends(10, {9, 11}); makeFriends(11, {8, 10, 12});
	makeFriends(12, {11, 14, 13}); makeFriends(13, {12});
	makeFriends(14, {2, 12}); makeFriends(15, {16, 17});
	makeFriends(16, {15, 17}); makeFriends(17, {15, 16});
	while (true) {
		char command;
		cin >> command;
		if (command == 'i') {
			cin >> x >> y;
			network[x-1].insert(y-1);
			network[y-1].insert(x-1);
		} else if (command == 'd') {
			cin >> x >> y;
			set<int>::iterator it;
			it = network[x-1].find(y-1);
			network[x-1].erase(it);
			it = network[y-1].find(x-1);
			network[y-1].erase(it);
		} else if (command == 'n') {
			cin >> x;
			cout << network[x-1].size() << endl;
		} else if (command == 'f') {
			cin >> x;
			set<int> friends;
			friends.insert(x-1);
			for (int friend_ : network[x-1]) {
				friends.insert(friend_);
				for (int friend__ : network[friend_]) {
					friends.insert(friend__);
				}
			}
			cout << (friends.size() - 1) - (network[x-1].size()) << endl;
		} else if (command == 's') {
			cin >> x >> y;
			queue<pair<int, int>> current;
			current.push({x-1, 0});
			set<int> friends;
			bool found = false;
			int distance = -1;
			while (current.size() > 0) {
				pair<int, int> g = current.front();
				current.pop();
				if (g.first == y-1) {
					if (found) {
						distance = min(distance, g.second);
					} else {
						found = true;
						distance = g.second;
					}
				}
				if (friends.find(g.first) == friends.end()) {
					friends.insert(g.first);
					for (int friend_ : network[g.first]) {
						if (friends.find(friend_) == friends.end()) {
							current.push({friend_, g.second + 1});
						}
					}
				}
			}
			if (found) {cout << distance << endl;}
			else {cout << "Not connected" << endl;}
		} else {
			break;
		}
	}
	return 0;
}
void makeFriends(int og, vector<int> newFs) {
	for (int i = 0; i < newFs.size(); i++) {
		int newF = newFs[i];
		network[og].insert(newF); network[newF].insert(og);
	}
}
