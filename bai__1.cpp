#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm lọc và thay thế các số theo yêu cầu
vector<int> filterAndReplace(vector<int> &num_list, int k) {
    vector<int> result;
    
    // Tìm số lớn nhất trong danh sách
    int max_value = *max_element(num_list.begin(), num_list.end());

    // Duyệt danh sách, nếu số > k thì giữ nguyên, nếu không thì thay bằng max_value
    for (int num : num_list) {
        if (num > k) {
            result.push_back(num);
        } else {
            result.push_back(max_value);
        }
    }
    
    return result;
}

int main() {
    vector<int> num_list = {3, 4, 5, 1, -44, 5, 10, 12, 33, 1};
    int k = 3;

    vector<int> output = filterAndReplace(num_list, k);

    // In kết quả
    cout << "[ ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << "]";

    return 0;
}
