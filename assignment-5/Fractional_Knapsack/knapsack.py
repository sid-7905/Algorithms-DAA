import csv 
class Item:
    def __init__(self, value, weight, shelf_life):
        self.value = value
        self.weight = weight
        self.shelf_life = shelf_life
        self.priority = value / (weight * shelf_life) 

def fractional_knapsack(items, capacity):
   
    items.sort(key=lambda x: x.priority, reverse=True)
    
    total_value = 0
    for item in items:
        if capacity <= 0: 
            break
        if item.weight <= capacity:
            total_value += item.value
            capacity -= item.weight
        else:
            fraction = capacity / item.weight
            total_value += item.value * fraction
            capacity = 0 

    return total_value

def read_items_from_csv(filename):
    items = []
    with open(filename, mode='r') as file:
        reader = csv.reader(file)
        next(reader) 
        for row in reader:
            item_id, value, weight, shelf_life = row
            item = Item(float(value), float(weight), float(shelf_life))
            items.append(item)
    return items


if __name__ == "__main__":
    items = read_items_from_csv('items.csv')

    capacity = 200

    max_value = fractional_knapsack(items, capacity)
    print(f"Maximum value in the knapsack = {max_value:.2f}")
