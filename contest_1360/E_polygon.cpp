#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1360/submission/81278996

bool check(vector<bitset<50>>& mat, int n) {
    for(int i = n-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            if(mat[i].test(j)) {
                if(mat[i+1].test(j) or mat[i].test(j+1)) {
                  continue;
                } else return false;
            }
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    while(t--) {
      int n; cin >> n;
      vector<bitset<50> > mat(50, 0);
      for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
          if(s[j] == '1') {
            mat[i].set(j);
          }
        }
      }
      if(check(mat, n)) {
        cout << "YES" << endl;
      } else cout << "NO" << endl;
    }
    return 0;
}
