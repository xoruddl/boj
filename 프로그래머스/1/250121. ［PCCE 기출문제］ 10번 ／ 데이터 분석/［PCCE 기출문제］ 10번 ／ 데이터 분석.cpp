#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> column = {"code", "date", "maximum", "remain"};
vector<vector<int>> temp;
int targetIdx; // 어떤 컬럼으로 정렬할지

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[targetIdx] < v2[targetIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < 4; i++) {
        if (sort_by == column[i]){
            targetIdx = i;
        }
    }
    
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int val = data[i][j];
            string curCol = column[j];
            
            if (curCol == ext) {
                if (val < val_ext) {
                    temp.push_back(data[i]);
                }
            }
        }
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    return temp;
}