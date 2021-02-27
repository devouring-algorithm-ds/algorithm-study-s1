// https://www.acmicpc.net/problem/3052

#include <iostream>

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

using namespace std;

int main()
{
  bool modulo[42] = {0};
  for(int i=0; i<10; ++i) {
    int n;
    cin >> n;
    modulo[n%42] = true;
  }

  int count=0;
  for(int i=0; i<42; ++i) {
    if(modulo[i]) ++count;
  }

  cout << count << endl;
  return 0;
}
