#include<bits/stdc++.h>

using namespace std;

using lli = long long int;

int main() {
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int l = 0, r = 0;
        int a = 0, b = 0, c = 0;
        int ans = INT_MAX;
        for(r; r < s.length(); r++) {
           switch (s[r]) {
             case '1': a++; break;
             case '2': b++; break;
             case '3': c++; break;
           }
           while(a > 0 && b > 0 && c > 0) {
             ans = min(ans, r-l+1);
             switch (s[l]) {
               case '1': a--; break;
               case '2': b--; break;
               case '3': c--; break;
             }
             l++;
           }
        }
        cout << (ans == INT_MAX ? 0 : ans) << endl;
    }
    return 0;
}
