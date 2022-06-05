/*
ID: markwor1
TASK: dualpal
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

bool conv(int x, int base){
	string s;
	while(x > 0){
		int rem = x % base;
		x /= base;
		if(rem >= 10){
			s += (char)('A' + rem - 10);
		}
		else s += rem + '0';
	}
	string cop = s;
	reverse(all(s));
	return cop == s;
}

void solve() {
	ifstream cin("dualpal.in");
	ofstream cout("dualpal.out");
	int n,s; cin >> n >> s;
	int cnt = 0;
	for(int i = s + 1; cnt < n; i++){
		int ok = 0;
		FORE(j,2,10){
			ok += conv(i,j);
		}
		if(ok >= 2){
			cnt++;
			cout << i << endl;
		}
	}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}