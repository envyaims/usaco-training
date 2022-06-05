/*
ID: markwor1
TASK: pprime
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

set<int> valid;
vector<int> str(10);

void check(int len){
	if(str[0] % 2 == 0)return;
	
	int val = 0;
	int power = 1;
	ROF(i, len-1, 0){
		val += str[i] * power;
		power *= 10;
	}
	bool ok = true;
	for(int i = 3; i * i <= val; i += 2){
		if(val % i == 0){
			ok = false;
			break;
		}
	}
	if(ok){
		valid.insert(val);
	}
}

void gen(int len, int idx){
	if(idx >= (len + 1) / 2){
		check(len);
		return;
	}
	FORE(i,0,9){
		str[idx] = i;
		str[len - idx - 1] = i;
		gen(len, idx + 1);
	}
}

void solve() {
	ifstream cin("pprime.in");
	ofstream cout("pprime.out");
	int l, r; cin >> l >> r;
	FORE(i,1,9){
		gen(i,0);
	}
	auto it = valid.lower_bound(l);
	while(it != valid.end() && *it <= r){
		cout << *it << endl;
		++it;
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