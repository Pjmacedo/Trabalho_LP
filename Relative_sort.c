//1122. Relative sort array, leetcode

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); ++i) {
            order[arr2[i]] = i;
        }

        std::vector<int> presentInArr2;
        std::vector<int> notInArr2;

        for (int num : arr1) {
            if (order.find(num) != order.end()) {
                presentInArr2.push_back(num);
            } else {
                notInArr2.push_back(num);
            }
        }

        std::sort(notInArr2.begin(), notInArr2.end());

        std::stable_sort(presentInArr2.begin(), presentInArr2.end(), [&](int a, int b) {
            return order[a] < order[b];
        });

        presentInArr2.insert(presentInArr2.end(), notInArr2.begin(), notInArr2.end());
        
        return presentInArr2;
    }
};
