//
// Created by sark2 on 17-01-2020.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    IOS

    int n; cin>>n;

    ld a[n+5][n+5];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+1; j++){
            cin>>a[i][j];
        }
    }

    cout<<"A : \n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<a[i][j]<<" ";
        }cout<<"\n";
    }

    cout<<"\nB : \n";
    for(int i = 1; i <= n; i++){
        cout<<a[i][n+1]<<"\n";
    }
    for(int k = 1; k <= n-1; k++){
        for(int i = k+1; i <= n; i++){
            ld u = a[i][k]/a[k][k];
            for(int j = k; j <= n+1; j++){
                a[i][j] -= u*a[k][j];
            }
        }
    }

    ld x[n+5];

    x[n] = a[n][n+1]/a[n][n];

    for(int i = n-1; i >= 1; --i){
        ld sum = 0;
        for(int j = i+1; j <= n; j++){
            sum += a[i][j]*x[j];
        }
        x[i] = (a[i][n+1] - sum)/a[i][i];
    }


    cout<<"\nX: \n";
    for(int i = 1; i <= n; i++){
        cout<<x[i]<<"\n";
    }


}
