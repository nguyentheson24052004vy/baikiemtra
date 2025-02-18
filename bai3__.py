from collections import deque
import re
import os

def max_sliding_window(num_list, k):
    if not num_list or k <= 0:
        return []
    
    result = []
    dq = deque()
    
    for i in range(len(num_list)):
        # Loại bỏ chỉ mục không còn trong cửa sổ
        if dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Loại bỏ phần tử nhỏ hơn phần tử hiện tại từ cuối deque
        while dq and num_list[dq[-1]] < num_list[i]:
            dq.pop()
        
        # Thêm chỉ mục hiện tại vào deque
        dq.append(i)
        
        # Khi đã có đủ k phần tử, thêm giá trị lớn nhất vào kết quả
        if i >= k - 1:
            result.append(num_list[dq[0]])
    
    return result

def count_chars(string):
    char_count = {}
    for char in string.replace(" ", ""):
        char_count[char] = char_count.get(char, 0) + 1
    return char_count

def word_count(file_path):
    if not os.path.exists(file_path):
        print(f"Error: File '{file_path}' not found.")
        return {}
    
    word_freq = {}
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            words = re.findall(r'\b[a-zA-Z]+\b', line.lower())
            for word in words:
                word_freq[word] = word_freq.get(word, 0) + 1
    return word_freq


# Example usage:
file_path = "P1_data.txt"  # Ensure this file exists in the correct directory
print(word_count(file_path))