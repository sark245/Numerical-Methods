//
// Created by sark2 on 01-01-2020.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

//f(x) = 3x+5
//Change f(x) as required!!

ld f(ld x){
    return 3*x + 5;
}


ld method_of_bisection(ld x0, ld x1, int n, ld eps){

    for(int i = 0; i < n; i++) {
        if (f(x0) * f(x1) > 0) {
            cout << "Invalid\n";
            return -1;
        }
        ld x2 = (x0 + x1)/2.0;

        if (fabs(f(x2)) < eps) {
            cout << "Solution found\n";
            return x2;
        }


        if (f(x0) * f(x2) < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }


    }


}

int main() {
    IOS

    cout<<fixed<<setprecision(6)<<method_of_bisection(-2, -1, 1000, 1e-7)<<"\n";



}
