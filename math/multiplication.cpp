#include <bits/stdc++.h>
using namespace std;

void multiply (string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int x = (a[i] - '0') * (b[j] - '0');

            int sum = x + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string ans = "";

    for (int digit: result) {
        if(!ans.empty() || digit != 0) {
            ans += to_string(digit);
        }
    }

    cout << (ans.empty() ? "0": ans) << endl;
}

int main() {

    string a, b;
    int i = 0;
    while (cin >> a && cin >> b) {
        multiply(a, b);
    }

    return 0;
}