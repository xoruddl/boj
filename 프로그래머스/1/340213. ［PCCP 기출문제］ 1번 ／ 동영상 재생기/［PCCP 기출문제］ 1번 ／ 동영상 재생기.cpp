#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int vl = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int ps = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int os = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int oe = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
    
    if (ps >= os && ps <= oe){
        ps = oe;
    }
    for (int i = 0; i < commands.size(); i++) {
        string com = commands[i];
        if (com == "next"){
            ps += 10;
        } else if (com == "prev"){
            ps -= 10;
        }
        if (ps >= vl){
            ps = vl;
        }
        if (ps <= 0){
            ps = 0;
        }
        if (ps >= os && ps <= oe){
            ps = oe;
        }
        
    }
    
    int m = ps / 60;
    string min = "";
    if (m == 0){
        min = "00";
    } else if (m < 10){
        min = "0" + to_string(m);
    } else{
        min = to_string(m);
    }
    
    int s = ps % 60;
    string sec = "";
    if (s == 0){
        sec = "00";
    } else if (s < 10){
        sec = "0" + to_string(s);
    } else{
        sec = to_string(s);
    }
    
    answer = min + ":" + sec;
    
    return answer;
}