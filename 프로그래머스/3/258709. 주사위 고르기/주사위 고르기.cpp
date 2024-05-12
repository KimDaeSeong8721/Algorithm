#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> decimalToBase6(int decimal,int n ) {
        vector<int> result(n) ;
    int index = n -1 ;
    while (decimal > 0) {
        int remainder = decimal % 6;
        result[index] = remainder;
        decimal /= 6;
        index--;
    }
    return result;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<int> dice_kind ;
    vector<int> tmp ;
    int max_cnt = 0 ; 
    int dice_cnt = dice.size();
    
    for(int i = 1 ; i <= dice_cnt ; i++){
        dice_kind.push_back(i);
        
        if( i <= dice_cnt / 2) {
            tmp.push_back(1); 
        } else { tmp.push_back(0);}
    }
    
    do{     
        cout << "a";
        vector<int> a ; 
        vector<int> b ;
        for(int i = 0; i < dice_cnt; i++){
            if(tmp[i] == 1) {
                // A 주사위
                a.push_back(dice_kind[i]);
            } else {
                // B 주사위
                b.push_back(dice_kind[i]);
            }
        }
        int tot_cnt = 1;
        for(int i = 0 ; i < dice_cnt/2  ; i++) tot_cnt *= 6;

        
            vector<int> asum_tot, bsum_tot ; 

            for(int j = 0 ; j < tot_cnt ; j++) {
                  auto t = decimalToBase6(j,dice_cnt/2);       
                  int a_sum = 0 ;
                  int b_sum = 0 ;
            

            for(int l = 0 ; l < dice_cnt/2 ; l++){
                a_sum += dice[a[l]-1][t[l]];
                b_sum += dice[b[l]-1][t[l]];
            }
            asum_tot.push_back(a_sum);
            bsum_tot.push_back(b_sum);
        }      
            sort(asum_tot.begin(), asum_tot.end());
	        sort(bsum_tot.begin(), bsum_tot.end());
        
        int tmp_cnt = 0 ;
        for(int i = 0 ; i < bsum_tot.size() ; i++) {
            tmp_cnt += asum_tot.end() - upper_bound(asum_tot.begin(), asum_tot.end(), bsum_tot[i]);
        }
        
        if(max_cnt < tmp_cnt) {
            max_cnt = tmp_cnt ;
            answer = a; 
        }
    } while(prev_permutation(tmp.begin(),tmp.end()));
    return answer;
}

/*
[문제이해]
A는 승리할 확률이 가자 높아지도록 주사위를 가져가려고 함.
A가 골라야하는 주사위 번호 오름차순으로 1차원 배열에 담아 리턴.

[제약]
- 승리할 확률이 가장 높은 주사위 조합이 유일한 경우만 주어짐.

*/