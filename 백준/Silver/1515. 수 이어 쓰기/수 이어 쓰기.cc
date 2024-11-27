#include <iostream>

using namespace std;

string N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int num = 0, ptr = 0;
    while (1) {
        num++;
        string nums = to_string(num);
        for (int i = 0; i < nums.size(); i++) {
            if (N[ptr] == nums[i]) {
                ptr++;
            }
            if (ptr == N.size()) {
                cout << num;
                return 0;
            }
        }
    }
}