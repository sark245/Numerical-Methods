//Median of two sorted arrays of same size in O(log(n))
//Used Divide And Conquer Technique
//Example: 
/* 
    Size of Array = 5
  Array 1 = {1, 12, 15, 26, 38}
  Array 2 = {2, 13, 17, 30, 45}
  Median = 16
  
*/


//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    
int findMedian(int arr[], int n){
    if(n & 1){
        return arr[n/2];
    }
    else{
        return (arr[(n-1)/2] + arr[n/2])/2;
    }
}
int getMedian(int arr1[], int arr2[], int n){
    if(n <= 0)return -1;
    if(n == 1)return (arr1[0] + arr2[0]) / 2;

    if(n == 2)return (max(arr1[0], arr2[0]) + min(arr1[1] , arr2[1])) / 2;

    int m1 = findMedian(arr1, n);
    int m2 = findMedian(arr2, n);

    if(m1 == m2)return m1;
    else if(m1 > m2){
        if(n & 1) return getMedian(arr1, arr2 + n/2, n - n/2);
        else return getMedian(arr1, arr2 + n/2 - 1, n - n/2 + 1);
        
    }else{
        if(n & 1) return getMedian(arr1 + n/2, arr2, n - n/2);
        else return getMedian(arr1 + n/2 - 1, arr2, n - n /2 + 1);
    }

}


int main(){
   IOS

   int n; cin>>n;
   int a1[n], a2[n];

   for(int i = 0; i < n; i++)cin>>a1[i];
   for(int i = 0; i < n; i++)cin>>a2[i];

   cout<<getMedian(a1, a2, n)<<"\n";


}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

