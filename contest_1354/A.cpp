#include<bits/stdc++.h>

using namespace std;

using lli = long long int;

int main() {
    int t; cin >> t;
    while(t--) {
        lli a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b >= a) {
            cout << b << endl;
        }
        else {
            if(d >= c) {
              cout << -1 << endl;
            } else {
              int r = ceil((double)(a-b)/(c-d));
              cout << b + c*r << endl;
            }
        }
    }
    return 0;
}
