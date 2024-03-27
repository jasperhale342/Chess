#pragma once
#include<unordered_set>
#include <piece_type_and_color.h>
struct KeyHasherPiece
{
    std::size_t operator()(const PieceTypeColor& k) const
    {
        using std::size_t;
        using std::hash;

        return (hash<int>()(k.type) ^ (hash<int>()(k.color) << 1));

    }
};