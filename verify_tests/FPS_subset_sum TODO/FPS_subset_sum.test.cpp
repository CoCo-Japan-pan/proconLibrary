#define PROBLEM "https://yukicoder.me/problems/no/2062"
#define IGNORE // FPSライブラリができるまで

// 提出時にassertはオフ
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif

#include <bits/stdc++.h>
#include "myLibrary/modint_static.hpp"
using mint = mint998244353;
constexpr int subset_mod = 999630629;
using namespace std;
using ll = long long;

#define ALL(x) (x).begin(), (x).end()
template <class T> using vec = vector<T>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vec<int> A(N);
    int all_sum = 0;
    for(int &a : A) {
        cin >> a;
        all_sum += a;
    }
    sort(ALL(A));
    // 基本的に総和の2^(N-1)倍で終わりだが、999630629を超えると引かないとダメ
    // いくつのsubsetでこれが起きるか数えます
    ll haveToSubtract = 0;
    if(all_sum >= subset_mod){
        multiset<int> sum_set;
        int last_sum = all_sum - subset_mod;
        // 要素の総和がlast_sum以下となるsubsetの個数を数える
        for(int i = 0; i < N; i++){
            multiset<int> cur_sum_set;
            cur_sum_set.insert(0);
            bool overFlag = false;
            for(int sum : sum_set){
                if(sum + A[i] <= last_sum){
                    cur_sum_set.insert(sum + A[i]);
                } else {
                    if(cur_sum_set.empty()) overFlag = true;
                    break;
                }
            }
            for(int cur_sum : cur_sum_set){
                sum_set.insert(cur_sum);
            }
            if(overFlag) break;
        }
        haveToSubtract = sum_set.size();
    }
    mint ans(all_sum);
    ans *= mint(2).pow(N - 1);
    ans -= mint(haveToSubtract) * mint(subset_mod);
    cout << ans.val() << "\n";
}