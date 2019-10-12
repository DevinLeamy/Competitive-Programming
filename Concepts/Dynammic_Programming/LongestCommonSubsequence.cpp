#include <iostream>

using namespace std;

int getLCS(string seq1, string seq2, int length)
{
    if (seq1.size() == 0 || seq2.size() == 0)
    {
        return length;
    }
    if (seq1.at(seq1.size() - 1) == seq2.at(seq2.size() - 1))
    {
        return getLCS(seq1.substr(0, seq1.size() - 1), seq2.substr(0, seq2.size() - 1), length+1);
    } else {
        return max(getLCS(seq1.substr(0, seq1.size() - 1), seq2.substr(0, seq2.size()), length), getLCS(seq1.substr(0, seq1.size()), seq2.substr(0, seq2.size() - 1), length));
    }
}

int main() {
    string seq1, seq2;
    cin >> seq1 >> seq2;
    cout << getLCS(seq1, seq2, 0) << endl;
    return 0;
}

