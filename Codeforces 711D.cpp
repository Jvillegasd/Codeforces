#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>
#define MOD 1000000007

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];
vector<int> g[200010], rg[200010];
stack<int> s;
bool vist[200010];
lli cnt;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u){
    vist[u] = 1;
    for(auto v : g[u]) if(!vist[v]) DFS(v);
    s.push(u);
}

void DFS2(int u){
    vist[u] = 1;
    cnt++;
    for(auto v : rg[u]) if(!vist[v]) DFS2(v);
}

void SSC(int n){
    lli ans=1;
    for(int u = 1; u <= n; u++) if(!vist[u]) DFS(u);
    memset(vist, 0, sizeof(vist));
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(vist[u]) continue;
        cnt=0;
        DFS2(u);
        if(cnt > 1) ans=(ans*(modPow(2, cnt)-2))%MOD;
        else if(cnt == 1) ans=(ans*modPow(2, cnt)%MOD);
    }
    printf("%lld", ans);
}

int main(){
    int n, v;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++) scanf("%d", &v), dEdge(u, v), rg[v].pb(u);
    SSC(n);
    return 0;
}
