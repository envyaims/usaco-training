/*
ID: markwor1
TASK: holstein
LANG: C++                 
*/

#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
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
#define trav(a,x) for (auto& a: x)
#define read(x) trav(i,x)cin>>i

template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};

void solve(){
	ifstream cin("holstein.in");
	ofstream cout("holstein.out");
	
	int n; cin >> n;
	vector<int> req(n);
	FOR(i,0,n){
		cin >> req[i];
	}
	
	int m; cin >> m;
	vt<2,int> each(m,n);
	FOR(i,0,m){
		FOR(j,0,n){
			cin >> each[i][j];
		}
	}
	
	vector<int> ans(100);
	FOR(i,0,1 << m){
		vector<int> cur(n);
		vector<int> x;
		FOR(j,0,m){
			if(i & (1 << j)){
				x.pb(j);
				FOR(k,0,n){
					cur[k] += each[j][k];
				}
			}
		}
		bool ok = true;
		FOR(j,0,n){
			if(cur[j] < req[j])ok = false;
		}
		if(ok){
			debug(x);
			if(x.size() < ans.size()){
				ans = x;
			}
			else if(x < ans && ans.size() == x.size()){
				ans = x;
			}
		}
	}
	cout << ans.size() << " ";
	FOR(i,0,ans.size()){
		cout << ans[i] + 1;
		if(i < ans.size() - 1)cout << " ";
	}
	cout << endl;
	
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}
