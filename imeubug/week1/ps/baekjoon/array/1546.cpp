// https://www.acmicpc.net/problem/1546

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  int n;
  cin >> n;
  double *arr = new double[n];
  int max = -1;

  for(int i=0; i<n; ++i) {
    cin >> arr[i];
    if(arr[i] > max) max = arr[i];
  }

  double sum = 0;
  for(int i=0; i<n; ++i) {
    arr[i] = arr[i] / max * 100;
    sum += arr[i];
  } 

  cout << sum / n << endl;

  delete [] arr;
  return 0;
}
