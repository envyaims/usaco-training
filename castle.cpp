/*
ID: markwor1
TASK: castle
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
template<class T> bool ckeq(T& a, const T& b){return a==b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	
struct DSU{
	vector<int> p, sz;
	DSU(int n){
		p.resize(n);
		sz.resize(n,1);
		iota(p.begin(),p.end(),0);
	}
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	bool unite(int a, int b){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
		}
		return a != b;
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};

int n, m;
int c(int i, int j){
	return m * i + j;
}

int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};

void solve() {
	ifstream cin("castle.in");
	ofstream cout("castle.out");
	cin >> m >> n;
	
	vt<2,int> grid(n,m);
	FOR(i,0,n)FOR(j,0,m)cin>>grid[i][j];
	DSU dsu(n * m);
	
	FOR(i,0,n)FOR(j,0,m){
		FOR(k,0,4){
			if(!(grid[i][j] & (1 << k))){
				dsu.unite(c(i,j), c(i + dx[k], j + dy[k]));
			}
		}
	}
	
	set<int> rooms;
	int largest = 0, largestrem = 0;
	int row = -1e9, col = 1e9; char dir;
	
	FOR(i,0,n)FOR(j,0,m){
		ckmax(largest, dsu.getsize(c(i,j)));
		rooms.insert(dsu.get(c(i,j)));
		
		// E
		if(j < m - 1){
			if(grid[i][j] & (1 << 2)){
				if(dsu.get(c(i,j)) != dsu.get(c(i, j+1))){
					if(ckeq(largestrem, dsu.getsize(c(i,j)) + dsu.getsize(c(i, j+1)) )){
						if(j < col){
							row = i; col = j; dir = 'E';
						}
						else if(j == col && i > row){
							row = i; col = j; dir = 'E';
						}
					}
					if(ckmax(largestrem, dsu.getsize(c(i,j)) + dsu.getsize(c(i, j+1)) )){
						row = i; col = j; dir = 'E';
					}
					
				}
			}
		}
		
		// N
		if(i > 0){
			if(grid[i][j] & (1 << 1)){
				if(dsu.get(c(i,j)) != dsu.get(c(i-1, j))){
					if(ckeq(largestrem, dsu.getsize(c(i,j)) + dsu.getsize(c(i-1,j)) )){
						if(j < col){
							row = i; col = j; dir = 'N';
						}
						else if(j == col && i >= row){
							row = i; col = j; dir = 'N';
						}
					}
					if(ckmax(largestrem, dsu.getsize(c(i,j)) + dsu.getsize(c(i-1,j)) )){
						row = i; col = j; dir = 'N';
					}
				}
			}
		}
	}
	
	cout << rooms.size() << endl;
	cout << largest << endl;
	cout << largestrem << endl;
	cout << row + 1 << " " << col + 1 << " " << dir << endl;
	
	
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
