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

ll n;
int curr;
ll freq[100010];
ll dp[100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> curr;
        ++freq[curr];
        maxi = max(maxi, curr);
    }

    dp[0] = 0;
    dp[1] = freq[1];
    for(int i = 2; i <= maxi; ++i)
    {
        ll val = freq[i] * ll(i);
        dp[i] = max(dp[i-1], dp[i-2] + val);
    }

    cout << dp[maxi] << endl;
}
