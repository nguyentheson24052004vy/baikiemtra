#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

// Hàm đếm số lần xuất hiện của các chữ cái trong chuỗi
unordered_map<char, int> count_chars(const string &str) {
    unordered_map<char, int> char_count;

    for (char c : str) {
        if (isalpha(c)) { // Chỉ xét chữ cái từ 'a-z' hoặc 'A-Z'
            char_count[c]++;
        }
    }

    return char_count;
}

int main() {
    string input;
    cout << "Nhập chuỗi: ";
    getline(cin, input);

    unordered_map<char, int> result = count_chars(input);

    cout << "{ ";
    for (const auto &pair : result) {
        cout << "'" << pair.first << "': " << pair.second << ", ";
    }
    cout << "}" << endl;

    return 0;
}
