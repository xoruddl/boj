#include <iostream>
#include <deque>

using namespace std;

int N, M;
int arr[53];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int res = 0;
    int idx;
    while (M--) {
        int x;
        cin >> x;
        for(int i = 0; i < dq.size(); i++) {
            if(dq[i] == x) {
                idx = i;
                break;
            }
        }

        // 앞에서부터
        if(idx <= dq.size() / 2) {
            while(1) {
                if(dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                ++res;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else { // 뒤에서부터
            while(1) {
                if(dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                ++res;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << res;
    return 0;
}