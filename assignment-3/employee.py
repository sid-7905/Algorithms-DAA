import pandas as pd
import os

def tax_to_be_paid(amount):
    taxable_amount=0
    if amount<=300000:
        return 0
    
    if amount>300000 and amount<=700000:
        return 0.05*(amount-300000)
    taxable_amount+=0.05*400000

    if amount>700000 and amount<=1000000:
        return 0.1*(amount-700000)+taxable_amount
    taxable_amount+=0.1*300000

    if amount>1000000 and amount<1200000:
        return 0.15*(amount-1000000)+taxable_amount
    taxable_amount+=0.15*200000

    if amount>1200000 and amount<1500000:
        return 0.20*(amount-1200000)+taxable_amount
    taxable_amount+=0.20*300000

    if amount>1500000:
        return 0.3*(amount-1500000)+taxable_amount

class Employee:
    def __init__(self, name, base, HRA, bonus, deductions):
        self.name = name
        self.base_salary = base
        self.HRA = HRA
        self.bonus = bonus
        self.deductions = deductions

    def gross_salary(self):
        # calculating Grossalary of the employee
        GrossSalary = self.base_salary + self.bonus + self.HRA
        return GrossSalary

    def net_salary(self):
        # calculating NetSalary of the employee
        NetSalary=self.gross_salary()-tax_to_be_paid(self.gross_salary()-self.HRA)-self.deductions
        return NetSalary; 

def min_iter(df):
    m = df.shape[0]
    min_salary = float("inf")
    for i in range(m):
        if df.iloc[i]["Net_Salary"] < min_salary:
            min_salary=df.iloc[i]["Net_Salary"]
            id = i

    return id


def max_iter(df):
    m = df.shape[0]
    max_salary = float("-inf")
    for i in range(m):
        if df.iloc[i]["Net_Salary"] > max_salary:
            max_salary = df.iloc[i]["Net_Salary"]
            id = i

    return id


def min_rec(df,left, right):
        if left == right:
            return left

        mid = left + (right - left)//2

        left_id= min_rec(df,left, mid)
        right_id= min_rec(df,mid + 1, right)

        if df.iloc[left_id]["Net_Salary"] < df.iloc[right_id]["Net_Salary"]:
            return left_id
        else:
            return right_id


def max_rec(df,left, right):
        if left == right:
            return left

        mid = left + (right - left) // 2

        left_id = max_rec(df,left, mid)
        right_id = max_rec(df,mid + 1, right)

        if df.iloc[left_id]["Net_Salary"] > df.iloc[right_id]["Net_Salary"]:
            return left_id
        else:
            return right_id


def main():
    file_size = os.path.getsize('employee_data.csv') 
 
    if file_size == 0:     
        print('File is Empty')
        return
    
    if(not os.path.isfile("employee_data.csv")):
        print("Employee_data missing! Please ensure that the employee data is stored in file named 'employee_data.csv'.")
        return
    
    df = pd.read_csv("employee_data.csv")

    n,m = df.shape
    print(n,m)

    print("Employees with Minimum Net Salaries: ")

    print(f"Iterative Result: ",end="")
    id = min_iter(df)
    name=df.iloc[id]["Name"]
    min_salary=df.iloc[id]["Net_Salary"]
    print(f"Id: {id}; Name: {name}; Salary: {min_salary}")

    print(f"Divide and Conquer Result: ",end="")
    id = min_rec(df,0,m-1)
    name=df.iloc[id]["Name"]
    min_salary=df.iloc[id]["Net_Salary"]
    print(f"Id: {id}; Name: {name}; Salary: {min_salary}")

    print("Employees with Maximum Net Salaries: ")

    print(f"Iterative Result: ",end="")
    id = max_iter(df)
    name=df.iloc[id]["Name"]
    max_salary=df.iloc[id]["Net_Salary"]
    print(f"Id: {id}; Name: {name}; Salary: {max_salary}")

    print(f"Divide and Conquer Result: ",end="")
    id = max_rec(df,0,m-1)
    name=df.iloc[id]["Name"]
    max_salary=df.iloc[id]["Net_Salary"]
    print(f"Id: {id}; Name: {name}; Salary: {max_salary}")

if __name__ == "__main__":
    main()