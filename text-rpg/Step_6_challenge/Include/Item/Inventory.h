#pragma once

#include <sstream>
#include <stdexcept>
#include <algorithm>

#include "../Common.h"
#include "../Constants.h"

#include "Item.h"

template<typename T>
class Inventory
{

public:

    void AddItem(T item)
    {
        //인벤토리 크기 검증
        if(this->size_ >= this->capacity_)
        { 
            std::cout << "Inventory Is Full! " << this->size_ << "/" << this->capacity_ << std::endl;
            this->Resize(capacity_ * 2); 
        }

        this->pItems_[this->size_] = item;
        this->size_ = this->size_ + 1;
    }

    void RemoveLastItem()
    {
        this->size_ = this->size_ - 1;
    }

    void Resize(int newCapacity)
    {
        //확장된 인벤토리용 buffer
        std::cout << "Resize Inventory.... "<< std::endl;
        T* Buf = new T[newCapacity];
        for(int loop = 0; loop < this->size_; loop = loop + 1){ Buf[loop] = this->pItems_[loop]; } //buffer로 값 복사
        
        delete[] this->pItems_;//기존 Inventory를 delete

        this->pItems_ = Buf;//ptr 이동

        Buf = nullptr;//buffer 해제
        this->capacity_ = newCapacity;
        std::cout << "Complete! Now " << this->size_ << "/" << this->capacity_ << "!" << std::endl;
    }

    void EraseItem(int num)
    {
        if(num >= this->size_ || num < 0){ return; }
        else if(num == this->size_ - 1){ this->RemoveLastItem(); return; }
        for(int loop = num; loop < this->size_ - 1; loop = loop + 1)
        { 
            this->pItems_[loop] = this->pItems_[loop + 1]; 
        }
        this->size_ = this->size_ - 1;
    }


    void PrintAllItems()
    {
        for(int loop = 0; loop < size_; loop = loop + 1)
        {
            std::cout << this->pItems_[loop].GetName() << "(" << this->pItems_[loop].GetPrice() << "G) x" << this->pItems_[loop].GetCount() << std::endl;
        }
    }

    void SortItems(){ std::sort(this->pItems_, this->pItems_ + this->size_, compareByPrice); }

    void SetSize(int size){ this->size_ = size; }
    void SetCapacity(int capacity){ this->capacity_ = capacity; }

    int GetSize() const{ return this->size_; }
    int GetCapacity() const{ return this->capacity_; }


    Inventory(int capacity = 10):capacity_(capacity),size_(0){ pItems_ = new T[capacity]; } // 기본 생성자


    Inventory(const Inventory& other)// 복사 생성자
    {
        this->pItems_ = new T[other.capacity_];
        this->capacity_ = other.capacity_;
        this->size_ = other.size_;
        for(int loop = 0; loop < this->size_; loop = loop + 1){ this->pItems_[loop] = other.pItems_[loop]; }
    }


    Inventory& operator=(const Inventory& other)
    {
        //자신인지 확인
        if( &other == this ){ return *this; }

        //other 내부 정리
        delete[] this->pItems_;

        //other 내부 값 재정리
        this->capacity_ = other.capacity_;
        this->size_ = other.size_;
        this->pItems_ = new T[other.capacity_];

        //other에 this 값 복사
        for(int loop = 0; loop < this->size_; loop = loop + 1){ this->pItems_[loop] = other.pItems_[loop]; }

        return *this;

    }


    T& operator[](const int num) const
    {
        if(num >= this->size_ || num < 0){ throw std::out_of_range("Inventory index out of range"); }
        return this->pItems_[num];
    }

    
    ~Inventory(){ delete[] pItems_; }


private:

    T* pItems_ = nullptr;
    int capacity_;
    int size_;

};

/*-------------------------Inventory-----------------------------*/

bool compareByPrice(const Item& a, const Item& b);
void SortCallable(Inventory<Item>& inventory);
std::string ItemInfo(const Inventory<Item>& inventory);
bool reserchUse(const Inventory<Item>& inventory, int itemNumber);
void InsertInventory(const Item& item, Inventory<Item>& inventory);
void DeleteInventory(const Item* item, Inventory<Item>& inventory);
Item BuildItem(const std::string name, const int price, const int count = 1);