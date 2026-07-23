#pragma once

#include "../Common.h"
#include "../Constants.h"

/*-------------------------Item-----------------------------*/

class Item
{

private:

    bool canSell;

    int count;
    int price;

    std::string name;

public:

    Item(std::string name, int price, int count = 1, bool canSell = true);

//Setter
    void SetCanSell(bool sellSet);
    void SetCount(int count);
    void Setrice(int price);
    void SetPrice(int price);

    void SetName(std::string name);


    //Getter
    bool GetCanSell() const;

    int GetCount() const;
    int GetPrice() const;

    std::string GetName() const;

};

