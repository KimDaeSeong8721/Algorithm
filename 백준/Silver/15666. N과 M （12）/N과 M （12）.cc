
#include <iostream>
#include <algorithm>
using namespace std;

// N과 M (10)
// 중복된 수들을 주어주고 조합

int arr[8];
int result[8];
int isused[8];

unordered_map<int,int> hashMap ;

int n,m ;

void func(int cnt, int prev) {
    if(cnt == m) {
        for(int i = 0; i< m ; i++) cout << result[i] << ' ';
        cout << '\n';
        return ;
    }

    int tmp = 0 ;
    for(int i = prev ; i < n ; i++) {
        if(tmp == arr[i]) continue;
        result[cnt] = arr[i] ;
        tmp = arr[i] ;
        func(cnt+1, i);
    }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n >> m ;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    sort(arr, arr + n);

    func(0,0);
}

