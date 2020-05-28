#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m, x, y;
    vector<string> mat;
    Solution(int a, int b, int c,int d) {
      n = a, m = b, x = c, y = d;
      mat.resize(n, "");
      for(int i = 0; i < n; i++) {
        cin >> mat[i];
      }
    }
    int solve() {
      int ans = 0;
      for(int i = n-1; i >= 0; i--) {
        vector<int> dp(m+1,INT_MAX);
        dp[m] = 0;
        for(int j = m-1; j >= 0; j--) {
          if(mat[i][j] == '*') {
            dp[j] = dp[j+1];
          }
          else {
            dp[j] = x + dp[j+1];
            if(j < m-1 && mat[i][j+1] == '.') {
              dp[j] = min(dp[j], y + dp[j+2]);
            }
          }
        }
        ans += dp[0];
      }
      return ans;
    }
};
int main() {
    int t; cin >> t;
    while(t--) {
      int n, m, x , y;
      cin >> n >> m >> x >> y;
      Solution ob(n,m,x,y);
      cout << ob.solve() << endl;
    }
    return 0;
}
