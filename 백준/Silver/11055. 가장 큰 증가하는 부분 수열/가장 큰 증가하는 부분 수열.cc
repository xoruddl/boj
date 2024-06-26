#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1001];
    int dp[1001];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--){
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(dp[i], ans);
    }

    cout << ans << "\n";
    return 0;
}