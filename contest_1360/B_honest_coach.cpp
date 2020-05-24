#include <bits/stdc++.h>
// https://codeforces.com/contest/1360/submission/81232273 
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
      int n; cin >> n;
      vector<int> nums(n);
      for(int i = 0; i < n; i++){
        cin >> nums[i];
      }
      sort(nums.begin(),nums.end());
      int ans = INT_MAX;
      for(int i = 1; i < n; i++) {
        ans = min(ans, nums[i]-nums[i-1]);
      }
      cout << ans << endl;
    }
    return 0;
}
