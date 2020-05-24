#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1360/submission/81305963

using llu = long long int;

llu count(vector<llu>& ve, llu t) {
  int res = 0;
  for(auto &l : ve){
    if(l < t) res++;
  }
  return res;
}

llu find(vector<llu>& ve, llu m, llu n) {
    llu k = (m-n-1)/2;
    llu l = 0, r = m-1;
    llu ans = 0;
    while(l <= r) {
      llu mid = (l+r)/2;
      llu comp = mid - count(ve, mid);
      if(comp <= k) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
      int n, m;
      cin >> n >> m;
      vector<llu> ve(n);
      for(int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(s.begin(),s.end());
        bitset<64> b;
        for(int j = 0; j < m; j++) {
          if(s[j] == '1') {
            b.set(j);
          }
        }
        ve[i] = b.to_ullong();
      }
      llu ans = find(ve, (1LL << m), n);
      bitset<60> bb(ans);
      string res = bb.to_string();
      reverse(res.begin(),res.end());
      res.resize(m);
      reverse(res.begin(),res.end());
      cout << res << endl;
    }
    return 0;
}
