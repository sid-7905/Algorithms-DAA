// import csv 
// class Item:
//     def __init__(self, value, weight, shelf_life):
//         self.value = value
//         self.weight = weight
//         self.shelf_life = shelf_life
//         self.priority = value / (weight * shelf_life) 

// def fractional_knapsack(items, capacity):
   
//     items.sort(key=lambda x: x.priority, reverse=True)
    
//     total_value = 0
//     for item in items:
//         if capacity <= 0: 
//             break
//         if item.weight <= capacity:
//             total_value += item.value
//             capacity -= item.weight
//         else:
//             fraction = capacity / item.weight
//             total_value += item.value * fraction
//             capacity = 0 

//     return total_value

// def read_items_from_csv(filename):
//     items = []
//     with open(filename, mode='r') as file:
//         reader = csv.reader(file)
//         next(reader) 
//         for row in reader:
//             item_id, value, weight, shelf_life = row
//             item = Item(float(value), float(weight), float(shelf_life))
//             items.append(item)
//     return items


// if __name__ == "__main__":
//     items = read_items_from_csv('items.csv')

//     capacity = 200

//     max_value = fractional_knapsack(items, capacity)
//     print(f"Maximum value in the knapsack = {max_value:.2f}")
    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <sstream>
    #include <algorithm>

    class Item {
    public:
        double value, weight, shelf_life, priority;

        Item(double v, double w, double s) : value(v), weight(w), shelf_life(s) {
            priority = value / (weight * shelf_life);
        }
    };

    bool compare(Item a, Item b) {
        return a.priority > b.priority;
    }

    double fractional_knapsack(std::vector<Item>& items, double capacity) {
        std::sort(items.begin(), items.end(), compare);

        double total_value = 0.0;
        for (auto& item : items) {
            if (capacity <= 0) break;
            if (item.weight <= capacity) {
                total_value += item.value;
                capacity -= item.weight;
            } else {
                double fraction = capacity / item.weight;
                total_value += item.value * fraction;
                capacity = 0;
            }
        }
        return total_value;
    }

    std::vector<Item> read_items_from_csv(const std::string& filename) {
        std::vector<Item> items;
        std::ifstream file(filename);
        std::string line, word;
        std::getline(file, line); // Skip header
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> row;
            while (std::getline(ss, word, ',')) {
                row.push_back(word);
            }
            double value = std::stod(row[1]);
            double weight = std::stod(row[2]);
            double shelf_life = std::stod(row[3]);
            items.emplace_back(value, weight, shelf_life);
        }
        return items;
    }

    int main() {
        std::vector<Item> items = read_items_from_csv("items.csv");

        double capacity = 200.0;

        double max_value = fractional_knapsack(items, capacity);
        std::cout << "Maximum value in the knapsack = " << max_value << std::endl;

        return 0;
    }