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

int n;
ll ai;

ll sums[500100];
ll apps[500100];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    cin >> ai;
    sums[0] = ai;
    for(int i = 1; i < n; ++i)
    {
        cin >> ai;
        sums[i] += sums[i-1] + ai;
    }

    if (sums[n-1] % 3LL)
    {
        cout << 0 << endl;
        return 0;
    }

    ll obj = sums[n-1] / 3LL;

    if (sums[0] == obj) apps[0] = 1;

    for(int i = 1; i < n; ++i)
    {
        apps[i] = apps[i-1];
        if (sums[i] == obj) apps[i] = apps[i] + 1;
    }

    ll contar = 0;
    for(int i = 1; i < n-1; ++i)
    {
        if (sums[i] == obj*2) contar += apps[i-1];
    }

    cout << contar << endl;

    return 0;
}

