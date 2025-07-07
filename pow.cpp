#include <iostream>
using namespace std;

// double power(int x, int n) {
//     if (n == 0) return 1;
//     return x * power(x, n - 1);
// }
double power(int x, int n) {
    if (n == 0) return 1;
    double half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}
 

int main() {
    int x, n;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;
    if(n<0) cout << x << "^" << -n << " = " <<1/ power(x, -n) << endl;
     else cout << x << "^" << n << " = " << power(x, n) << endl;
    
    return 0;
}
