// https://www.acmicpc.net/problem/8958

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    string s;
    cin >> s;
    int score = 0;
    int pt = 1;

    for(int i=0; s[i]; ++i) 
    {
      if(s[i] == 'O') 
      {
        score += pt;
        ++pt;
      }
      else 
      {
        pt = 1;
      }
    }

    cout << score << endl;
  }

  return 0;
}
