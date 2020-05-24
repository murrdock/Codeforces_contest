#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
      int a, b;
      cin >> a >> b;
      if(a < b) swap(a,b);
      int side = max(a, 2*b);
      cout << (side*side) << endl;
    }
    return 0;
}
