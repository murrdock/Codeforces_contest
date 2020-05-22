#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/challenges/competitive/may-circuits-20/algorithm/avoiding-networked-paths-revisited-38d27ffb/

using llu = long long unsigned int;
// considering 5 factors of X(repeated as unique as well) we traverse down taking union(maintaining only unique ones) down the path.
// when all the factors are included it's a black node.
// 32 possibilites which we can store inside a vector determining which possibility is this at x, y.
class Solution {
  int n,m;
  const int MOD = 1e9+7;
  vector<vector<short int>> mat;
  vector<vector<vector<int>>> dp;
  inline short int operate(llu x) {
      bitset<5> b(0);
      if(x > 0 && x%107 == 0) {
        x = x/107;
        b.set(0);
      }
      if(x > 0 && x%107 == 0) {
        x = x/107;
        b.set(1);
      }
      if(x > 0 && x%1361 == 0) {
        x = x/1361;
        b.set(2);
      }
      if(x > 0 && x%1361 == 0) {
        x = x/1361;
        b.set(3);
      }
      if(x > 0 && x%10000019 == 0) {
        x = x/10000019;
        b.set(4);
      }
      return (short int)b.to_ulong();
  }
  inline int sum(int x, int y) {
    int z = x + y;
    if(z >= MOD) {
      z = z - MOD;
    }
    return z;
  }
  inline short int OR(short int x, short int y) {
    bitset<5> a(x), b(y), res(0);
    ((a.test(4) || b.test(4)) ? res.set(4) : res.reset(4));
    int c = a.test(0) + a.test(1) + b.test(0) + b.test(1);
    (c > 1 ? (res.set(0), res.set(1)) : (c > 0 ? res.set(0) : res.reset(0)));
    c = a.test(2) + a.test(3) + b.test(2) + b.test(3);
    (c > 1 ? (res.set(2), res.set(3)) : (c > 0 ? res.set(2) : res.reset(2)));
    return (short int)(res.to_ulong());
  }
public:
  Solution(int x, int y) {
    n = x, m = y;
    mat.assign(n, vector<short int> (m, 0));
    dp.assign(n, vector<vector<int>> (m, vector<int> (32,-1)));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        llu a; cin >> a;
        mat[i][j] = operate(a);
      }
    }
  }
  int dfs(short int val, int i, int j) {
      if(i >= n || j >= m) {
        return 0;
      }
      if(dp[i][j][val] != -1) return dp[i][j][val];
      short int t = OR(mat[i][j], val);
      if(t == 31) {
        return 0;
      }
      if(i == n-1 && j == m-1) return 1;
      return dp[i][j][val] = sum(dfs(t, i+1,j), dfs(t, i,j+1));
  }
};

int main() {
    int n, m;
    cin >> n >> m;
    Solution ob(n,m);
    cout << ob.dfs(0,0,0) << endl;
    return 0;
}
