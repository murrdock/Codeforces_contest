#include<cmath>
#include<bits/stdc++.h>

using namespace std;

const double PI = 3.141592653;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    n = n * 2;
    cout << fixed << setprecision(9) << (1/(2*sin(PI/2/n))) << endl;
  }
  return 0;
}
