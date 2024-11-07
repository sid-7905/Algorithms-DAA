import csv
import random

# Function to create a CSV file with 100 items
def create_items_csv(filename):
    # Define the header
    header = ['Item_ID', 'Value', 'Weight', 'Shelf_Life']

    # Open a CSV file for writing
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(header)

        # Generate 100 items
        for item_id in range(1, 101):
            value = random.randint(100, 1000)          # Random value between 100 and 1000
            weight = random.randint(1, 50)              # Random weight between 1 and 50
            shelf_life = random.randint(1, 10)          # Random shelf life between 1 and 10 days
            writer.writerow([item_id, value, weight, shelf_life])

    print(f"CSV file '{filename}' created with 100 items.")

# Example usage
if __name__ == "__main__":
    create_items_csv('items.csv')
