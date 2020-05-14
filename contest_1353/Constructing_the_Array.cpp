#include<bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1353/submission/80161924
// it's like doing breadth first search but in the even case left and right value differ

struct compare{
  bool operator()(const pair<int,int>& a,const pair<int,int>& b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  }
};

int main() {
  int t; cin >> t;
  while(t--) {
        int n; cin >> n;
        vector<int> arr(n,0);
        set<pair<int,int>, compare> pq;
        int x = 1;
        pq.insert(make_pair(n, 0));
        while(pq.size()) {
            pair<int,int> p = *pq.rbegin();
            pq.erase(p);
            int l = p.first;
            int i = p.second;
            if(l < 1) continue;
            if(l%2) {
              int m = i+l/2;
              arr[m] = x++;
              //cout << m << " "<< arr[m] <<endl;
              pq.insert(make_pair(m-i,i));
              pq.insert(make_pair(i+l-m-1,m+1));
            } else {
              int m = i+(l-1)/2;
              arr[m] = x++;
            //  cout << m << " " << l << "" << arr[m] <<endl;
              pq.insert(make_pair(m-i,i));
              pq.insert(make_pair(i+l-m-1,m+1));
            }
        }

        for(auto a : arr) cout << a << " ";
        cout << endl;
    }

  return 0;
}
