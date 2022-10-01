#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
int recur_depth = 0;
#define db(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define db(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
os<<"[";for(auto& x:v){os<<x<<", ";}return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
return os<<"{"<<p.first<<", "<<p.second<<"}";
}

void solve(){}

int main() {
#ifdef DEBUG
auto started = std::chrono::high_resolution_clock::now();
#endif
cin.tie(0)->sync_with_stdio(0);
cin.exceptions(cin.failbit);
int t;
t = 1;
cin >> t;
for (int I = 1; I <= t; I++)
{
#ifdef DEBUG
cerr << "Case #" << I << ":\n";
#endif
solve();
}
#ifdef DEBUG
auto done = std::chrono::high_resolution_clock::now();
cerr << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " ms\n";
#endif
}
