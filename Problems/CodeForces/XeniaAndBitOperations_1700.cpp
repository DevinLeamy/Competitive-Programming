#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

long long values[131100];
long long tree[600000];
int N, M, I;
void update(int, int, int, int, long long, int);
void build(int, int, int, int);
int main() {
    long long V, V2;
    scanf("%i%i", &N, &M);
    int numLines = pow(2, N);
    for (long long i = 0; i < numLines; i++) {
        scanf("%lld", &V);
        values[i] = V;
    }
    build(1, 0, numLines-1, 1);
    for (int i = 0; i < M; i++) {
        scanf("%i%lld", &I, &V2);
        update(1, 0, numLines-1, I-1, V2, 1);
        cout << tree[1] << endl;
    }
    return 0;
}
void build(int node, int start, int end, int depth) {
    if (start == end) {
        tree[node] = values[start];
    } else {
        int mid = (start + end)/2;
        build(2*node, start, mid, depth+1);
        build(2*node + 1, mid+1, end, depth+1);
        if (depth % 2 == N % 2) {
            tree[node] = tree[node*2] | tree[node*2 + 1];
        } else {
            tree[node] = tree[node*2] ^ tree[node*2 + 1];
        }
    }
}
void update(int node, int start, int end, int index, long long value, int depth) {
    if (start == end) {
        values[index] = value;
        tree[node] = value;
    } else {
        int mid = (start + end)/2;
        if (start <= index && index <= mid) {
            update(2*node, start, mid, index, value, depth+1);
        } else {
            update(2*node + 1, mid+1, end, index, value, depth+1);
        }
        if (depth % 2 == N % 2) {
            tree[node] = tree[node*2] | tree[node*2 + 1];
        } else {
            tree[node] = tree[node*2] ^ tree[node*2 + 1];
        }
    }
}
