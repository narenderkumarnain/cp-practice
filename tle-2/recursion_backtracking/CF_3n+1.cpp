#include <bits/stdc++.h>
using namespace std;

int recur(int n) {
  if(n == 1) return 1;
  if(n % 2 == 0) {
    return recur(n / 2) + 1;
  } else {
    return recur(3 * n + 1) + 1;
  }
}

int main() 
{
    int n;
    cin >> n;
    
    cout << recur(n) << endl;
    return 0;
}