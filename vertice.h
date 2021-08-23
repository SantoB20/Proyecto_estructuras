#ifndef _VERTICE_H_
#define _VERTICE_H_

class Vertice{
    private:
        unsigned int indice;
        int px;
        int py;
        int pz;
    public:
        Vertice();
        void setIndice(unsigned int ind);
        void setPx(int x);
        void setPy(int y);
        void setPz(int z);
        unsigned int getIndice();
        int getPx();
        int getPy();
        int getPz();

};

#endif //_VERTICE_H_