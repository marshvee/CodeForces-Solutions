#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        const vector<int> denominations = {1, 5, 10, 20, 100};

        int n, i, bills;
        cin >> n;
        i = denominations.size()-1;
        bills = 0;

        while (n>0)
        {
            while (denominations[i] > n)
            {
                i = i-1;
            }
            bills = bills + n/denominations[i];
            n = n - int(n/denominations[i]) * denominations[i];
            i = i-1;
        }

        cout << bills << endl;

        return 0;
    }
