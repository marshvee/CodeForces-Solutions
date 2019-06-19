#include <bits/stdc++.h>

using namespace std;

int subtract(int n, int k) {
    if(k==0) 
        return n;
        
    if(n%10!=0)
        subtract(n-1,k-1);
    else
        subtract(n/10,k-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
        
    cout << subtract(n,k) << endl; 

    return 0;
}