#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n ; 

vector<int> v1; // 양수
vector<int> v2; // 음수
bool zeroflag = false ;
int result ;
vector<int> v ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ; 
    for(int i = 0 ; i< n ; i++)
        {   int tmp ;
            cin >> tmp ;
            if(tmp == 0) zeroflag = true;
            else if(tmp > 0) v1.push_back(tmp);
            else v2.push_back(tmp);
        }
    
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end());

    if(v1.size() % 2 == 1){
        result += v1.back();
        v1.pop_back();
    }
    if(v1.size() != 0) {
        for(int i = 0 ; i < v1.size()-1 ; i+=2){
        if(v1[i] == 1 || v1[i+1] == 1) result+= v1[i]+v1[i+1];
        else 
        result += v1[i]*v1[i+1];
    } }
    
     if(v2.size() % 2 == 1){
        if(!zeroflag) result += v2.back();
        v2.pop_back();
    }
    if(v2.size() != 0) {
        for(int i = 0 ; i < v2.size()-1 ; i+=2){
        result += v2[i]*v2[i+1];
    } }
    
    cout<< result ; 
}