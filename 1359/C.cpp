#include <bits/stdc++.h>

using namespace std;

inline double calc(int a, double h, double c) {
  return ((a*h)+(a-1)*c)/(a+a-1);
}

int main() {
  int T; cin >> T;
  while(T--) {
    double h,c,t;
    cin >> h >> c >> t;
    bool turn = true; // hot
    int a = 0, b = 0;
    double l = (h+c)/2.0;
    if(t <= l) {
      cout << 2 << endl;
      continue;
    }
    int ans = 0;
    double diff = h-t+1;
    int left = 1, right = 1000000;
    while(left <= right) {
      int mid = (left + right)/2;
      double avg = calc(mid, h, c);

      if(avg >= t) {

        left = mid+1;
        if(diff > abs(t - avg)) {
          diff = abs(t - avg);
          ans = 2*mid -1;
        }
      } else {
        right = mid -1;
      }
    }
    left = 1, right = 1000000;
    while(left <= right) {
      int mid = (left + right)/2;
      double avg = calc(mid ,h, c);
      if(avg < t) {
        if(diff > abs(t - avg)) {
          diff = abs(t - avg);
          ans = 2*mid -1;
        }
        right = mid -1;
      } else {
        left = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
