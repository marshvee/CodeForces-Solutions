#include <bits/stdc++.h>

using namespace std;

int n;
long int st, in, xp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> st >> in >> xp;

        long int dif = in - st;

        if(dif >= xp) cout << 0 << endl;
        else if (dif >= 0)
        {
            xp = xp - dif - 1;
            st = st + dif + 1;

            cout << min((st+xp-in+(st+xp-in)%2)/2 , xp+1) << endl;
        }
        else
        {
            cout << min((st+xp-in+(st+xp-in)%2)/2 , xp+1) << endl;
        }
    }
    return 0;
}
