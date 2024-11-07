import pandas as pd
import random
from employee import Employee

def gen_emp_data():
    # generating random data
    names = [f"Employee_{i}" for i in range(2000)]
    base_salaries = [random.randint(100000, 3000000) for _ in range(2000)]
    HRAs = [random.randint(10000, 30000) for _ in range(2000)]
    Bonuses = [random.randint(0, 10000) for _ in range(2000)]
    deductions = [random.randint(1000, 10000) for _ in range(2000)]

    # Data structure(array) to store data
    employees = []

    for i in range(2000):

        # creating employee object of class Employee
        employee = Employee(
            names[i],
              base_salaries[i],
                HRAs[i],
                  Bonuses[i],
                    deductions[i]
        )

        # appending into the array
        employees.append(
            {
                "Name": employee.name,
                "Base_Salary": employee.base_salary,
                "HRA": employee.HRA,
                "Bonus": employee.bonus,
                "Deductions":  employee.deductions,
                "Gross_Salary":employee.gross_salary(),
                "Net_Salary":employee.net_salary()
            }
        )
    return employees

employee_data = gen_emp_data()
df = pd.DataFrame(employee_data)
df.to_csv(f"employee_data.csv")

print("Data saved succesfully")