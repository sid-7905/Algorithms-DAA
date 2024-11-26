// # def multiply_large_numbers(num1, num2):
// #     n1 = len(num1)
// #     n2 = len(num2)
// #     result = [0] * (n1 + n2)
// #     i_n1 = 0
// #     i_n2 = 0
    
// #     for i in range(n1 - 1, -1, -1):
// #         carry = 0
// #         n1_digit = int(num1[i])
// #         i_n2 = 0
        
// #         for j in range(n2 - 1, -1, -1):
// #             n2_digit = int(num2[j])
// #             sum_value = n1_digit * n2_digit + result[i_n1 + i_n2] + carry
// #             carry = sum_value // 10
// #             result[i_n1 + i_n2] = sum_value % 10
// #             i_n2 += 1
        
// #         if carry > 0:
// #             result[i_n1 + i_n2] += carry
            
// #         i_n1 += 1
    
// #     i = len(result) - 1
// #     while i >= 0 and result[i] == 0:
// #         i -= 1
    
// #     if i == -1:
// #         return "0"
    
// #     s = ""
// #     while i >= 0:
// #         s += str(result[i])
// #         i -= 1
    
// #     return s

// # if __name__ == "__main__":
// #     num1 = input("Enter first large number: ")
// #     num2 = input("Enter second large number: ")
// #     result = multiply_large_numbers(num1, num2)
// #     print("Result:", result)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply_large_numbers(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> result(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1_digit = num1[i] - '0';

        for (int j = n2 - 1; j >= 0; j--) {
            int n2_digit = num2[j] - '0';
            int sum_value = n1_digit * n2_digit + result[i + j + 1] + carry;
            carry = sum_value / 10;
            result[i + j + 1] = sum_value % 10;
        }

        result[i] += carry;
    }

    string s = "";
    for (int i = 0; i < result.size(); i++) {
        if (!(s.empty() && result[i] == 0)) {
            s += to_string(result[i]);
        }
    }

    return s.empty() ? "0" : s; 
}

int main() {
    string num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;
    string result = multiply_large_numbers(num1, num2);
    cout << "Result: " << result << endl;
    return 0;
}