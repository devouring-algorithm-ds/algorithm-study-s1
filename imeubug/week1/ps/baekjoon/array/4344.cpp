// https://www.acmicpc.net/problem/4344

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
    int n;
    cin >> n;
    double *arr = new double[n];
    double sum = 0;

    for (int i=0; i<n; ++i) 
    {
      cin >> arr[i];
      sum += arr[i];
    }

    sum /= n;

    int cnt = 0;
    for (int i=0; i<n; ++i)
    {
      if (arr[i] > sum)
      {
        ++cnt;
      }
    }

    printf("%.3f%%\n", cnt*100.0/n);
    delete [] arr;
  }

  return 0;
}
