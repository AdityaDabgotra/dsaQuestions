#include <bits/stdc++.h>
using namespace std;

int stairs(int n, vector<int>& arr) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main() {
    int n;
    cout << "Enter the Number of stairs:\t";
    cin >> n;
    vector<int> ans(max(3, n + 1), -1);

    int result = stairs(n, ans);
    cout << "The total possible ways are:\t" << result << endl;

    return 0;
}