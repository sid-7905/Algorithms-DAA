import csv
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2 
        left_half = arr[:mid]
        right_half = arr[mid:]

        inversions = merge_sort(left_half) + merge_sort(right_half)

        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] <= right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                inversions += len(left_half) - i
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

        return inversions
    return 0

def find_inversion_counts(csv_filename):
    student_inversions = []

    with open(csv_filename, mode='r') as file:
        reader = csv.reader(file)
        next(reader)

        for row in reader:
            number = row[0]
            name = row[1]
            courses = list(map(int, row[2:]))
            course_list = courses[:]
            inversion_count = merge_sort(course_list)

            student_inversions.append((number, name, inversion_count))

    return student_inversions


csv_filename = 'students.csv'
inversions = find_inversion_counts(csv_filename)

for student in inversions:
    print(f"Student Number: {student[0]}, Name: {student[1]}, Inversion Count: {student[2]}")
