#include <bits/stdc++.h>
using namespace std;

//string s;
//getline(cin, s);

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> maxPq;
typedef priority_queue<ll, vector<ll>, greater<ll> > minPq;
typedef deque<int> dq;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forVar(type, var, init, till, increment) for (type var = init; var < till; var += increment)
#define deb(x) cout << x << endl;
#define MAX 5 * 10000 + 1
#define INF 10000000000
#define endl '\n'

ll sums[5010];
ll nums[5010];
ll dp_0[5010];
ll dp_1[5010];
int n, m, k;
ll curr;

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> curr;
        nums[i] = curr;
    }
    memset(sums, -1, sizeof(sums));

    ll ini = 0;
    for(int i = 0; i < m; ++i)
    {
        ini += nums[i];
    }

    sums[m-1] = ini;

    int j = 0;

    for(int i = m; i < n; ++i)
    {
        sums[i] = sums[i-1] - nums[j] + nums[i];
        ++j;
    }

    for(j = 0; j <= k; ++j)
    {
        if(j%2 == 0)
        {
            for(int i = 0; i < n; ++i)
            {
                if (j == 0 || i < m-1)
                {
                    dp_0[i] = 0;
                }
                else if (i == m-1)
                {
                    dp_0[i] = sums[i];
                }
                else
                {
                    dp_0[i] = max(dp_0[i-1], dp_1[i-m] + sums[i]);
                }
            }
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                if (j == 0 || i < m-1)
                {
                    dp_1[i] = 0;
                }
                else if (i == m-1)
                {
                    dp_1[i] = sums[i];
                }
                else
                {
                    dp_1[i] = max(dp_1[i-1], dp_0[i-m] + sums[i]);
                }
            }
        }
    }

    if(k%2 == 0) cout << dp_0[n-1] << endl;
    else cout << dp_1[n-1] << endl;

    return 0;
}
