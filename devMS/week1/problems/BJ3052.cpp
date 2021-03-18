#include <iostream>
using namespace std;

void count(int* arr);

int main()
{
    int remainder[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> remainder[i];
        remainder[i] = remainder[i] % 42;
    }

    count(remainder);

    return 0;
}

void count(int* arr)
{
    int num[42] = { 0, };//element N : number of N in the arr.
    int result = 0;

    for (int i = 0; i < 42; i++)//remainder could be 0 to 41
    {
        for (int j = 0; j < 10; j++)//number of input(remainder array) is 10
        {
            if (arr[j] == i) //if the element is 0 then num[0] is increased by 1
            {
                num[i] += 1;
            }
        }
        if (num[i] != 0)//count the number of remainders which is not zero.
        {
            result++;
        }       
    }
    cout << result << endl;
}

