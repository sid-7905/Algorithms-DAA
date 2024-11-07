def multiply_large_numbers(num1, num2):
    n1 = len(num1)
    n2 = len(num2)
    result = [0] * (n1 + n2)
    i_n1 = 0
    i_n2 = 0
    
    for i in range(n1 - 1, -1, -1):
        carry = 0
        n1_digit = int(num1[i])
        i_n2 = 0
        
        for j in range(n2 - 1, -1, -1):
            n2_digit = int(num2[j])
            sum_value = n1_digit * n2_digit + result[i_n1 + i_n2] + carry
            carry = sum_value // 10
            result[i_n1 + i_n2] = sum_value % 10
            i_n2 += 1
        
        if carry > 0:
            result[i_n1 + i_n2] += carry
            
        i_n1 += 1
    
    i = len(result) - 1
    while i >= 0 and result[i] == 0:
        i -= 1
    
    if i == -1:
        return "0"
    
    s = ""
    while i >= 0:
        s += str(result[i])
        i -= 1
    
    return s

if __name__ == "__main__":
    num1 = input("Enter first large number: ")
    num2 = input("Enter second large number: ")
    result = multiply_large_numbers(num1, num2)
    print("Result:", result)
