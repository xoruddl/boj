#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> st;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    long long ans = 0;
    while (N--) {
        int h;
        cin >> h;
        int cnt = 1;
        while (!st.empty() && st.top().first <= h) {
            ans += st.top().second;
            if (st.top().first == h) cnt += st.top().second;
            st.pop();
        }
        if (!st.empty()) ans++;
        st.push({h, cnt});
    }
    cout << ans;
}