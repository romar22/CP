#include <bits/stdc++.h>
using namespace std;

int _gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // coprime example
    cout << _gcd(2, 5);
}