// https://www.acmicpc.net/problem/2577

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  int a, b, c, d;
  int arr[10] = {0};
  cin >> a >> b >> c;
  d = a*b*c;

  while(true) {
    ++(arr[d%10]);
    d/=10;
    if(d<=0) break;
  }

  for(int i=0; i<10; ++i) {
    cout << arr[i] << endl;
  }
  return 0;
}
