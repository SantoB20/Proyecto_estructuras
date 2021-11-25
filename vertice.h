#ifndef _VERTICE_H_
#define _VERTICE_H_

class Vertice{
    private:
        unsigned int indice;
        float px;
        float py;
        float pz;
    public:
        Vertice();
        Vertice(unsigned int ind, float x, float y, float z);
        void setIndice(unsigned int ind);
        void setPx(float x);
        void setPy(float y);
        void setPz(float z);
        unsigned int getIndice();
        float getPx();
        float getPy();
        float getPz();
};

#endif //_VERTICE_H_