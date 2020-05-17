#include<cmath>
#include<bits/stdc++.h>

using namespace std;

const double PI = 3.141592653;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    double ang = PI - PI/n;
    int x = (2*n-4)/4;
    double prev = 0.000000000;
    double res = 0.500000000;
    double curr = ang;
    for(int i = 0; i < x; i++) {
        curr = ang-prev;
        prev = PI - curr;
        res += cos(prev);
    }
    cout << fixed << setprecision(9) << (double)2*res << endl;
  }
  return 0;
}
