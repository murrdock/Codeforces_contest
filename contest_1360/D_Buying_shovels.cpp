#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1360/submission/81259520

int largestfactor(int n, int k) {
    int ans = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n%i == 0) {
          if(i <= k) ans = max(ans, i);
          if(n/i <= k) ans = max(ans, n/i);
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
      int n, k;
      cin >> n >> k;
      if(k >= n) {
        cout << 1 << endl;
      } else {
        int l = largestfactor(n, k);

        cout << n/l << endl;
      }
    }
    return 0;
}
