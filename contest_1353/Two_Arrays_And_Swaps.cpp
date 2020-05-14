#include<bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1353/submission/80149819

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      min.push(x);
    }
    for(int j = 0; j < n; j++) {
      int x; cin >> x;
      max.push(x);
    }
    while(k > 0 && min.top() < max.top()) {
      min.pop();
      min.push(max.top());
      max.pop();
      k--;
    }
    int sum = 0;
    while(!min.empty()) {
      sum += min.top();
      min.pop();
    }
    cout << sum << endl;
  }
  return 0;
}
