#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
      int n, m, k;
      cin >> n >> m >> k;
      int cards = n/k;
      if(cards >= m) {
        cout << m << endl;
      } else {
        m = m - cards;
        cout << cards - ceil(double(m)/double(k-1)) << endl;
      }
    }
    return 0;
}
