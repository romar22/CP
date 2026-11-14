#include <bits/stdc++.h>
using namespace std;


int main() {
    int numbers[100];

    // fill all with 1
    // fill(start, end, value);
    fill(numbers, numbers + 100, 1);
    // reverse
    reverse(numbers, numbers + 100);
    // sort
    sort(numbers, numbers + 100);

    return 0;
}