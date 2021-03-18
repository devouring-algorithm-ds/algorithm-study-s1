#include <iostream>
#include <string>
using namespace std;


int main()
{
    string input_str;
    int total_num = 0;
    int o_num;
    int result;

    cin >> total_num;

    for (int i = 0; i < total_num; i++)
    {
        cin >> input_str;
        o_num = 0;
        result = 0;

        for (int j = 0; j < input_str.length(); j++) // check per one test case
        {
            
            if (input_str[j] == 'O')
            {
                o_num++;
                result += o_num;
            }
            if (input_str[j] == 'X')
            {
                o_num = 0;
            }
        }
        cout << result << endl;
    }
    

    return 0;
}