/*
ID: markwor1
TASK: milk2
LANG: C++                 
*/

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> void max_self(T& a, T b){a = max(a,b);}
template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;
using secondpq = priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll; const ll INF = 2e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define tobin(b,x) bitset<b>(x).to_string()
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
#define int long long
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.S < b.S;
}

void doStuff(){
	// freopen("milk2.in","r",stdin);
	// freopen("milk2.out","w",stdout);
	int n; cin>>n;
	vector<pair<int,int>> nums(n);
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		nums[i] = mp(a,b);
		
	}	
	sort(all(nums));
	int maxt = nums[0].S - nums[0].F, startt = nums[0].F, endt = 0;
	int idlet = 0;
	for(int i = 0; i < n-1; i++){
		maxt = max(maxt, nums[i].S - nums[i].F);
		if(nums[i].S < nums[i+1].F){
			endt = nums[i].S;
			maxt = max(maxt,endt - startt);
			startt = nums[i+1].F;
		}
	}
	sort(all(nums),cmp);
	debug(nums);
	cout<<maxt<<" "<<idlet<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		doStuff();
	}
	return 0;
}