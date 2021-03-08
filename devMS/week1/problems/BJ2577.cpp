#include <iostream>
using namespace std;

void count(int* arr);

int main()
{
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;

    int result;
    result = A * B * C;

    int result_arr[10] = { 0, };
    int deno = 1000000000;
    
    for (int i = 0; i < 10; i++)
    {
        result_arr[i] = result / deno;
        result = result - result_arr[i] * deno;
        deno /= 10;
    }

    count(result_arr);

    return 0;
}

void count(int* arr)
{
    int num[10] = {0,};//element 0 : number of 0s in the arr. 

    int num0 = 0; // number of 0 before the real value
    while (arr[num0] == 0)
    {
        num0++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[j] == i)
            {
                num[i] += 1;
            }
        }
        if (i == 0)
            cout << num[i] - num0 << endl;
        else
            cout << num[i] << endl;
    }
}

