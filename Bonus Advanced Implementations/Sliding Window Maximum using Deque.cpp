#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

// Driver Code
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = slidingWindowMax(nums, k);
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
