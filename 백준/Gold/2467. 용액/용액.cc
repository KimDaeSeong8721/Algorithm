#include <iostream>


using namespace std;

int  n = 0;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    long long arr[n] ;
    int left = 0 ;
    int right = n-1 ;
    long long  ans = 10000000000 ;
    pair<int, int> p  ;

    for(int i = 0 ; i< n ; i++){
      cin>>arr[i];
    }

  while(left<right){
    long long  sum = arr[left] + arr[right];
    
    if(abs(sum) <= ans)
    { 
      ans = abs(sum) ; p = make_pair(left,right);
    }
    if(sum > 0) right--;
    else if(sum < 0) left++;
    else break;
  }

  cout<<arr[p.first]<<" "<<arr[p.second];
    return 0;
 
  }
   
  

