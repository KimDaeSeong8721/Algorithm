#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> indegree[1'000'001];
vector<int> outdegree[1'000'001];
int vis[1'000'001];

int cnt = 0 ;
vector<int> answer(4,0);

void dfs(int nxt){
    if(vis[nxt]) {
        cnt++;
        return;
    }
    
    vis[nxt] = true ;
    
    if(outdegree[nxt].empty()) {
        answer[2]++;
        return;
    }
    for(auto a : outdegree[nxt]){
        dfs(a);
    }
}


vector<int> solution(vector<vector<int>> edges) {
    
    for(auto edge : edges){
        outdegree[edge[0]].push_back(edge[1]);
        indegree[edge[1]].push_back(edge[0]);
    }
    
    for(int i = 1 ; i <= 1'000'000 ; i++){
        if(indegree[i].empty() && outdegree[i].empty()) {continue;}
        if(indegree[i].empty()) {
            if(outdegree[i].size() >= 2) {
                // 생성한 정점
                vis[i] = true ;
                answer[0] = i;
            } else if(outdegree[i].size() == 1){
                // 막대 모양의 시작점.
                dfs(i);
            } 
        }

    }
    
    for(auto node :outdegree[answer[0]]){
        if(vis[node]) continue; 
        
        if(indegree[node].size() == 1) {
            // 막대모양
            answer[2]++;
        } else {
            // 도넛모양 혹은 8자모양 
            cnt = 0 ;
            dfs(node);
            if(cnt == 1) answer[1]++;
            else if(cnt == 2) answer[3]++;
            
        }
        // 모양 검사 
        
    }
    
    
    return answer;
}

/*
이 그래프들과 무관한 정점을 하나 생성.
indegree가 0인데 Outdegree가 2이상이면 생성한 정점.

도넛모양과 8자모양을 어떻게 구별하지?

*/