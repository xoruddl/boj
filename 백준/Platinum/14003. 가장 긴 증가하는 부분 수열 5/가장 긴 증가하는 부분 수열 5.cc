#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1000003], indexArr[1000003];
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    indexArr[0] = 0;
    int len = 1;
    for(int i = 1; i < N; i++) {
        if(arr[i] > v[v.size() - 1]) {
            v.push_back(arr[i]);
            indexArr[i] = len;
            len++;
        }
        else {
            auto idx = lower_bound(v.begin(), v.end(), arr[i]);
            *idx = arr[i];
            indexArr[i] = idx - v.begin();
        }
    }

    int maxLen = *max_element(indexArr, indexArr + N) + 1;
    cout << maxLen << '\n';
    vector<int> ans;
    for(int i = N - 1; i >= 0 && maxLen > 0; i--) {
        if(indexArr[i] == maxLen - 1) {
            ans.push_back(arr[i]);
            maxLen--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}