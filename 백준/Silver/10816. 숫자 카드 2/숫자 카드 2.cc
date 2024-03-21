#include <iostream>
#include <algorithm>
using namespace std;


int a[500005];
int n ; 


int lowerBound(int size , int target){
	int lo = -1 ; int hi = size;
	while(lo+1 <hi) {
		int mid = (lo + hi ) / 2; 
		if(a[mid] >= target) hi = mid;
		else lo = mid ;
	}
	return hi ;
}


int upperBound(int size ,int target) {
	int lo = -1 ; int hi = size;
while(lo+1 <hi) {
		int mid = (lo + hi ) / 2; 
		if(a[mid] > target) hi = mid;
		else lo = mid ;
	}
	return hi ;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a,a+n);
    int m ;
    cin >> m ;
    while(m--) {
        int t ; 
        cin >> t ;
        cout << upperBound(n,t)-lowerBound(n,t) <<'\n';
    }
}

/*
[해결전략 참고]
https://www.acmicpc.net/blog/view/109
[시작]

[배울 점]

[문제 이해]

[입력]

[제약]

[출력]

[풀이전략]


*/
