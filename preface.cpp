/*
ID: markwor1
TASK: preface
LANG: C++                 
*/

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif
using namespace std;
using ll = int_fast64_t;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define fuck(x) trav(i,x) cin >> i
#define sz(x) (int)x.size()
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};

void uwu(){
	ifstream cin("preface.in");
	ofstream cout("preface.out");
	string ones[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[3] = {"M", "MM", "MMM"};
    string order = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
    map<char, int> cnt;
    
    auto ins = [&](string& s){
		trav(i, s) cnt[i]++;
	};
    int n; cin >> n;
    FORE(i,1,n){
		int tmp = i;
		if(tmp >= 1000) ins(thousands[tmp / 1000 - 1]);
		tmp %= 1000;
		if(tmp >= 100) ins(hundreds[tmp / 100 - 1]);
		tmp %= 100;
		if(tmp >= 10) ins(tens[tmp / 10 - 1]);
		tmp %= 10;
		if(tmp >= 1) ins(ones[tmp - 1]);
	}
	trav(i, order){
		if(cnt.count(i)){
			cout << i << " " << cnt[i] << endl;
		}
	}
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin>>t;
	while(t--){
		uwu();
	}
}
