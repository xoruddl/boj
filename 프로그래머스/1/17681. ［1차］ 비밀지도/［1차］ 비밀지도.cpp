#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(arr1[i] | arr2[i]);
    }
    
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (arr[i] & (1 << j)) {
                s = "#" + s;
            } else {
                s = " " + s;
            }
        }
        answer.push_back(s);
    }
    
    return answer;
}