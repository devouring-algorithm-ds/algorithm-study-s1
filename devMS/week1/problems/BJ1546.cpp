#include <iostream>

using namespace std;

int main()
{
    int subject_num = 0;
    cin >> subject_num;

    float score[1000] = {0,};
    int max = -1000;
    for (int i = 0; i < subject_num; i++) // get score & max value
    {
        cin >> score[i];
        if (score[i] > max)
        {
            max = score[i];
        }
    }
    float sum_result = 0;
    for (int j = 0; j < subject_num; j++) // change score to score/max*100
    {
        score[j] = score[j] / max * 100;
        sum_result += score[j];
    }
    float avg = (float)sum_result / subject_num;
    
    cout << avg << endl;


    return 0;
}

