//
// Created by sark2 on 10-01-2020.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ld f(ld x){
    return sin(x);
}

ld f_dash(ld x){
    return cos(x);
}

int Newton_Raphson_Method(ld x0, ld eps, int n){
    for(int i = 1; i <= n; i++){
        if(fabs(f_dash(x0)) < eps){
            cout<<"Method Fails !!\n";
            return -1;
        }
        ld x1 = x0 - f(x0)/ f_dash(x0);
        if(fabs(f(x1)) < eps){
            cout<<x1<<" is the solution!!\n";
            return 0;
        }
        x0 = x1;
    }
}


int main() {

    
    int n;
    ld eps, x0;

    cin>>x0>>eps>>n;

    Newton_Raphson_Method(x0, eps, n);

}
