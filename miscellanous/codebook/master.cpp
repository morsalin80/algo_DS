/// Bismillahir Rahmanir Rahim
/* Mohammad Morsalin
   Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define int long long
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ms2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,int>
#define tc(t) int t;cin>>t;while(t--)
#define bits(n) __builtin_popcount(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ins insert
#define ALL(v) v.begin(),v.end()
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define fi first
#define se second
#define PI acos(-1)
#define sz(a) (int)a.size();
#define IOS ios::sync_with_stdio(false);
using namespace std;
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
double sq(double x) {return x*x;}
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
///to compare in a priority queue;
struct myComp { 
    constexpr bool operator()( 
        pair<int, pair<int,int > > const& a, 
        pair<int, pair<int,int > > const& b) 
        const noexcept 
    { 
    	if(a.fi==b.fi) return a.se.fi<b.se.fi;
        return a.first > b.first; 
    } 
}; 
//Largest rectangle Area in a histogram in O(n)
 int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 


//points template
struct point
{
    double x, y;
    point() {}  //constructor
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double dist(point p) //euclidean distance
    {
        p.x -= x, p.y -= y;
        return sqrt(p.x*p.x + p.y*p.y);
    }
    void input()
    {
        double xx, yy;
        cin >> xx >> yy;
        x = xx;
        y = yy;
    }
    void leftmid(point p, point q) //leftmid point of the distance between these two point p, q
    {
        x = p.x + (q.x-p.x)/3.0;
        y = p.y + (q.y-p.y)/3.0;
    }
    void rightmid(point p, point q)//rightmid point of the distance between these two point p,q;
    {
        x = q.x - (q.x-p.x)/3.0;
        y = q.y - (q.y-p.y)/3.0;
    }
 
} a, b, c, d;

///gcd of two number in logn
    int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
///checking primes in sqrt(n)
bool prime(int n){
    bool pr=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            pr=0;
            break;
        }
    }
    return pr;
}
///seive
const int MAXN = 87000000;///maximum range as a array size
int Prime[MAXN];

vector<int> vec;
void seive(){

    vec.pb(2);
    for(int i = 3; i*i<MAXN; i+=2){
        if(Prime[i] == 0){
            for(int j = i*i; j < MAXN; j +=i){
                Prime[j] = 1;
            }
        }
    }
    for(int i=3;i<MAXN;i+=2){
        if(Prime[i]==0)vec.pb(i);
    }
}
///segmented seive
void segmentedSieve(ll L, ll R)
{
    bool isPrime[R-L+1];
    for(int i=0 ; i<=R-L+1 ; i++)
        isPrime[i]=true;


    if(L==1)
        isPrime[0]=false;
    for(int i=0 ; primes[i]*primes[i]<=R ; i++)
    {
        ll curPrime=primes[i];
        ll base=curPrime*curPrime;
        if(base<L)
        {
            base=((L+curPrime-1)/curPrime)*curPrime;
        }
        for(ll j=base ; j<=R ; j+=curPrime)
            isPrime[j-L]=false;
    }
    for(int i=0 ; i<=R-L ; i++)
    {
        if(isPrime[i]==true)
            cout<<L+i<<endl;
    }
    cout<<endl;
}
///prime factorisation of a number
vector<int>factors;
void primefactor(int n){
    while(n%2==0){
        factors.pb(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i++){
        while(n%i==0){
            factors.pb(i);
            n/=i;
        }
    }
}
///eular totient function
const int maxx=1000006;
int phi[maxx];
void sPHI(){
    ll i,j;
    for(i=2;i<maxx;i++){
        if(phi[i]==0){
            phi[i]=i-1;
            for(j=i*2;j<maxx;j+=i){
                if(phi[j]==0)phi[j]=j;
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

/*fermats little theorem states that if p is a prime number,
 then for any integer a, the number a^p � a is an integer multiple of p.*/
///finding x^n in logn in floating value
float power(float x, int y)
{
    float temp;
    if(y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}
///extended eucledian algo/ egcd
int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
///modular inverse based on egcd
void modular_inverse(int x, int y){
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        cout << "No solution!";
    }
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}
///mod inverses
    inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
    inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
    inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
    inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
    inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
    inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
    inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
///chinese remainder theorem
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modular_inverse(pp, num[i]) * pp;
    }

    return result % prod;
}
///is power of two
bool isPowerOfTwo(int x)
    {
        /// x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
        return (x && !(x & (x - 1)));
    }
///count the number of ones
int count_one (int n)
        {
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
    }
///check if ith bit set or not?
bool check (int N)
    {
        if( N & (1 << i) )
            return true;
        else
            return false;
    }
///all possible subsets
void possibleSubsets(char A[], int N)
    {
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] << � �;
            cout << endl;
    }
    }
// Returns count of subarrays of arr with XOR
// value equals to m
long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0; // Initialize answer to be returned

    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];

    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;

    // Initialize first element of prefix array
    xorArr[0] = arr[0];

    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];

    // Calculate the answer
    for (int i = 0; i < n; i++) {
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];

        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);

        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == m)
            ans++;

        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }

    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}
  ///kadanes algorithm
  int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];

   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
//NCR in O(T*logn)
vll fact(maxx);
void init(){
    fact[0]=1;
    rep1(i,1,maxx-1){
        fact[i]=(fact[i-1]*i)%MOD;
        fact[i]%=MOD;
    }
}
ll ncr(ll n,ll k){
    if(k==0 || n-k==0) return 1;
    ll res=fact[n];
    //cout<<n<<" "<<fact[n]<<endl;
    ll denom= (Bigmod(fact[k],MOD-2,MOD)+MOD)%MOD*(Bigmod(fact[n-k],MOD-2,MOD)+MOD)%MOD;
    denom%=MOD;
    return (res%MOD*denom%MOD)%MOD;
}


//NCR in T*O(1)
vll fact(maxx),inv(maxx);
void init(){
    fact[0]=1;
    rep1(i,1,maxx-1){
        fact[i]=(fact[i-1]*i)%MOD;
        fact[i]%=MOD;
    }
    inv[maxx-1]=Bigmod(fact[maxx-1],MOD-2,MOD);
    irep(i,maxx-2,0){
        inv[i]=(inv[i+1]*(i+1))%MOD;
    }
}
ll ncr(ll n,ll k){
    if(n<0 or k<0) return 0;
    if(n<k) return 0;
    ll res=fact[n];
    //cout<<n<<" "<<fact[n]<<endl;
    ll denom=(inv[k]*inv[n-k])%MOD;
    return (res%MOD*denom%MOD)%MOD;
}


//Basic Dijkstra
int src=1;
dist[src]=0;
multiset<pair<int,int>>q;
q.insert({0,src});
while(!q.empty()){
    int u=(*q.begin()).ss,w=(*q.begin()).ff;
    //debug(u,w,vis[u]);
    q.erase(q.begin());
    if(vis[u]) continue;
    //debug("chk");
    vis[u]=1;
    //debug(edg[u].size());
    forch(it,edg[u]){
        int v=it.ff,cost=it.ss;
        if(cost+w<dist[v]){
            dist[v]=cost+w;
            q.insert({dist[v],v});
        }
    }
}
if(dist[n]<(int)1e7) printf("%d\n",dist[n]);
else printf("Impossible\n");





//next greater element O(n) using stack
pair<vi,vi> nge(int arr[],int n){//next greater element
    vi ngeElement(n,-1),ngeInd(n,-1);
    stack<int>sEl,sInd;
    sEl.push(arr[0]);
    sInd.push(0);
    rep1(i,1,n-1){
        if(sEl.empty())
        {
            sEl.push(arr[i]);
            sInd.push(i);
            continue;
        }
        while(!sEl.empty() and sEl.top()<arr[i]){
            ngeElement[sInd.top()]=arr[i];
            ngeInd[sInd.top()]=i;
            sEl.pop();
            sInd.pop();
        }
        sEl.push(arr[i]);
        sInd.push(i);
    }
}



//HLD heavy light decomposition 
int chainNo, chainInd[maxx], chainHead[maxx], posInBase[maxx],ptr;
ll baseArray[maxx];
vi edg[maxx],par(maxx),heavy_child(maxx); //heavy_child refers to the child who has the maximum subtree size, we can find that using dfs.
int dfs(int v,int p){
    int szz=1;
    int mxsz=0;
    for(int u:edg[v])
    {
        if(u!=p){
            par[u]=v;
            int ch_sz=dfs(u,v);
            szz+=ch_sz;
            if(ch_sz>mxsz){
                mxsz=ch_sz;
                heavy_child[v]=u;
            }
        }
    }
    return szz;
}
void HLD(int cur){
    if(chainHead[chainNo]==-1) chainHead[chainNo]=cur;
    chainInd[cur]=chainNo;
    posInBase[cur]=ptr;
    baseArray[ptr++]=cost[cur];
    if(heavy_child[cur]!=-1) HLD(heavy_child[cur]);
    forch(it,edg[cur]){
        if(it!=par[cur] and it!=heavy_child[cur]){
            chainNo++;
            HLD(it);
        }
    }

}




//segment tree without update for finding rmq
ll minSeg[4*maxx],maxSeg[4*maxx],arr[maxx];
void build(int treeL,int treeR,int pos){
    if(treeL==treeR){
        minSeg[pos]=arr[treeL];
        maxSeg[pos]=arr[treeR];
        return;
    }
    int mid=treeL+(treeR-treeL)/2;
    build(treeL,mid,2*pos+1);
    build(mid+1,treeR,2*pos+2);
    minSeg[pos]=min(minSeg[2*pos+1],minSeg[2*pos+2]);
    maxSeg[pos]=max(maxSeg[2*pos+1],maxSeg[2*pos+2]);
}
ll minQ(int treeL,int treeR,int L,int R,int pos){
    if(treeR<L or treeL>R) return highest(ll);
    if(L<=treeL and treeR<=R){
        return minSeg[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return min(minQ(treeL,mid,L,R,2*pos+1),minQ(mid+1,treeR,L,R,2*pos+2));
}
ll maxQ(int treeL,int treeR,int L,int R,int pos){
    if(treeR<L or treeL>R) return lowest(ll);
    if(L<=treeL and treeR<=R){
        return maxSeg[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return max(maxQ(treeL,mid,L,R,2*pos+1),maxQ(mid+1,treeR,L,R,2*pos+2));
}


//segment tree "range update range sum query" with lazy propagation 
ll segsum[4*maxx],lazy[4*maxx];
void pushDown(int pos,int treeL,int treeR){
    if(lazy[pos]!=0){
        segsum[pos]+=(lazy[pos]*(treeR-treeL+1)*1ll);
        if(treeL!=treeR)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
}
void update(int treeL,int treeR,int ul,int ur,int pos,ll val){
    pushDown(pos,treeL,treeR);
    if(ul<=treeL and ur>=treeR){//total overlap
        segsum[pos]+=(val*(treeR-treeL+1)*1ll);
        if(treeL!=treeR){
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
    }
    if(ul>treeR or ur<treeL) return;
    int mid=treeL+(treeR-treeL)/2;
    update(treeL,mid,ul,ur,2*pos+1,val);
    update(mid+1,treeR,ul,ur,2*pos+2,val);
    segsum[pos]=segsum[2*pos+1]+segsum[2*pos+2];
}
ll query(int treeL,int treeR,int ql,int qr,int pos){
    pushDown(pos,treeL,treeR);
    if(ql>treeR or qr<treeL) return 0ll;
    if(ql<=treeL and qr>=treeR){
        return segsum[pos];
    }
    int mid=treeL+(treeR-treeL)/2;
    return query(treeL,mid,ql,qr,2*pos+1)+query(mid+1,treeR,ql,qr,2*pos+2);
}


//kth smallest number in a range 
vector<int> seg[4*maxx]; 
void build(int ci, int st, int end, pair<int, int>* B) 
{ 
    if (st == end) { 
        seg[ci].push_back(B[st].second); 
        return; 
    } 
  
    int mid = (st + end) / 2; 
    build(2 * ci + 1, st, mid, B); 
    build(2 * ci + 2, mid + 1, end, B);  
    merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), 
          seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(), 
          back_inserter(seg[ci])); 
} 
int query(int ci, int st, int end, int l, int r, int k) 
{ 

    if (st == end) 
        return seg[ci][0]; 
    int p = upper_bound(seg[2 * ci + 1].begin(), 
                        seg[2 * ci + 1].end(), r) 
            - lower_bound(seg[2 * ci + 1].begin(), 
                          seg[2 * ci + 1].end(), l); 
  
    int mid = (st + end) / 2; 
    if (p >= k) 
        return query(2 * ci + 1, st, mid, l, r, k); 
    else
        return query(2 * ci + 2, mid + 1, end, l, r, k - p); 
} 
void solve(){
    int n,q;
    cin>>n>>q;
    vi arr(n);
    rep(i,n) cin>>arr[i];
    pair<int, int> B[n]; 
  
    for (int i = 0; i < n; i++) { 
        B[i] = { arr[i], i }; 
    } 
    sort(B, B + n); 
    build(0, 0, n - 1, B); 
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        cout<<arr[query(0, 0, n - 1, l, r, k)]<<endl;//gives kth smalleset element in the subarray 
                                                    //starts from l to rth index.
    }
}




//bit binary indexed tree
int bit[maxx];
void update(int pos,int val,int n){
    while(pos<=n){
        bit[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int sum=0;
    while(pos>0){
        sum+=bit[pos];
        pos-=(pos&-pos);
    }
    return sum;
}




//BST[n] means number of binary search tree can be formed by n distinct number. It is also known as catalan number.
// BST[n]==Cn[i]
//Cn[n]=(2n)!/((n+1)!*n!)=C(2n,n)/n+1
const int maxxn=20000;
ll BST[maxxn];
rep(i,maxxn){
    if (i==0 || i==1){
        BST[i]=1;
    }
    else{
        ll sum =0;ll left, right;
        rep1(k,1,i){
            left = BST[k-1] % MOD;
            right= BST[i-k] % MOD;
            sum =(sum%MOD+ (left * right)%MOD)%MOD;
        }
        BST[i]=sum;
    }
}
BST[0]=0;
//Total number of binary tree possible with n nodes is given by :—
//BT(n) = BST(n)*n!



//Phi(x), number of i(1<=i<=x-1) where gcd(i,x)==1;
//Source: http://shoshikkha.com/archives/1472
//for a big number 
ll prime(ll a)
{
    for(int i=2;i*i<=a;i++)
        if(a%i==0) return 1;
    return 0;
}
ll phi(ll n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)==0) mul=n-1;
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    fre++;n/=i;holder=i;
                }
                mul*=(po(holder,fre-1)*(holder-1));
                fre=0;
            }
        }
        if(n!=1)
            mul*=(n-1);
    }
    return mul;
}


//using pair as a key in unordered map
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<pair<int,int>,ll,hash_pair>dp;


// Mo's algo
int k;
ll sum=0;
ll arr[maxx];
ll ans[maxx];
ll cnt[maxx*10];
struct query{
    int index,l,r;
    bool operator < (const query &other) const{
        int block_own=l/k;
        int block_other=other.l/k;
        if(block_own==block_other){
            return r<other.r;
        }
        return block_own<block_other;
    }
}Query[maxx];
void add(int x){
    sum+=arr[x];
}
void rmove(int x){
    sum-=arr[x];
}
int main()
{
    int n;
    cin>>n;
    k=sqrt(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    for(int i=0;i< q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
       // Query[i]={i,l,r};
        Query[i].l=l;
        Query[i].r=r;
        Query[i].index=i;
    }
    sort(Query,Query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++){
        while(R<Query[i].r) add(++R);
        while(R>Query[i].r) rmove(R--);
        while(L<Query[i].l) rmove(L++);
        while(L>Query[i].l) add(--L);
        ans[Query[i].index]=sum;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}





//bfs path finding from root to vertex v;
ll w[maxx],par[maxx];
vi edg[maxx],vis(maxx);
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    par[src]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        forch(it,edg[u]){
            if(!vis[it]){
                vis[it]=1;
                par[it]=u;
                q.push(it);
            }
        }
    }
}

int crwl=par[u];
vi path; //contains the path from root to vertex u in reverse order
path.pb(u);
while(crwl!=-1){
    path.pb(crwl);
    crwl=par[crwl];
}




///DFS
vll edg[maxx],a(maxx),out(maxx),lefs(maxx),sum(maxx),vis(maxx),parent(maxx,-1),ans(maxx);
int n;
void dfs(ll child,ll par){
    lefs[child]=!(edg[child].size());
    //vis[par]=1;
    sum[child]=a[child];
    ans[child]=0;
    forch(it,edg[child]){
        if(it!=par){
            //parent[it]=par;
            dfs(it,child);
            sum[child]+=sum[it];
            lefs[child]+=lefs[it];
            ans[child]=max(ans[child],ans[it]);
        }
    }
    ans[child]=max(ans[child],((sum[child]+lefs[child]-1)/lefs[child]));
}





//LCA using binaryLifting with O(logn) complexity per query and O(nlogn) complexity for precomputation
int n,ht,timer;
vector<vector<int>>up;
vector<int>edg[maxx];
vector<int>st,en;
void dfs(int v,int p){
    st[v]=++timer;
    up[v][0]=p;
    for(int i=1;i<=ht;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u:edg[v])
    {
        if(u!=p) dfs(u,v);
    }
    en[v]=++timer;
}
bool is_ancestor(int u,int v){
    return st[u]<=st[v] and en[u]>=en[v];
}
int lca_qu(int u,int v){
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for(int i=ht;i>=0;i--){
            if(!is_ancestor(up[u][i],v))
                u=up[u][i];
        }
        return up[u][0];
}
void prepo(int root){
    st.resize(n);
    en.resize(n);
    timer=0;
    ht=ceil(log2(n));
    //debug(ht);
    up.assign(n, vector<int>(ht + 1));
    dfs(root,root);
}








//Binary indexed tree(BIT) point update point query
struct BIT{
    vector<int>bt;
    BIT(int n){
        bt.resize(n+1);
    }
    void update(int pos,int val,int upto){
        while(pos<=upto){
            bt[pos]+=val;
            pos+=(pos&-pos);
        }
    }
    int query(int pos){
        int res=0;
        while(pos>0){
            res+=bt[pos];
            pos-=(pos&-pos);
        }
        return res;
    }
};





//rmq by sparse table
struct rmq{
    vector<int>arr;
    vector<vector<int>>sparse;
    int maxxx;
    void init(int n,vector<int>vec){
        maxxx=n;
        arr=vec;
        sparse.resize(n);
        for(auto &it:sparse ){
            it.resize((int)log2(n)+1);
        }
    }
    int  po(int  base , int power){
        int ret=1;
        while(power){
            ret*=base;
            power--;
        }
        return ret;
    }
    ll lg2(ll x){
        ll res=0;
        while(x>1){
            res++;
            x/=2ll;
        }
        return res;
    }
    void prepo(){
        int col=lg2(maxxx)+1;
        for(int i=0;i<maxxx;i++) sparse[i][0]=i; /*the first column of sparse table is equal to the row number because
        the index of the minimum element in range start from ith index to the next 2^0 element is the i itself*/
        for(int j=1;j<=col;j++){
            for(int i=0;i+po(2,j)-1<maxxx;i++){ // this condition is for not going out of bound. else range may go out of bound.
                if(arr[sparse[i][j-1]]<arr[sparse[i+po(2,j-1)][j-1]]){ /*this conditions use the previous range's result. Basically,breaks the
                        present range into two halves that represents the previously calculated halves and compare between them. Seems like used
                        DP here*/
                    sparse[i][j]=sparse[i][j-1];
                }
                else {
                    sparse[i][j]=sparse[i+po(2,j-1)][j-1];
                }
            }
        }
    }
    int minQ(int l,int r){
        int tot=r-l+1;
        int k=log2(tot);
        int slide=l+(tot-pow(2,k));
        return min(arr[sparse[l][k]],arr[sparse[slide][k]]);
        /*
        dividing the range into to halves: 1st--> starting from l to next 2^k elements
                                           2nd--> starting from l+(number of the rest of the elements that was outside the 1st range) to next 2^k 
                                           elements
        */
    }
};





//2d rmq using sparse table, 0 indexed
int n,arr[maxx][maxx],q;
pair<int,int>sparsT[maxx][maxx][maxln];
void prepo(){
    rep(i,n){
        rep(j,n) sparsT[i][j][0]={i,j};
    }
    int col=(int)log2(n)+1;
    rep1(k,1,col){
        for(int i=0;i+po(2,k)-1<n;i++){
            for(int j=0;j+po(2,k)-1<n;j++){
                int x=i+po(2,k-1),y=j+po(2,k-1);
                int x1=sparsT[i][j][k-1].ff,y1=sparsT[i][j][k-1].ss,x2=sparsT[i][y][k-1].ff,y2=sparsT[i][y][k-1].ss;
                if(arr[x1][y1]>arr[x2][y2]){
                    sparsT[i][j][k]=sparsT[i][j][k-1];
                }
                else{
                    sparsT[i][j][k]=sparsT[i][y][k-1];
                }
                x1=sparsT[x][j][k-1].ff,y1=sparsT[x][j][k-1].ss,x2=sparsT[x][y][k-1].ff,y2=sparsT[x][y][k-1].ss;
                int x3,y3;
                if(arr[x1][y1]>arr[x2][y2]){
                    x3=sparsT[x][j][k-1].ff;
                    y3=sparsT[x][j][k-1].ss;
                }
                else{
                    x3=sparsT[x][y][k-1].ff;
                    y3=sparsT[x][y][k-1].ss;
                }
                x1=sparsT[i][j][k].ff,y1=sparsT[i][j][k].ss;
                if(arr[x1][y1]>arr[x3][y3]){
                    sparsT[i][j][k]=sparsT[i][j][k];
                }
                else{
                    sparsT[i][j][k]={x3,y3};
                }
            }
        }
    }
}
int minQ(int x1,int y1,int x2,int y2){
    int Lx=x2-x1+1,Ly=y2-y1+1;
    int kx=(int)log2(Lx),ky=int(log2(Ly));
    int slidex=x1+(Lx-po(2,kx)),slidey=y1+(Ly-po(2,ky));
    int a1=sparsT[x1][y1][ky].ff,b1=sparsT[x1][y1][ky].ss,a2=sparsT[x1][slidey][ky].ff,b2=sparsT[x1][slidey][ky].ss;
    int m1=max(arr[a1][b1],arr[a2][b2]);
    a1=sparsT[slidex][y1][kx].ff,b1=sparsT[slidex][y1][kx].ss,a2=sparsT[slidex][slidey][kx].ff,b2=sparsT[slidex][slidey][kx].ss;
    int m2=max(arr[a1][b1],arr[a2][b2]);
    return max(m1,m2);

}





//Disjoint Set Union
struct DSU{
    vector <int> arr, szz;//arr[i]=j means j is the root of  i; //
    DSU(int n) {
        arr.resize(n + 1); szz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            arr[i] = i; //initially ith node's root is i itself
        }
    }
    int root(int i) { //this func returns the root of ith node
        while(i!=arr[i]){
            arr[i]=arr[arr[i]];
            i=arr[i];
        }
        return i;
    }
    void merge(int a, int b) { //this func merges two nodes a and b.
        int root_a=root(a),root_b=root(b);
        if(root_a==root_b) return;
        if(szz[root_a]<szz[root_b]){
            arr[root_a]=arr[root_b];
            szz[root_b]+=szz[root_a];
        }
        else{
            arr[root_b]=arr[root_a];
            szz[root_a]+=szz[root_b];
        }
    }
};






//Minimum Spanning Tree (mst) using dsu
int n;
scanf("%d",&n); //number of nodes
vector<tuple<int,int,int>>edgs;
int u,v,w;
while(scanf("%d%d%d",&u,&v,&w)) { //given edges of that graph
        if(u==0 and v==0) break;
        edgs.pb(make_tuple(w,u,v));
}
sort(ALL(edgs)); //sorting acording to the ascending order of the cost of the edgs.
int szz=sz(edgs);
int minCost=0; //minimum cost of that spanning tree.
DSU d(n);
rep(i,szz){
    int w=get<0>(edgs[i]),u=get<1>(edgs[i]),v=get<2>(edgs[i]);
    if(d.root(u)!=d.root(v)){
        minCost+=w;
        d.merge(u,v);
    }
}




//articulation bridges 
//graph can not contain multiple edgs and self edgs
//graph can be disconnected
vi edg[maxx],st(maxx),low(maxx,highest(int)),vis(maxx); // st-> stores dicovery time of every node in dfs tree. 
vpii bridgs;                                            // low[u]-> sotres the lowest discovery time among set of nodes in the subtree of u 
int Time=0;
void init(int n){
    rep(i,n) edg[i].clear(),st[i]=0,low[i]=highest(int),vis[i]=0;
    bridgs.clear();
    Time=0;
}
void dfs(int u,int p){
    vis[u]=1;
    low[u]=st[u]=++Time;
    forch(v,edg[u]){
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],st[v]);
        }
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(st[u]<low[v]){                       //this code is for bridges purpose. but por articulation point, just this condition 
                                                    // st[u]<low[v] will be replaced by st[u]<=low[v];
                bridgs.pb({min(u,v),max(u,v)});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    init(n);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        edg[u].pb(v);
        edg[v].pb(u);
    }
    rep(i,n){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    cout<<bridgs.size()<<endl;
    
}




//articulation points
vi edg[maxx],st(maxx),low(maxx,highest(int)),vis(maxx),par(maxx),points(maxx); // st-> stores dicovery time of every node in dfs tree.
                                            // low[u]-> sotres the lowest discovery time among set of nodes in the subtree of u
int Time=0;
void init(int n){
    rep(i,n) edg[i].clear(),st[i]=0,low[i]=highest(int),vis[i]=0,par[i]=-1,points[i]=0;
    Time=0;
}
void dfs(int u,int p){
    vis[u]=1;
    low[u]=st[u]=++Time;
    int ch=0;
    forch(v,edg[u]){
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],st[v]);
        }
        else{
            par[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(st[u]<=low[v] and par[u]!=-1){                       //this code is for bridges purpose. but por articulation point, just this condition
                points[u]=1;                                    // st[u]<low[v] will be replaced by st[u]<=low[v];
            }
            ch++;
        }
        if(par[u]==-1 and ch>1) points[u]=1;
    }

}
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    rep(i,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        edg[u].pb(v);
        edg[v].pb(u);
    }
    dfs(0,-1);
    int ans=0;
    rep(i,n) ans+=points[i];
    printf("%d\n",ans);

}




//trie data structure
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void ins(string str)
{
    int len=sz(str);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool srch(string str)
{
    int len=sz(str);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
///The number of relative primes in a given interval[1:r] for a number n
///coprime

int solve (int n, int r) {
    vector<int> p;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);

    int sum = 0;
    for (int msk=1; msk<(1<<p.size()); ++msk) {
        int mult = 1,
            bits = 0;
        for (int i=0; i<(int)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }

        int cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return r - sum;
}
void solve(){
    root=new node();
    //all other code

    del(root);
}




signed main()
{
    IOS

    return 0;
}
///Alhamdulillah

Bigmod-45
Priority queue compare-61
Largest Rectangular area in histogram-72
points template-132
gcd logn-167
primes sqrt(n)-174
seive-185
segmented seive-204
Prime factorisation-232
Phi function- 246
Fermat theorem-262
Egcd-281
Mod inverse based on egcd-294
Mod inverse-305
chinese remainder theorem-313
Power of two check-333
Number of One count-339
check if ith bit is set-349
All possible subset-357
Count of subarrays xor value is m-368
kadanes algorithm-413
NCR-426
Dijkstra-468
Next greater element-496
Heavy light decomposition-522
Segment tree-561
k-th smallest element-634
Bit-689
BST-709
Phi for a big number-737
pair as a key in unordered map-769
MOs-782
bfs-841
dfs-873
LCA-897
Bit point update point query-942
sparse table rmq-969
2d rmq sparse table-1032
dsu-1088
mst using dsu-1123
Articulation bridge-1147
Articulation point-1199
trie-1250
relative primes in a given interval[1:r] for a number n-1293