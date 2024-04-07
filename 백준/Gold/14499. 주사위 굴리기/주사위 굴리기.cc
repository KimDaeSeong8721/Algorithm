#include <iostream>
#include <algorithm>
using namespace std;

// 주사위 굴리기.

int n, m ; // 지도 세로, 가로 길이
int x, y ; //  주사위 좌표
int k ; // 명령의 개수
int arr[21][21];

int vDice[4];
int hDice[4];


void writeNum(int a[]) { // a는 명령에 의해 먼저 변경되는 주사위 배열.
    if(arr[x][y] != 0){
        a[0] = arr[x][y];
        arr[x][y] = 0 ;
    }
    else {
        arr[x][y] = a[0];
    }
}

void copyNum(int a[], int b[]) {
    b[0] = a[0];
    b[2] = a[2];
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m >> x >> y >> k ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> arr[i][j];
 

    while (k--)
    {
        int cmd ;
        cin >> cmd ;

        if(cmd == 1) {
            if(y == m-1) continue;
            rotate(hDice,hDice+1,hDice+4);
            y++;
            writeNum(hDice);
            copyNum(hDice,vDice);
        }
        else if(cmd == 2) {
            if(y == 0) continue;
            rotate(hDice,hDice+4-1,hDice+4);
            y--;
            writeNum(hDice);
            copyNum(hDice,vDice);

        }
        else if(cmd == 3) {
            if(x == 0) continue;
            rotate(vDice,vDice+4-1,vDice+4);
            x--;
            writeNum(vDice);
            copyNum(vDice,hDice);

        }
        else if(cmd == 4) {
            if(x == n-1) continue;
            rotate(vDice,vDice+1,vDice+4);
            x++;
            writeNum(vDice);
            copyNum(vDice,hDice);

        }

        cout << vDice[2] <<'\n';


    }
    
}

/*
[해결전략 참고]

[시작]
- 4월 7일 오후 7시51분
[배울 점]
- 문제를 차근차근 생각하고, 특정 방법이 떠올랐다면 직접 손으로 써가며 순차적으로 생각하면서 패턴 찾기.

[문제 이해]
동 - 1 , 서 - 2 , 북 -3 ,남 - 4
- 지도 위의 칸의 수가 0이면, 주사위 바닥면의 수로 복사됨.
- 지도 위의 칸의 수가 0이 아니면, 주사위 바닥면의 수에 복사되고 칸은 0으로 됨.
주사위를 어떻게 표현할 것인가

[입력]
- n , m , x, y , k
- 지도 위의 숫자들
- 명령어 k개 

[제약]
- 바깥 이동 불가.
- 초기 주사위 칸 값은 모두 0 
[출력]
- 이동할 때마다 주사위 윗 면에 쓰인 수 출력

[풀이전략]
1.주사위 평행 배열과 수직 배열을 각각 만든다.
2. 명령에 맞는 배열을 적절히 회전시킨다.
3. 주사위 좌표 업데이트 한다.
4. 지도위의 칸이 0 조건에따라 주사위 바닥면 및 지도위의 칸 업데이트 한다.
5. 남은 배열의 윗면과 아랫면을 업데이트한다.
6. 지도 바깥을 나가지못하는 조건을 설정한다.
*/
