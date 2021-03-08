#include <iostream>
using namespace std;
int main()
{
    int input[9] = { 0, };
    int max = -10000000;
    int max_idx = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> input[i];

        if (input[i] > max)
        {
            max = input[i];
            max_idx = i+1;
        }
    }
    cout << max << endl;
    cout << max_idx;

    return 0;
}
