/*
ID: markwor1
TASK: transform
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

vt<2,char> rotate(vt<2,char> x){
	int n = x.size();
	vt<2,char> ret(n,n);
	FOR(i,0,n)FOR(j,0,n){
		ret[j][n-i-1] = x[i][j];
	}
	return ret;
}

vt<2,char> reflect(vt<2,char> x){
	int n = x.size();
	vt<2,char> ret(n,n);
	FOR(i,0,n)FOR(j,0,n){
		ret[i][n-j-1] = x[i][j];
	}
	return ret;
}

#define pr(x) cout << x << endl; return

void solve() {
	ifstream cin("transform.in");
	ofstream cout("transform.out");
	int n; cin >> n;
	vt<2,char> orig(n,n), target(n,n);
	FOR(i,0,n)FOR(j,0,n)cin>>orig[i][j];
	FOR(i,0,n)FOR(j,0,n)cin>>target[i][j];
	
	vt<2,char> cur = rotate(orig);
	
	if(cur == target){
		pr(1);
	}
	cur = rotate(cur);
	if(cur == target){
		pr(2);
	}
	cur = rotate(cur);
	if(cur == target){
		pr(3);
	}
	
	cur = reflect(orig);
	if(cur == target){
		pr(4);
	}
	
	FOR(i,0,3){
		cur = rotate(cur);
		if(cur == target){
			pr(5);
		}
	}
	
	if(target == orig){
		pr(6);
	}
	pr(7);
	
	
	
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}