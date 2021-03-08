#include <iostream>
using namespace std;
int main()
{
    int size;
    int input;
    int min = 10000000;
    int max = -10000000;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> input;

        if (input < min)
        {
            min = input;
        }
        if (input > max)
        {
            max = input;
        }
    }
    cout << min << " ";
    cout << max;
}

