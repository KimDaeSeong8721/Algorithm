#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 트럭

int n, w, l ;

int arr[1'001];
int tot ; 
int pt ;
int currL; 


queue<int> q  ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> w >> l ;

    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    for(int i= 0 ; i < w*n ; i++){

        if(q.size() == w) {
            auto t = q.front(); q.pop();  

            if(q.front() == -1) {tot = i ;break ;}
            else if(t == 0) { }
            else{currL -= t;  }
        }
        if(pt != n){
            int nxt = arr[pt];
            if((currL + nxt) <= l){ q.push(nxt); currL += nxt; pt++; }
            else {q.push(0);}
        }
        else{
            q.push(-1);
        }

    }
    if(tot == 0) tot = w*n ;    



    cout << tot+1 ; 
}