#include<iostream>

using namespace std;

// https://codeforces.com/contest/1353/submission/80117677
// work out an example to see that you'll only fill boxed that can have zeros on both sides.

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    if(n == 1) {
      cout << 0 << endl;
    } else if(n == 2) {
      cout << m << endl;
    } else {
      int x = (n-1)/2;
      if(m % x == 0) {
        cout << 2 * m << endl;
      } else {
        int y = m/x;
        cout << (x-1)*y*2 + (m-y*x+y)*2 << endl;
      }
    }
  }
  return 0;
}
