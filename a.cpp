#include <bits/stdc++.h>
using namespace std;

void solve() {
    unsigned long long n;

    while (cin >> n && n != 0) {
        unsigned long long root = sqrtl(n);

        cout << (root * root == n ? "yes" : "no") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}