/**
* @file Yigin.cpp
* @description Yiginin tanımlanan fonksiyonları yazıldı.
* @course 2-B
* @assignment 2
* @date 10.12.2023
* @author Hüseyin Akbal huseyinakbal@ogr.sakarya.edu.tr
*/
#include "Yigin.hpp"
#include <exception>
#include <iostream>
#include <iomanip>
using namespace std;
Yigin::Yigin()
{
    tepe = -1;
    kapasite = 0;
    veriler = 0;
    Genislet(5);
}

Yigin::~Yigin()
{
    delete[] veriler;
}

void Yigin::Genislet(int boyut)
{
    int* yeniAlan = new int[boyut+kapasite];

    for (int i = 0; i <= tepe; i++)
    {
        yeniAlan[i] = veriler[i];
    }
    
    if(veriler)
    {
        delete[] veriler;
    }
    veriler = yeniAlan;
    kapasite += boyut;
}

void Yigin::Ekle(int veri)
{
    if(tepe==kapasite-1)
    {
        Genislet(kapasite);
    }
    tepe++;
    veriler[tepe]=veri;
}

void Yigin::Cikart()
{
    if(tepe!=-1)
    {
        tepe--;
    }
}

void Yigin::Yazdir()
{
    while(tepe!=-1)
    {
        std::cout << "Tepe Degeri" << "  " << "Sayi Degeri" << std::endl;
        std::cout <<"      " <<kapasite-tepe-1 << "          " <<veriler[kapasite-tepe-1] << std::endl;
        tepe--;
    }
}

int Yigin::Getir()
{
    if(tepe!=-1)
    {
        return veriler[tepe];
    }
    throw std::out_of_range("Yigin BOS!!!");        
}

bool Yigin::BosMu()
{
    if(tepe==-1)
        return true;

    return false;
}

ostream& operator<<(ostream& os,Yigin& yigin)
{
    os<<std::setw(5)<<"---->";
    for(int i=0;i<=yigin.tepe;i++)
    {
        os<<yigin.veriler[yigin.tepe-i]<<std::endl;
        os<<std::setw(5)<<"    ";     
    }
    std::cout<<std::endl;
    return os;
}