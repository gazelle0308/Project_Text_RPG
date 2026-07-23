#pragma once

#include <algorithm>

#include "../Common.h"
#include "../Constants.h"

#include "../Monster/MonsterBone.h"

#include "../Ui/Ui.h"

class Room
{

public:

    Room() = default;

    void SetClear(bool clear);
    void SetRoomOpen(bool open);
    void SetRoomNum(int num);
    void SetEntity(std::unique_ptr<Monster> entity);

    bool GetClear();
    bool GetRoomOpen();
    int GetRoomNum();
    Monster& GetEntity();

private:

    bool clear = false;
    bool roomOpen = false;
    int roomNum = 0;
    std::unique_ptr<Monster> entity = nullptr;

};