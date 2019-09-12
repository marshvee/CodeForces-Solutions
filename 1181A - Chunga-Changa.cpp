//Sebastian Lemus - Mariana Rodriguez
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x, y, z;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y >> z;

    cout << (x+y)/z << " ";

    if((x%z == 0 && y%z == 0) || (x%z + y%z < z))
    {
        cout << 0 << endl;
        return 0;
    }
    cout << z - max(x%z,y%z) << endl;

    return 0;
}
