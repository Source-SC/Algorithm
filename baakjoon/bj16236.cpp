/*
1h 3m

그래프 - bfs 응용

아기상어 문제. 이문제는 현위치에서 조건에 맞는 bfs를 수행한후, 이동하여 정해진 조건 내에서 계속 bfs를 수행한다.

일반적으로는 bfs를 한번 수행하는데 여러번 수행하는 과정에서 많은 고민이 필요했음.

*/

#include <iostream>
#include <queue>

using namespace std;

struct Location{
    int i;
    int j;
};

struct cmp{
    bool operator()(Location a, Location b){
        if(a.i != b.i){
            return a.i > b.i;
        }
        else{
            return a.j > b.j;
        }
    }
};

priority_queue<Location, vector<Location>, cmp> pq1;
priority_queue<Location, vector<Location>, cmp> pq2;


int n;
int map[21][21];
int visited[21][21];

void reset_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
}

int shark(int now_i, int now_j, int level, int eat){
    // now_i,now_j 에서 먹을수있는 물고기 위치로 이동
    // 한 shark 함수 사이클에서는 한번에 한마리를 먹어야한다.
    while(!pq1.empty()){ pq1.pop();}
    while(!pq2.empty()){ pq2.pop();}
    reset_visited();
    Location now;
    Location tmp;
    tmp.i = now_i;
    tmp.j = now_j;
    pq1.push(tmp);

    if(level == eat){
        level++;
        eat = 0;
    }
    int move = 0;
    while(!pq1.empty()){
        now = pq1.top();
        pq1.pop();
        if(map[now.i][now.j] != 0 && map[now.i][now.j] < level){
            map[now.i][now.j] = 0;
            return shark(now.i,now.j,level,eat+1) + move;
        }

        if(now.i > 0){ // 위로 이동가능하면서, 물고기 크기가 자신보다 작을때
            if(map[now.i-1][now.j] <= level && visited[now.i-1][now.j] == 0){
                visited[now.i-1][now.j] = 1;
                tmp.i = now.i-1;
                tmp.j = now.j;
                pq2.push(tmp);
            }
        }
        if(now.i < (n-1) && visited[now.i+1][now.j] == 0){ // 아래로 이동가능하면서, 물고기 크기가 자신보다 작을때
            if(map[now.i+1][now.j] <= level){
                visited[now.i+1][now.j] = 1;
                tmp.i = now.i+1;
                tmp.j = now.j;
                pq2.push(tmp);
            }
        }
        if(now.j > 0 && visited[now.i][now.j-1] == 0){ // 왼쪽 이동가능하면서, 물고기 크기가 자신보다 작을때
            if(map[now.i][now.j-1] <= level){
                visited[now.i][now.j-1] = 1;
                tmp.i = now.i;
                tmp.j = now.j-1;
                pq2.push(tmp);
            }
        }
        if(now.j < (n-1) && visited[now.i][now.j+1] == 0){ // 오르쪽 이동가능하면서, 물고기 크기가 자신보다 작을때
            if(map[now.i][now.j+1] <= level){
                visited[now.i][now.j+1] = 1;
                tmp.i = now.i;
                tmp.j = now.j+1;
                pq2.push(tmp);
            }
        }
        
        if(pq1.size() == 0){
            pq1 = pq2;
            while(pq2.size() > 0){pq2.pop();}
            move++;
        }
    }
    return 0;
}

int main(){
    int start_i, start_j;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                start_i = i;
                start_j = j;
                map[i][j] = 0;
            }
        }
    }
    cout << shark(start_i,start_j,2,0);
}