/*
ID: markwor1
TASK: crypt1
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

int n;
vector<int> a, dig;

ll ans = 0;

int digcnt(int x){
	int cnt = 0;
	while(x > 0){
		cnt++;
		x /= 10;
	}
	return cnt;
}

bool in(int x){
	while(x > 0){
		int d = x % 10;
		x /= 10;
		if(find(all(a), d) == a.end())return false;
	}
	return true;
}

void check(){
	int f = 100 * dig[0] + 10 * dig[1] + dig[2];
	int one = f * dig[4];
	int two = f * dig[3];
	int prod = 10 * two + one;
	if(in(one) && in(two) && in(prod)){
		if(digcnt(one) == 3 && digcnt(two) == 3 && digcnt(prod) == 4){
			ans++;
		}
	}
}

void rec(){
	if(dig.size() == 5){
		check();
		return;
	}
	trav(i,a){
		dig.pb(i);
		rec();
		dig.pop_back();
	}
}

void solve() {
	ifstream cin("crypt1.in");
	ofstream cout("crypt1.out");
	cin >> n;
	a.resize(n);
	read(a);
	rec();
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