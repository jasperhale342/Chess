#pragma once
#pragma once
#include<unordered_set>
#include <piece_type.h>
struct PieceTypeKeyHasher
{
    std::size_t operator()(const PieceType& k) const
    {
        using std::size_t;
        using std::hash;

        return (hash<int>()(k));

    }
};