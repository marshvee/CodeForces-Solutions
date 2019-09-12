#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    double x = (log2(b)-log2(a))/(log2(3)-1);
    cout << int(x+0.000000000000001)+1 << endl;

    return 0;
}
