#include <bits/stdc++.h>

// https://codeforces.com/contest/1360/submission/81246739

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
      bool state = false;
      int n; cin >> n;
      vector<int> even;
      vector<int> odd;
      vector<bool> t(101, false);
      for(int i = 0; i < n; i++) {
        int x; cin >> x;
        (x%2 ? odd.push_back(x) : even.push_back(x));
        t[x] = true;
      }
      if(odd.size()%2) {
        for(int i = 0; i < odd.size(); i++) {
           if(t[odd[i]+1] or t[odd[i]-1]) {
             state = true; break;
           }
        }
      } else {
        state = true;
      }
      cout << (state ? "YES" : "NO") << endl;
    }
    return 0;
}
