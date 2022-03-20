// 2022-02-24 17:33:07
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

typedef struct DATA{
    string ans;
    int now;
} leaf;

int D(int now){
    return (now*2)%10000;
}
int S(int now){
    return (now+9999)%10000;
}
int L(int now){
    return (now*10 + now/1000)%10000;
}
int R(int now){
    return (now/10 + (now%10)*1000)%10000;
}

char d[4]={'D','S','L','R'};
int (*fd[4])(int)={D,S,L,R};
bool check[10101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        leaf x; x.ans = ""; x.now = a;
        queue<leaf> q;
        q.push(x);
        check[a] = true;
        while(!q.empty()){
            leaf temp = q.front(), c;
            q.pop();
            int w, i;
            for(i=0;i<4;i++){
                w = fd[i](temp.now);
                if(check[w]){
                    continue;
                }
                string e = temp.ans + d[i];
                if(w == b){
                    cout << e << endl;
                    break;
                }
                c.ans = e; c.now = w;
                q.push(c);
                check[w] = true;
            }
            if(i != 4){
                break;
            }
        }
        fill(check,check+10101,false);
        for(;!q.empty();q.pop());
    }
}