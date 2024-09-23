#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[10001];
    int dp[10001] = {0, };

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[2], max(arr[2] + arr[3], arr[1] + arr[3]));

    for (int i = 4; i <= n; i++){
        dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 1]));
    }

    cout << dp[n] << "\n";
    return 0;

}