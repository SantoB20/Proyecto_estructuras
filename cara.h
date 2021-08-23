#ifndef _CARA_H_
#define _CARA_H_

#include <vector>
#include <string>

class Cara{
    private:
        unsigned int tam;
        std::vector<unsigned int> v_indices;
    public:
        Cara();
        void setNombre(unsigned int tam);
        unsigned int getNombre(); 
}

#endif //_CARA_H_