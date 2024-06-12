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
int coins[10010];
int dp[10010];

int func(int amount, vector<ll>& coins) {
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    int ans = INT_MAX;
    for(ll coin : coins) {
        if(amount - coin >= 0) {
            if(amount - coin >= 0)
            ans = min(ans + 0LL, func(amount - coin, coins) + 1);
        }
    }
    return dp[amount] =  ans;
}

ll coinChange(vector<ll>& coins, ll amount) {
    memset(dp, -1, sizeof(dp));
    int ans = func(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >>t;
    while(t--) {
        ll amount,numb; cin >> amount;
        cin >> numb;
        for(ll i = 0; i<numb; i++) {
            cin >> coins[i];
        }
        cout << coinChange(coins, amount) << endl;
    }
    return 0;
}
 