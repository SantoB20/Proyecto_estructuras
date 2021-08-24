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
        void setTam(unsigned int tam);
        unsigned int getTam();
        void agregarIndice(unsigned int ind);
        std::vector<unsigned int> getIndices();
};

#endif //_CARA_H_