#include <iostream>
#include <string>
#include <stack>

using namespace std;

int K;
long long sum;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            st.pop();
        }
        else {
            st.push(a);
        }
    }
    while (!st.empty()) {
        int num = st.top();
        sum += num;
        st.pop();
    }
    cout << sum << '\n';
    return 0;
}