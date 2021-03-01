// https://www.acmicpc.net/problem/2562

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  const int N = 9;
  int arr[N];
  int max = -1;
  int pos = -1;

  for(int i=0; i<N; ++i)
  {
    cin >> arr[i];
    if(arr[i] > max) max = arr[i], pos = i+1;
  }

  cout << max << endl << pos << endl;

  return 0;
}
