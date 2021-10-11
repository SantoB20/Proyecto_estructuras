#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>

struct punto
{
    unsigned int indice;
    float x;
    float y;
    float z;

    punto &operator=(const punto &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
        indice = p.indice;
        return *this;
    }
    bool operator==(const punto &p)
        const
    {
        return (y == p.y && x == p.x && z == p.z);
    }
    friend std::ostream &operator<<(std::ostream &o, const punto &p)
    {
        o << "(" << p.x << "," << p.y << "," << p.z << ")";
        return o;
    }
};

#endif
