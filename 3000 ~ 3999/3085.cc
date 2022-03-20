// 2022-02-15 00:36:46
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

using namespace std;

int n;
char d[51][51];
int dx[2]={0,1}, dy[2]={1,0};
int ck(int x, int y){
    int maxx = 1, s = 1, w = 1;
    for(int i=1;i<n;i++){
        if(d[x][i] == d[x][i-1]){
            s++;
        }else{
            s=1;
        }
        if(d[i][y] == d[i-1][y]){
            w++;
        }else{
            w=1;
        }
        maxx = max(maxx, max(s, w));
    }
    return maxx;
}

int func(int x, int y){
    int maxx = 0;
    for(int i=0;i<2;i++){
        if(x+dx[i]==n || y+dy[i]==n) continue;
        swap(d[x][y],d[x+dx[i]][y+dy[i]]);
        maxx = max(maxx, ck(x, y));
        maxx = max(maxx, ck(x+dx[i], y+dy[i]));
        swap(d[x][y],d[x+dx[i]][y+dy[i]]);
    }
    return maxx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    }
    int maxx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                maxx = max(maxx, ck(i,j));
            }
            maxx = max(maxx, func(i,j));
        }
    }
    cout << maxx;
}