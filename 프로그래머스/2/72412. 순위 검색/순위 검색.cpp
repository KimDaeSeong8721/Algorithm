#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;


vector<string> split(string& s, string& sep){
    vector<string> ret ;
    int pos = 0;
    while(pos <s.size()){
        int nxt_pos = s.find(sep,pos); // find의 두번쨰 인자는 찾기 시작하는 주소값
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0) ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret ; 
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string,vector<int>> m ; 
    
      for(auto pe : info) {
          string sep =" ";
            vector<string> person = split(pe, sep);
            int score = stoi(person.back()); person.pop_back();
          
          for(int i = 0 ; i < 16 ; i++){
            string tmp ; 
              for(int j = 0 ; j < 4 ; j++){
                  tmp += (i & (1 << j)) ? person[j] : "-";
              }
              m[tmp].push_back(score);
          }
      }
    
    for(auto &iter: m) sort(iter.second.begin(), iter.second.end()); 
        
    for(auto q: query) {
        int cnt = 0 ;
        string sep = " and ";
        vector<string> p = split(q, sep);
        string tmp = p.back(); p.pop_back();
        sep = " ";
        vector<string> temp = split(tmp,sep); 
        p.push_back(temp[0]);
        int score = stoi(temp[1]);
        
        string str = p[0]+p[1]+p[2]+p[3];
        
        cnt += m[str].end()- lower_bound(m[str].begin(),m[str].end(),score);
        
        
        answer.push_back(cnt);
    }
    return answer;
}