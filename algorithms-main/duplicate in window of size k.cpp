#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicateWithinWindow(const std::vector<int>& nums, int k) {
    int n = nums.size();
    if (k >= n) {
        return false;
    }

    std::unordered_set<int> windowSet;

    // Check duplicates within the first window
    for (int i = 0; i < k; i++) {
        if (windowSet.find(nums[i]) != windowSet.end()) {
            return true;
        }
        windowSet.insert(nums[i]);
    }

    // Slide the window and check duplicates
    for (int i = k; i < n; i++) {
        windowSet.erase(nums[i - k]);
        if (windowSet.find(nums[i]) != windowSet.end()) {
            return true;
        }
        windowSet.insert(nums[i]);
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1, 4, 5};
    int k = 3;

    if (containsDuplicateWithinWindow(nums, k)) {
        std::cout << "Duplicates found within the window." << std::endl;
    } else {
        std::cout << "No duplicates found within the window." << std::endl;
    }

    return 0;
}
