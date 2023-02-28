#pragma once

#ifdef NOBUNDLE
#include<bits/stdc++.h>
using namespace std;
#endif

// 静的な半群列の区間和を高速に計算する
// 半群: 二項演算が定義されて、結合法則を満たす、単位元も逆元も不要 (min, max, 和, 積, gcd)
// 更新はできないが、クエリはO(1)!!! (前計算にO(nlogn))

template <class T>
struct DST {
    using OperatorType = function<T(T, T)>;

   public:
    DST(const vector<T> &vec, const OperatorType &op_) : size(vec.size()), op(op_) {
        int depth = 1;
        while((1 << depth) <= size) depth++;
        data.assign(depth, vector<T>(size));
        MSSBTable.resize((1 << depth), 0);
        for(int i = 0; i < size; i++) {
            data[0][i] = vec[i];
        }
        for(int i = 2; i < (1 << depth); i++){
            MSSBTable[i] = MSSBTable[i >> 1] + 1;
        }

        for(int a = 1; a < depth; a++) {
            int maxLen = 1 << a;
            for(int b = 0; b < size; b += (maxLen << 1)){
                // [l, middle)
                int middle = min(b + maxLen, size);
                data[a][middle - 1] = vec[middle - 1];
                for(int l = middle - 2; l >= b; l--){
                    data[a][l] = op_(vec[l], data[a][l + 1]);
                }
                if(middle == size) break;
                // [middle, r]
                data[a][middle] = vec[middle];
                for(int r = middle + 1; r < min(middle + maxLen, size); r++){
                    data[a][r] = op_(data[a][r - 1], vec[r]);
                }
            }   
        }
    }

    // [l, r)の区間での計算結果をO(1)で取得
    T query(int l, int r) const {
        assert(l < r);
        assert(0 <= l && r <= size);
        if(l >= --r) return data[0][l];
        return op(data[MSSBTable[l ^ r]][l], data[MSSBTable[l ^ r]][r]);
    }

   private:
    const int size;
    const OperatorType op;
    vector<vector<T>> data; // data[i][j]で、[j, MSSB) または [MSSB, j]
    vector<int> MSSBTable;  // most significant set bit
};