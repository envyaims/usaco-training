/*
ID: markwor1
TASK: wormhole
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
	
vector<pair<int,int>> a;
ll ans = 0;
vector<int> connect, pairing;
int n;

bool cycle(){
	FOR(i,0,n){
		int track = i;
		FOR(j,0,n){
			track = connect[pairing[track]];
			if(track == -1)break;
		}
		if(track != -1)return true;
	}
	return false;
}

void rec(){
	bool found = false;
	FOR(i,0,n){
		if(pairing[i] == -1){
			found = true;
			FOR(j, i+1, n){
				if(pairing[j] == -1){
					pairing[i] = j;
					pairing[j] = i;
					rec();
					pairing[i] = pairing[j] = -1;
				}
			}
			return;
		}
	}
	if(!found){
		ans += cycle();
	}
	
}

void solve() {
	ifstream cin("wormhole.in");
	ofstream cout("wormhole.out");
	cin >> n;
	a.resize(n);
	connect.resize(n, -1);
	pairing.resize(n, -1);
	trav(i,a){
		cin >> i.F >> i.S;
	}
	FOR(i,0,n){
		FOR(j,0,n){
			if(a[j].F > a[i].F && a[j].S == a[i].S){
				if(connect[i] == -1 || a[connect[i]].F > a[j].F){
					connect[i] = j;
				}
			}
		}
	}
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