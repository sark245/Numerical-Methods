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

int RegulaFalsi(ld x0, ld x1, ld eps, int n){
    for(int i = 1; i <= n; i++){
        if(f(x1) * f(x0) > 0){
            cout<<"Incorrect Range !!\n";
            return -1;
        }
        if(fabs(f(x1)-f(x0)) < eps){
            cout<<"Method Fails!!!\n";
            return -1;
        }
        ld x2 = (x0*f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        if(fabs(f(x2)) < eps){
            cout<<fixed<<setprecision(6)<<x2<<" is the root !!\n";
            return 0;
        }
        if(f(x0) * f(x2) < 0){
            x1 = x2;
        }else{
            x0 = x2;
        }
    }
}


int main() {

    int n;
    ld x0, x1, eps;
    cin>>n>>x0>>x1>>eps;

    RegulaFalsi(x0, x1, eps, n);


}
