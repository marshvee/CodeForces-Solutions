#include <bits/stdc++.h>

using namespace std;

int t, n;
long int x, d, h, maxdif_d, maxdif_h, maxhit, resp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n >> x;
        maxdif_d = 0;
        maxdif_h = 0;
        maxhit = 0;

        for(int j=0; j<n; j++)
        {
            cin >> d >> h;

            if(d - h > maxdif_d - maxdif_h)
            {
                maxdif_d = d;
                maxdif_h = h;
            }

            if(d > maxhit) maxhit = d;
        }

        if(maxdif_d - maxdif_h == 0 && maxhit < x) cout << -1 << endl;
        else
        {
            resp = 0;
            if(maxhit>=x)
            {
                resp = 1;
            }
            else
            {
                x = x - maxhit;
                resp = ceil(double(x)/double(maxdif_d - maxdif_h)) + 1;
            }
            cout << resp << endl;
        }

    }
    return 0;
}
