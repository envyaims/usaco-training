/*
ID: markwor1
TASK: sprime
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
set<string> ans;

string s;

bool isprime(){
	int x = stoi(s);
	if(x == 1)return false;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0)return false;
	}
	return true;
}

void rec(){
	if(s.length() == n){
		ans.insert(s);
		return;
	}
	for(char i = '1'; i <= '9'; i++){
		s.pb(i);
		if(isprime()){
			rec();
		}
		s.pop_back();
	}
}

void solve() {
	ifstream cin("sprime.in");
	ofstream cout("sprime.out");
	cin >> n;
	rec();
	
	for(string i: ans){
		cout << i << endl;
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