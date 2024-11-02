#ifndef DATACLASS_H
#define DATACLASS_H

#include <string>
#include <iostream>

using namespace std;

class DataClass {
private:
    string itemName;
    double price;
    string category;

public:
    DataClass(const string& name = "", double cost = 0.0, const string& type = "")
        : itemName(name), price(cost), category(type) {}

    void setItem(const string& name, double cost, const string& type) {
        itemName = name;
        price = cost;
        category = type;
    }

    string getItemName() const { return itemName; }
    double getPrice() const { return price; }
    string getCategory() const { return category; }

    void print() const {
        cout << "Item: " << itemName << ", Price: $" << price << ", Category: " << category << endl;
    }

    // Get details as a formatted string
    string getDetails() const {
        return "Item: " + itemName + ", Price: $" + to_string(price) + ", Category: " + category;
    }

    bool operator == (const DataClass& d)
    {
        if (price < d.price)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool operator > (const DataClass& d)
    {
        if (price > d.price)
        {
            return true;
        }

        else 
        {
            return false;
        }
    }

    bool operator < (const DataClass& d)
    {
        if (price < d.price)
        {
            return true;
        }

        else 
        {
            return false;
        }
    }
};

#endif
