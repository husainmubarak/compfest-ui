#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] < 0){
            a[i] += a[i] * -2;
        }
    }

    sort(a, a+n);
    cout<<a[0];
}