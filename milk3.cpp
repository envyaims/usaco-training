/*
ID: markwor1
TASK: milk3
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

int a,b,c;
bool can[25][25][25];

void dfs(int am, int bm, int cm){
	if(can[am][bm][cm])return;
	can[am][bm][cm] = true;
	
	// a to b
	int pour = min(am, b - bm);
	dfs(am - pour, bm + pour, cm);
	
	// a to c
	pour = min(am , c - cm);
	dfs(am - pour, bm , cm + pour);
	
	// b to c
	pour = min(bm , c - cm);
	dfs(am, bm - pour, cm + pour);
	
	// b to a
	pour = min(bm, a - am);
	dfs(am + pour, bm - pour, cm);
	
	// c to a
	pour = min(cm, a - am);
	dfs(am + pour, bm, cm - pour);
	
	// c to b
	pour = min(cm, b - bm);
	dfs(am, bm + pour, cm - pour);
}

void solve() {
	ifstream cin("milk3.in");
	ofstream cout("milk3.out");
	cin >> a >> b >> c;
	dfs(0,0,c);
	set<int> ans;
	FORE(i,0,b){
		FORE(j,0,c){
			if(can[0][i][j]){
				ans.insert(j);
			}
		}
	}
	auto it = ans.begin();
	while(true){
		cout << *it;
		it++;
		if(it != ans.end()){
			cout << " ";
		}
		else break;
	}
	cout << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}