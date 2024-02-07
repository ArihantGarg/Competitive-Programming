#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define cin std::cin
#define cout std::cout
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);
// #define int ll
#define ll long long
#define ld double
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define pi pair<ll, ll>
#define pb push_back
#define sqrt sqrtl
#define pow powl
#define __builtin_popcount __builtin_popcountll
#define MOD 1000000007LL
#define inf 1000000000000000000LL
#define debug(x) cout << x << '\n';
#define debug2(x, y) cout << x << " " << y << '\n';
#define debug3(x, y, z) cout << x << " " << y << " " << z << '\n';
#define all(x) x.begin(), x.end()
#define abs llabs

#ifndef ONLINE_JUDGE
#define Log(x) cerr << "Debug: " << x
#else
#define Log(x) 0
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll min(ll a, ll b)
{
    if (a < b)
        return a;

    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;

    return b;
}

ll hcf(ll a, ll b)
{
    if (b == 0LL)
        return a;

    return hcf(b, a % b);
}

ll lcm(ll a, ll b) { return ((a * b) / hcf(a, b)); };

ll countbit(ll x) { return __builtin_popcountll(x); }

string binary(ll n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');
    if (loc1 != string::npos)
    {
        return s.substr(loc1);
    }
    return "0";
}

ll decimal(string s) { return stoll(s); }

//

ll modinv(ll p, ll q)
{
    p %= MOD;
    q %= MOD;
    ll expo = MOD - 2;
    while (expo)
    {
        if (expo & 1)
            p = (p * q) % MOD;
        q = (q * q) % MOD;
        expo >>= 1;
    }
    return p;
}

ll binexp(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//

ll kmp(string txt, string pat)
{
    vector<ll> ans;

    ll n = txt.size(), m = pat.size();

    ll prefix[m], q = 0, len = 0, curr = 1;

    prefix[0] = 0;

    while (curr < m)
    {
        if (pat[curr] == pat[len])
        {
            len++;
            prefix[curr] = len;
            curr++;
        }
        else if (len != 0)
        {
            len = prefix[len - 1];
        }
        else
        {
            prefix[curr] = 0;
            curr++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pat[q] != txt[i])
            q = prefix[q - 1];

        if (pat[q] == txt[i])
            q++;

        if (q == m)
        {
            ans.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }

    return ans.size();
}

//

const ll N = 300005;
vector<bool> VISI;
vvi divisors;
vi primes;

void Sieve()
{
    VISI.assign(N, 1);

    VISI[0] = VISI[1] = false;
    for (ll i = 4; i < N; i += 2)
        VISI[i] = false;
    for (ll i = 3; i < N / i; i += 2)
    {
        if (!VISI[i])
            continue;
        for (ll j = i * i; j < N; j += i + i)
            VISI[j] = false;
    }
}

void Gen()
{
    for (ll i = 2; i < N; i++)
        if (VISI[i])
            primes.pb(i);

    // divisors.assign(N, {});
    // for (ll i = 1; i < N; i++)
    //     for (ll j = i; j < N; j += i)
    //         divisors[j].pb(i);
}

//

vi fact, facti;

void Fact()
{
    fact.resize(N);
    facti.resize(N);

    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;

    facti[N - 1] = modinv(1, fact[N - 1]);
    for (ll i = N - 2; i >= 0; i--)
        facti[i] = ((i + 1) * facti[i + 1]) % MOD;
}

ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;

    ll temp = fact[n] * facti[r] % MOD;
    temp = temp * facti[n - r] % MOD;
    return temp;
}

//

vi parentt, siz;

void make_set(int n)
{
    parentt.assign(n + 1, 0);
    siz.assign(n + 1, 1);

    for (ll i = 0; i <= n; i++)
        parentt[i] = i;
}

ll find_set(int v)
{
    if (v == parentt[v])
        return v;
    return parentt[v] = find_set(parentt[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parentt[b] = a;
        siz[a] += siz[b];
    }
}

//

vvi adj;
vi vis1;
vi vis2;
vi par1;
vi par2;
vi dist1;
vi dist2;

void create_graph(ll n)
{
    adj.assign(n + 1, {});
    vis1.assign(n + 1, 0);
    vis2.assign(n + 1, 0);
    par1.assign(n + 1, -1);
    par2.assign(n + 1, -1);
    dist1.assign(n + 1, inf);
    dist2.assign(n + 1, inf);
}

// void dfs(ll curr, vi &vis,ll dis)
// {

//     if (vis[curr] == 1)
//         return;

//     vis[curr] = 1;

//     for (auto x : adj[curr])
//     {

//         if (!vis[x])
//         {
//             dfs(x, vis,dis+1);
//         }
//     }

//     return;
// }

void bfs(ll curr, vi &vis, vi &par, vi &dist)
{
    queue<ll> q;

    vis[curr] = 1;
    dist[curr] = 0;
    q.push(curr);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto x : adj[u])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                par[x] = u;
                dist[x] = 1 + dist[u];
                q.push(x);
            }
        }
    }
}

// void djikstra(ll curr)
// {
//     dist2[curr]=0;

//     priority_queue<pi,vector<pi>,greater<pi>> pq;

//     pq.push({0,curr});

//     while(!pq.empty())
//     {
//         int u=pq.top().second;
//         int distance=pq.top().first;

//         pq.pop();

//         if(dist2[u]==distance)
//         {
//             for(auto [x,weight]:adj[u])
//             {
//                 if(dist2[x]>dist2[u]+weight)
//                 {
//                     dist2[x]=dist2[u]+weight;
//                     par2[x]=u;

//                     pq.push({dist2[x],x});
//                 }
//             }
//         }
//     }
// }

//

/*                  CODE      STARTS       HERE        */



void solve()
{
    

    cout << "\n";
}

signed main()
{
    fast_io;

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}