#pragma once
#include<unordered_set>
#include <coor.h>
struct CoorKeyHasher
{
    std::size_t operator()(const Coor& k) const
    {
        using std::size_t;
        using std::hash;

        return (hash<int>()(k.x) ^ (hash<int>()(k.y) << 1));
           
    }
};