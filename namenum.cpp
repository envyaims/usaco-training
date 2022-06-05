/*
ID: markwor1
TASK: namenum
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
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

bool contain(vector<char> a, char b){
	return find(all(a), b) != a.end();
}

void solve() {
	ifstream cin("namenum.in");
	ofstream cout("namenum.out");
	
	vector<char> valid;
	for(int c = 'A'; c <= 'Y'; c++){
		if(c != 'Q'){
			valid.push_back(c);
		}
	}
	vector<vector<char>> mapping(10);
	int cnt = 1;
	for(int i = 0; i < valid.size();  i++){
		if(i % 3 == 0){
			cnt++;
		}
		mapping[cnt].push_back(valid[i]);
	}
	
	string s; cin >> s;
	
	vector<string> cand;
	
	ifstream fin("dict.txt");
	string v;
	while(fin >> v){
		if(v.length() != s.length()){
			continue;
		}
		
		bool ok = true;
		for(int i = 0; i < s.length(); i++){
			if(!contain(mapping[s[i] - '0'], v[i])){
				ok = false;
				break;
			}
		}
		
		if(ok){
			cand.push_back(v);
		}
		
	}
	
	for(char i: s){
		if(i == '0' || i == '1'){
			cout << "NONE" << endl;
			return;
		}	
	}
	
	if(cand.empty()){
		cout << "NONE" << endl;
		return;
	}
	
	sort(all(cand));
	for(string i: cand){
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