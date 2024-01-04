#ifndef Yigin_HPP
#define Yigin_HPP
#include <iostream>
using namespace std;
class Yigin
{
private:
    int tepe;
    int kapasite;
    int* veriler;
    void Genislet(int boyut);
public:
    Yigin();
    ~Yigin();
    void Ekle(int veri);
    void Cikart();
    void Yazdir();
    int Getir();
    bool BosMu();
    friend ostream& operator<<(ostream& os,Yigin& yigin);
};

#endif