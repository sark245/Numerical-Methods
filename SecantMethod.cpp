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
    return x*x + 2*x + 1;
}

int secantMethod(ld x0, ld x1, ld eps, int n){
    for(int i = 1; i <= n; i++){
        if(fabs(f(x1)-f(x0)) < eps){
            cout<<"Secant Method Fails!!!\n";
            return -1;
        }
        ld x2 = (x0*f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        if(fabs(f(x2)) < eps){
            cout<<fixed<<setprecision(6)<<x2<<" is the root !!\n";
            return 0;
        }
        x0 = x1;
        x1 = x2;
    }
}


int main() {
    IOS

    secantMethod(-5, 4, 1e-6, 1000);


}
