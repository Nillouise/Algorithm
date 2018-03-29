#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=(a);i<=(int)(n);++i)
#define lpd(i,a,n) for(int i=(a);i>=(int)(n);--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define readll(x) scanf("%I64d",&x)
#define mod 1000000007
#define eps 1e-6
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 104;
int t,hd,ad,hk,ak,b,d,dp[N][N][N][N];

int solve(int i, int j, int k, int l){
    if(k < 1) return 0;
    if(i < 1) return infi;
    int &ret = dp[i][j][k][l];
    if(ret != -1) return ret;

    ret = infi;
    ret = solve(i - l, j, k - j, l);
    if(j < k and b) ret = min(ret, solve(i - l, min(j + b, k+1), k, l));
    ret = min(ret, solve(hd - l, j, k, l));
    if(l and d) ret = min(ret, solve(i - max(0, l - d), j, k, max(0, l - d)));
    return ++ret;
}

int main() {
    freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    freopen("output.txt","w",stdout);

    readi(t);
    lp(test,1,t){
        scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
        printf("Case #%d: ",test);
        mem(dp,-1);
        int ans = solve(hd,ad,hk,ak);
        if(ans >= infi) puts("IMPOSSIBLE");
        else printf("%d\n",ans);
    }
}

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios::sync_with_stdio(0);cin.tie(0);
