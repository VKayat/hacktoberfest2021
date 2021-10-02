/* Code by - Sahil Sarwar */

#include <algorithm>
#include <bits/stdc++.h>
#include <time.h>
#include <numeric>

using namespace std;

// Debug templates

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// debug template ends

#define ll long long
#define w(t) while (t--)
#define vec vector
#define vi vector<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int, vector<int>, greater<int>>
#define ins insert
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a)  //will give no. of elements strictly lesser than a
#define pii pair<int, int>
#define _decint greater<int>()
#define _decll greater<ll>()
#define mem(a, x) memset(a, x, sizeof(a))
#define vll vector<long long>
#define pll pair<long long, long long>
#define pb push_back
#define all(c) c.begin(), c.end()
#define all_ar(ar, n) ar, ar + n
#define For(i, a, b) for (size_t i = a; i < b; ++i)
#define Rof(i, a, b) for (size_t i = a; i >= b; i--)
#define print_ar(ar, n)            \
    for (size_t i = 0; i < n; i++) \
    {                              \
        cout << ar[i] << " ";      \
    }
#define out(x) cout << x << endl
#define out__(x, y) cout << x << " " << y << endl
#define inarr(arr, n) For(i, 0, n) cin >> arr[i]
#define mx_a(arr, n) max_element(arr, arr + n)
#define mn_a(arr, n) min_element(arr, arr + n)
#define mx_c(container) max_element(container.begin(), container.end())
#define mn_c(container) min_element(container.begin(), container.end())
#define un_m unordered_map
#define F first
#define S second
#define not_found string::npos
#define vec_2d vector<vector<int>>

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll INF = 1e18;
const int MOD = 1e9 + 7;

inline int64_t mul(int64_t a, int64_t b)
{
    return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
    return (a + b >= INF ? INF : a + b);
}

// dsu class ---- starts here
class dsu
{
private:
    vector<int> parent;
    vector<int> siz;

public:
    dsu(vector<int> parent, vector<int> siz)
    {
        this->parent = parent;
        this->siz = siz;
    }

    void make_set(int v)
    {
        parent[v] = v;
        siz[v] = 1;
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
};

vector<bool> sieve(ll n)
{
    vector<bool> isPrime(n + 1, 0);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // after this, all the numbers which are primes are marked as 1
    return isPrime;
}

bool isPerfectSquare(ll x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0)
    {

        long long sr = sqrt(x);

        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

bool isPrime(ll n)
{
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// a to power b
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    stack<pii> st;
    int ar[n];
    inarr(ar, n);
    vi res(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            while (st.top().first >= ar[i])
            {
                st.pop();
                if (st.empty())
                    break;
            }
        }
        if (st.empty())
            res[i] = 0;
        else
            res[i] = st.top().second;
        st.push({ar[i], i + 1});
        // debug(res);
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;

    clock_t p;
    p = clock();
    w(t)
    {

        // each iteration takes this time
        // p = clock() - p;
        // cerr << "time : " << float(p)/CLOCKS_PER_SEC << " sec\n";
        solve();
    }

    return 0;
}