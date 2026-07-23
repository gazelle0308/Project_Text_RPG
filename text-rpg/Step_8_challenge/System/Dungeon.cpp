#include "../include/System/Dungeon.h"

void Room::SetClear(bool clear){ this->clear = clear; }
void Room::SetRoomOpen(bool open){ this->roomOpen = open; }
void Room::SetRoomNum(int num){ this->roomNum = num; }
void Room::SetEntity(std::unique_ptr<Monster> entity){ this-> entity = move(entity);}

bool Room::GetClear(){ return this->clear; }
bool Room::GetRoomOpen(){ return this->roomOpen;}
int Room::GetRoomNum(){ return this->roomNum; }
Monster& Room::GetEntity(){ return *this->entity; }

