import csv
import random

# Generate 100 different names (for simplicity, using placeholders, you can replace them with actual names)
names = [f"Student_{i}" for i in range(1, 101)]

# Function to generate random course numbers between 1001 and 1009
def generate_courses():
    return random.sample(range(1001, 1010), 6)

# Create CSV file
with open('students.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write header
    writer.writerow(['Number', 'Name', 'Course 1', 'Course 2', 'Course 3', 'Course 4', 'Course 5', 'Course 6'])
    
    # Write student data
    for number in range(1, 101):
        courses = generate_courses()
        writer.writerow([number, names[number-1]] + courses)

print("CSV file 'students.csv' generated successfully!")
