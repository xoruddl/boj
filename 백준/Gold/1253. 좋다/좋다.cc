#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int left = 0;
        int right = v.size() - 1;

        if (i == 0) left++;
        else if (i == v.size() - 1) right--;

        int target = v[i];

        while (left < right) {
            if (v[left] + v[right] == target) {
                ans++;
                break;
            }
            else if (v[left] + v[right] > target) {
                right--;
                if (v[right] == target) right--;
            }
            else if (v[left] + v[right] < target) {
                left++;
                if (v[left] == target) left++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}