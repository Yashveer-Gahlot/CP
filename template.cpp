#include<bits/stdc++.h>
using namespace std;
 
/* DATA_types and structures */
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define mii map<int, int>
#define mci map<char,int>
#define si set<int>
#define sc set<char>
#define vvi vector<vector<int>>
#define endl '\n'
#define ff first
#define ss second
#define INF 1e18
#define FAST_IO (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define ia(n) int a[n]
#define iton for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define MOD  1000000007
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
 
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}
 
/*------- Combinatorics Boilerplate Begin ---------- */
 
const int N = 1e6+100;
ll mod(ll a, ll m = MOD) {
    return a % m;
}
 
template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(ll n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (ll i = 1; i < n; i++) {
            fact[i] = mod(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = mod(res * base, m);
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans * invfact[n - k]);
        ans = mod(ans * invfact[k]);
        return ans;
    }
};
 
/*------- Combinatorics Boilerplate Ends ---------- */
 
 
struct Hash{
    const int BASE1=5689,BASE2=8861;
    vector<pair<int,int> > hashes,Pow;
 
    Hash(string s){
        hashes.assign(s.size()+1,{0,0});
        Pow.assign(s.size()+1,{1,1});
 
        for(int i=0;i<s.size();i++){
            hashes[i+1]= { ( 1ll * hashes[i].first * BASE1 + ( s[i] - 'a' + 1 )) % MOD,
                           ( 1ll * hashes[i].second * BASE2 + ( s[i] - 'a' + 1 )) % MOD };
 
            Pow[i+1]= { (1ll * Pow[i].first * BASE1) % MOD,
                        (1ll * Pow[i].second * BASE2) % MOD};
        }
    }
    pair<int,int> get(int l,int r){
        l++; r++;
 
        int hash1=(hashes[r].first -(1ll * hashes[l-1].first * Pow[r-l+1].first) % MOD + MOD);
        int hash2=(hashes[l].second -(1ll * hashes[l-1].second * Pow[r-l+1].second) % MOD + MOD);
 
        return {hash1,hash2};
    }
};
 
/* Functions  */
ll factorial(ll n) { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll nPr(ll n, ll r) { return factorial(n) / factorial(n - r); }
ll nCr(ll n, ll r) { return factorial(n) / (factorial(r) * factorial(n - r));}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b);}
ull mypow(ull a, ull b) { ull ans = 1; a%=MOD; while(b){ if (b&1) ans = (ans*a) % MOD; a = (a*a) % MOD; b >>= 1; } return ans; }
bool isPrime(ll n) { if(n <= 1) return false; for(ll i = 2; i*i <= n; i++) if(n % i == 0) return false; return true; } 
 
#define pb push_back
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
 
 
 
/*------- Number Theory Begins---------- */
 
 
ll binpow(ll a,ll b){
    ll res=1;
    a%=MOD;
    while(b>0){
        if(b&1) res=(res*a)%MOD; // if want to mod here 
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
 
const int LIMIT = 1e6 + 5;
vector<bool> is_prime(LIMIT, true);
 
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < LIMIT; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < LIMIT; j += i) {
 
                is_prime[j] = false;
            }
        }
    }
}
 
ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
 
bool d_equation(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = extended_gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
 
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
 
 
 
/*------- Number Theory Ends---------- */
 
 
 
// to delete a specific element from an vector
 
/* --------- Method -------------*/
// auto it=find(all(vi),x); 
//     if(it!=vi.end()){
//         vi.erase(it);
//     }
 
// ceil() func replacement 
// ceil(a/b)= a+b-1/b
 
  
 
 
/* ~~~~~~~~~~~ ZePhYeR_ ~~~~~~~~~~~~~~~~~~~*/
/*------------------------------------------*/ 





void solve() {
    
}



/*------------------------------------------*/
/*~~~~~~~~~~~~~~ ZePhYeR_ ~~~~~~~~~~~~~~~~~~~~~*/
 
 
 
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output1.txt","w",stdout);
    #endif
    FAST_IO;    

    // int t;cin>>t;
    // cin.ignore();
    int t=1;
    while(t--){
        solve();
    }

        
      
}
 













