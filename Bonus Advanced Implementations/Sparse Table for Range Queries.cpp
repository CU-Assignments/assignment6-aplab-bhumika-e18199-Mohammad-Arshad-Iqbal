#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
    vector<vector<int>> st;

public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int logN = log2(n) + 1;
        st.assign(n, vector<int>(logN, 0));

        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = log2(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

// Driver Code
int main() {
    vector<int> arr = {4, 6, 1, 5, 7, 3, 9, 2};
    SparseTable st(arr);
    cout << "Min in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Min in range [2, 6]: " << st.query(2, 6) << endl;
    return 0;
}
