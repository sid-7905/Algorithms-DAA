def count_inversions(arr):
    n = len(arr)  
    count = 0 
   
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                count += 1
            
    return count

if __name__ == "__main__":
    arr = [2, 4, 1, 3, 5]
    print("Number of inversions:", count_inversions(arr))
