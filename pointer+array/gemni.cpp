#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream file("pricec.txt");
    string temp;
    int index;
    double currentPrice;
    double totalSum = 0;
    int count = 0;

    if (file.is_open()) {
        // We use a while loop because we don't know if there are 4, 8, or 100 prices
        while (file >> temp) { 
            // Logic: If 'temp' is a number (the index), the NEXT thing is the price
            // But 'temp' might be the word "list" or "item"
            
            // Try to read the index and price
            if (isdigit(temp[0])) { // Check if the first character is a number
                index = stoi(temp); // Convert string to int
                file >> currentPrice; // Read the actual price
                
                totalSum += currentPrice;
                count++;
            }
        }
        file.close();

        cout << "Total items found: " << count << endl;
        cout << "Total Sum: " << totalSum << endl;
        if(count > 0) cout << "Average: " << totalSum / count << endl;
    } else {
        cout << "Error opening file.";
    }
    return 0;
}