#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
#define pb push_back
#define rg(e, s, t) s <= e && e < t
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name;
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size());

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const int INF = (int)2e9;
const int MOD = (int)1e9 + 9;
const double EPS = 1e-10;

#define MAX_N 1005

ll combi[MAX_N+2][MAX_N+2];

void makeCombiMod(){
    rep(i, 0, MAX_N+1) combi[i][0] = 1;
    rep(i, 1, MAX_N+1) combi[0][i] = 0;
    rep(i, 1, MAX_N+1){
        rep(j, 1, i+1) combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % MOD;
    }
}


int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
        return g;
}

int mod_inverse(int a){
    int x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x % MOD) % MOD;
}

ll B[MAX_N+2];
void initBernoulliMod(){
    makeCombiMod();
    Rep(i, MAX_N+1){
        if(i % 2) B[i] = 0;
        else B[i] = -INF;
    }
    B[0] = 1;
    B[1] = -mod_inverse(2) + MOD;
}

int BernoulliMod(int n){
  if(B[n] == -INF){
    ll sum = (1 + combi[n+1][1] * B[1]) % MOD;
    for(int i = 2; i < n; i+= 2) sum = (sum + (combi[n+1][i] * BernoulliMod(i) % MOD)) % MOD;
    B[n] = sum * mod_inverse(n+1) % MOD;
    B[n] *= -1;
    while(B[n] < 0) B[n] += MOD;
  }
  return B[n];
}

int powMod(ll n, int p){
  ll ans = 1, ln = n % MOD;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = (ans*ln) % MOD;
	ln = (ln * ln) % MOD;
	p = p >> 1;
  }
  return (int)ans;
}

int faulhaberMod(int k, ll n){
  ll ans = 0;
  Rep(j, k+1){
    if(j % 2) ans = (ans - ((combi[k+1][j] * BernoulliMod(j) % MOD) * powMod(n, k+1-j) % MOD) + MOD) % MOD;
    else ans = (ans + ((combi[k+1][j] * BernoulliMod(j) % MOD) * powMod(n, k+1-j) % MOD)) % MOD;
  }
  ans = ans * mod_inverse(k+1) % MOD;
  return (int)ans;
}

void solve(){
  int k;
  ll n;
  cin >> n >> k;
  cout << faulhaberMod(k, n) << endl;
}

void doIt(){
  int t;
  initBernoulliMod();
  cin >> t;
  while(t--){
    solve();
  }
}

void test(){
  initBernoulliMod();
  cout << faulhaberMod(3, 5) << endl;;
}

int main() {
  doIt();
  return 0;
}
