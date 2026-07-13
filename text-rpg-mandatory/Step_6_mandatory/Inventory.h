#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item
{
    string name;
    int price;
    void PrintInfo() const
    {

        cout << name << "(" << price << "G)" << endl;

    }

};

Item BuildItem( const string name, const int price );

void InsertInventory( const Item& item, vector<Item>& Inventory );
void deleteInventory( const Item* item, vector<Item>& Inventory );