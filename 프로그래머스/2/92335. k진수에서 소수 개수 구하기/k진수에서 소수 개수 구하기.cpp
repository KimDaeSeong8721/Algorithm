#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


vector<int> convert(int n, int k) {
    int tmp = n ;
    vector<int> result ;
    while(tmp > 0) {
           result.push_back(tmp % k) ;
            tmp /= k ;
    }
    reverse(result.begin(),result.end());
    return result; 
}

bool isprime(long long  n) {    
    if(n <= 1) return false;
    if(n == 2 ) return true;
    for(long long i = 2 ; i*i <= n ; i++){
        if(n % i == 0) return false ;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0 ;
    auto kv = convert(n,k);
    
    long long tmp = 0;
    for(long long i = 0 ; i < kv.size() ; i++) {
        if(kv[i]== 0) { 
            if(isprime(tmp)) answer++;
            tmp = 0 ; 
            continue;
        }
        tmp = tmp*10 + kv[i];
    }
    if(isprime(tmp)) answer++;
    return answer;
}


/*
k진법으로 보았을 때가 아닌 10진법으로 보았을 때 P가 소수여야함.

*/