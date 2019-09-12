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

int n, k;

vector<ll> nums;
ll curr;
string s;
char ult;
int x;
int chars[3];
bool posibles[4];
int main()
{
    cin >> s;

    for(int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '?') ++chars[2];
        else ++chars[s[i] - '0'];
    }

    ult = s[s.length()-1];

    if(chars[2] == 0)
    {
        if(chars[1] < chars[0]) posibles[0] = true;
        else if(chars[1] > chars[0] + 1) posibles[3] = true;
        else if(ult == '1') posibles[1] = true;
        else if(ult == '0') posibles[2] = true;
    }
    else
    {
        //cout << chars[0] << chars[1] << chars[2];
        if(chars[1] < chars[0] + chars[2]) posibles[0] = true;
        if(chars[0] + 1 < chars[1] + chars[2]) posibles[3] = true;

        if(ult == '1')
        {
            x = (chars[0] + chars[2] - chars[1] + (chars[1] + chars[2] + chars[0])%2 )/2;
            if(x>=0 && x<=chars[2]) posibles[1] = true;
        }
        else if(ult == '?')
        {
            chars[2]--; chars[1]++;
            x = (chars[0] + chars[2] - chars[1] + (chars[1] + chars[2] + chars[0])%2 )/2;
            if(x>=0 && x<=chars[2]) posibles[1] = true;
            chars[2]++; chars[1]--;
        }

        if(ult == '0')
        {
            x = (chars[0] + chars[2] - chars[1] + (chars[1] + chars[2] + chars[0])%2 )/2;
            if(x>=0 && x<=chars[2]) posibles[2] = true;
        }
        else if(ult == '?')
        {
            chars[2]--; chars[0]++;
            x = (chars[0] + chars[2] - chars[1] + (chars[1] + chars[2] + chars[0])%2 )/2;
            if(x>=0 && x<=chars[2]) posibles[2] = true;
            chars[2]++; chars[0]--;
        }
    }

    if(posibles[0]) cout << "00" << endl;
    if(posibles[1]) cout << "01" << endl;
    if(posibles[2]) cout << "10" << endl;
    if(posibles[3]) cout << "11" << endl;

    return 0;
}
