// 2022-03-07 12:47:15
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int> d;

int main(){
    long long n;
    cin >> n;
    d.push_back(0);
    d.push_back(1);
    d.push_back(2);
    d.push_back(2);
    if(n <= 3){
        if(n == 1){
            cout << 1;
        }else{
            cout << 2;
        }
        return 0;
    }
    int cnt = 4000000;
    n -= 3;
    for(long long i = 3;1;i++){
        n -= (long long)d[i];
        if(n <= 0){
            cout << i;
            return 0;
        }
        for(int j=1;j<=d[i] && cnt;j++){
            d.push_back(i);
            cnt--;
        }
    }
}