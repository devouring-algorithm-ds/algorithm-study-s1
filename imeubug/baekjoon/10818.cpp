// https://www.acmicpc.net/problem/10818

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  int min = 1000001;
  int max = -1000001;

  for(int i=0; i<n; ++i)
  {
    cin >> arr[i];
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  }

  cout << min << ' ' << max << endl;

  delete [] arr;
}
