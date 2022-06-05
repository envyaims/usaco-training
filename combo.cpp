/*
ID: markwor1
TASK: combo
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
	
bool test(vector<int> a, vector<int> b, int n){
	FOR(i,0,3){
		bool ok = false;
		if(abs(a[i] - b[i]) <= 2)ok = true;
		if(abs(a[i] + n - b[i]) <= 2)ok = true;
		if(abs(b[i] + n - a[i]) <= 2)ok = true;
		if(!ok)return false;
	}
	return true;
}

void solve() {
	ifstream cin("combo.in");
	ofstream cout("combo.out");
	int n; cin >> n;
	vector<int> a(3), b(3);
	read(a);
	read(b);
	
	int ans = 0;
	FORE(i,1,n)FORE(j,1,n)FORE(k,1,n){
		vector<int> c = {i,j,k};
		if(test(a,c,n) || test(b,c,n)){
			//debug(c);
			ans++;
		}
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