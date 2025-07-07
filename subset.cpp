#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& nums, vector<int>& current, int index) {
    if (index == nums.size()) {
        // Print current subset
        cout << "{ ";
        for (int val : current)
            cout << val << " ";
        cout << "}" << endl;
        return;
    }

    // Include current element
    current.push_back(nums[index]);
    findSubsets(nums, current, index + 1);

    // Exclude current element
    current.pop_back();
    findSubsets(nums, current, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> current;

    findSubsets(nums, current, 0);

    return 0;
}
