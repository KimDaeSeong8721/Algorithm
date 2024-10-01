#include <iostream>
#include <algorithm>
using namespace std;


int n,m ;
int arr[101][101];
const int big_value = 1'050'000'000;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++) {
        fill(arr[i],arr[i]+n+1, big_value);
    }

    for(int i = 0 ; i < m ; i++) {
        int a,b,c ;
        cin >> a >> b >> c ;
        arr[a][b] = min(arr[a][b],c) ;
    }

    for(int i = 1; i <= n; i++) arr[i][i] = 0 ; // 대각선 0 초기화

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++) {
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
    
    for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++) {
            if(arr[i][j] == big_value) cout << '0';
            else cout << arr[i][j]; 
            cout << ' ';
            }
        cout << '\n';
    }
 
}