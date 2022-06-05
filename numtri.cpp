/*
ID: markwor1
TASK: numtri
LANG: C++                 
*/

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x)cin >> i
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	

void solve() {
	ifstream cin("numtri.in");
	ofstream cout("numtri.out");
	int n; cin >> n;
	vt<2,int> grid(n,n);
	FOR(i,0,n)FORE(j,0,i)cin>>grid[i][j];
	vt<2,int> dp(n,n);
	dp[0][0] = grid[0][0];
	FOR(i,1,n){
		FORE(j,0,i){
			if(j != i){
				ckmax(dp[i][j], dp[i-1][j]);
			}
			if(j != 0){
				ckmax(dp[i][j], dp[i-1][j-1]);
			}
			dp[i][j] += grid[i][j];
		}
	}
	int ans = 0;
	FOR(i,0,n){
		ckmax(ans, dp[n-1][i]);
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}