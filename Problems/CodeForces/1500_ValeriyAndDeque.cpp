#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q, index = 0;
    cin >> N >> Q;
    vector<long long> deque;
    vector<long long> cycle;

    long long largest = -1, element, M;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        if (element > largest)
        {
            largest = element;
            index = i;
        }
        deque.push_back(element);
        cycle.push_back(element);
    }
    while (cycle[0] != largest)
    {
        if (cycle[0] > cycle[1])
        {
            cycle.push_back(cycle[1]);
            cycle.erase(cycle.begin() + 1);
        } else {
            cycle.push_back(cycle[0]);
            cycle.erase(cycle.begin());
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> M;
        long long currentLargest = -1;
        if (M <= index)
        {
            for (int j = 0; j < M; j++)
            {
                if (deque[j] > currentLargest)
                {
                    currentLargest = deque[j];
                }
            }
            cout << currentLargest << " " << deque[M] << endl;
        } else {
            M -= index;
            if (M >= N-1)
            {
                M = (M % (N - 1) == 0) ? N - 1 : M % (N - 1);
            }
            cout << largest << " " << cycle[M] << endl;
        }
    }


    return 0;
}
