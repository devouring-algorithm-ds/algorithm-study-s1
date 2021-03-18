#include <iostream>

using namespace std;

int main()
{
    int total_num;
    cin >> total_num;

    int student_num = 0;
    int score[1000] = { 0, };
    int avg = 0;
    float result = 0;

    for (int i = 0; i < total_num; i++)//per test case
    {
        int sum_result = 0;
        int student_over = 0;
        cin >> student_num;
        for (int j = 0; j < student_num; j++)//per student score: get sum_result
        {
            cin >> score[j];
            sum_result += score[j];
        }
        avg = sum_result / student_num;

        for (int k = 0; k < student_num; k++)//per student score: get student_over
        {
            if (score[k] > avg)
            {
                student_over++;
            }
        }
        result = (float)student_over / student_num;

        cout << fixed;
        cout.precision(3);
        cout << result * 100 << "%" <<endl;
    }
    return 0;
}

