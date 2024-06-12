#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int N = 1e5+10;
int h[N];
int dp[N];

int func(int i) {
    if(i == 0) return 0;
    int cost = INT_MAX;
    if(dp[i] != -1) return dp[i];
    cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
    if(i > 1)
        cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));
    return dp[i] = cost;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >>t;
    while(t--) {
        for(ll i = 0; i<n; i++) {
            cin >> h[i];
        }
        cout << func(n-1) << endl;
    }
    return 0;
}
 