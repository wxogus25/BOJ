// 2022-02-17 22:45:35
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>
#include <string.h>

using namespace std;

int n, len, ls[110], dp[110];
char s[110], d[110][110];

bool func(int now){
    if(now == len){
        return true;
    }
    int &res = dp[now];
    if(res != -1){
        return res;
    }
    res = false;
    char temp;
    int slen;
    for(int i=0;i<n;i++){
        slen = ls[i];
        if(len-now < slen){
            continue;
        }
        temp = s[now+slen];
        s[now+slen] = '\0';
        if(strcmp(d[i],s+now) == 0){
            s[now+slen]=temp;
            if(func(now+slen)){
                return res = true;
            }
        }
        s[now+slen]=temp;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    len = strlen(s);
    fill(dp,dp+len,-1);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d[i];
        ls[i] = strlen(d[i]);
    }
    cout << func(0) << endl;
}