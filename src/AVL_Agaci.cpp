/**
* @file AVL_Agaci.cpp
* @description AVL agacinin bütün fonksiyonları yazıldı.
* @course 2-B
* @assignment 2
* @date 10.12.2023
* @author Hüseyin Akbal huseyinakbal@ogr.sakarya.edu.tr
*/
#include "AVL_Agaci.hpp"
#include "Dugum.hpp"
#include "Yigin.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>

AVL_Agaci::AVL_Agaci()
{
    kok = 0;
    yaprakOlmayanToplamlar = 0;
}

AVL_Agaci::~AVL_Agaci()
{
    
}

void AVL_Agaci::preOrder(Dugum* aktif)
{
    if(aktif)
    {
        std::cout << aktif->veri << " ";

        preOrder(aktif->sol);

        preOrder(aktif->sag);
    }
}

void AVL_Agaci::postOrder(Dugum* aktif)
{
    if(aktif)
    {
        postOrder(aktif->sol);

        postOrder(aktif->sag);

        std::cout << aktif->veri << " ";
    }
}

void AVL_Agaci::inOrder(Dugum* aktif)
{
    if(aktif)
    {
        inOrder(aktif->sol);

        std::cout << aktif->veri << " ";

        inOrder(aktif->sag);
    }
}

void AVL_Agaci::inOrder()
{
    inOrder(kok);
    std::cout << std::endl;
}

void AVL_Agaci::postOrder()
{
    postOrder(kok);
    std::cout << std::endl;
}

void AVL_Agaci::preOrder()
{
    preOrder(kok);
    std::cout << std::endl;
}

void AVL_Agaci::Ekle(int veri)
{
    kok = Ekle(veri,kok);
}   

void AVL_Agaci::Sil(int veri)
{
    kok = Sil(veri,kok);
}

int AVL_Agaci::Yukseklik()
{
    return Yukseklik(kok);
}

int AVL_Agaci::Yukseklik(Dugum* aktif)
{
    if(aktif)
        return 1+std::max(Yukseklik(aktif->sol),Yukseklik(aktif->sag));

    return -1;
}

int AVL_Agaci::YaprakOlmayanToplam()
{
    YaprakOlmayanToplam(kok);
    return yaprakOlmayanToplamlar;
}

void AVL_Agaci::YaprakOlmayanToplam(Dugum* aktif)
{
    if(aktif)
    {
        YaprakOlmayanToplam(aktif->sol);
        YaprakOlmayanToplam(aktif->sag);
        if(aktif->sag!=0||aktif->sol!=0)
        {
            yaprakOlmayanToplamlar+=aktif->veri;
        }
    }
    else if(aktif == nullptr)
        return ;
}

int AVL_Agaci::MinDeger(Dugum* aktif)
{
    if(aktif->sol)
        return MinDeger(aktif->sol);
    return aktif->veri;
}

int AVL_Agaci::MaxDeger(Dugum* aktif)
{
    if(aktif->sag)
        return MaxDeger(aktif->sag);
    return aktif->veri;
}

int AVL_Agaci::DengesizlikYonu(Dugum* aktif)
{
    if(aktif==0)
        return 0;
    return Yukseklik(aktif->sol)-Yukseklik(aktif->sag);
}

bool AVL_Agaci::Varmi(int veri) 
{
    return Varmi(veri,kok);
}

bool AVL_Agaci::Varmi(int aranan,Dugum* aktif)
{
    if(aktif==nullptr)
    {
        return false;
    }
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return Varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return Varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}

Dugum* AVL_Agaci::Sil(int veri,Dugum* aktif)
{
    if(aktif==0) 
        return 0;
    if(aktif->veri>veri)
    {
        aktif->sol = Sil(veri,aktif->sol);
    }
    else if(aktif->veri<veri)
    {
        aktif->sag = Sil(veri,aktif->sag);
    }
    else
    {
        if(aktif->sol==0&&aktif->sag==0)
        {
            delete aktif;
            aktif = 0;  
        }
        else if(aktif->sol==0)
        {
            Dugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if(aktif->sag==0)
        {
            Dugum* sil = aktif->sol;
            *aktif = *aktif->sol;
            delete sil;
        }
        else
        {
            aktif->veri = MinDeger(aktif->sag);
            Sil(aktif->veri,aktif->sag);
        }
    }
    int denge = DengesizlikYonu(aktif);
    if(denge>1)
    {
        if(DengesizlikYonu(aktif->sol)>=0)
            return SagaDondur(aktif);
        if(DengesizlikYonu(aktif->sol)<0)
            aktif->sol=SolaDondur(aktif->sol);
            return SagaDondur(aktif);
    }
    else if(denge<-1)
    {
        if(DengesizlikYonu(aktif->sag)<=0)
            return SolaDondur(aktif);
        if(DengesizlikYonu(aktif->sag)>0)
            aktif->sag = SagaDondur(aktif->sag);
            return SolaDondur(aktif);
    }
}

Dugum* AVL_Agaci::Ekle(int veri,Dugum* aktifDugum)
{
    if (aktifDugum == 0)
        return new Dugum(veri);

    else if (aktifDugum->veri < veri)
    {
        aktifDugum->sag = Ekle(veri, aktifDugum->sag);
        if (Yukseklik(aktifDugum->sag) - Yukseklik(aktifDugum->sol) > 1)
        {
            if (veri > aktifDugum->sag->veri)
                aktifDugum = SagaDondur(aktifDugum);

            else
            {
                aktifDugum->sag = SolaDondur(aktifDugum->sag);
                aktifDugum = SagaDondur(aktifDugum);
            }
        }
    }
    else if (aktifDugum->veri > veri)
    {
        aktifDugum->sol = Ekle(veri, aktifDugum->sol);
        if (Yukseklik(aktifDugum->sol) - Yukseklik(aktifDugum->sag) > 1)
        {

            if (veri < aktifDugum->sol->veri)
                aktifDugum = SolaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = SagaDondur(aktifDugum->sol);
                aktifDugum = SolaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}

Dugum* AVL_Agaci::SolaDondur(Dugum* buyukEbeveyn)
{
    Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

Dugum* AVL_Agaci::SagaDondur(Dugum* buyukEbeveyn)
{
    Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}

void AVL_Agaci::YaprakBulveYigitEkle(Dugum* aktif,Yigin& yigin)
{
    if(aktif)
    {
        YaprakBulveYigitEkle(aktif->sol,yigin);
        YaprakBulveYigitEkle(aktif->sag,yigin);
        if(aktif->sag==0&&aktif->sol==0)
        {
            yigin.Ekle(aktif->veri);
        }
    }
    else
        return;
}

void AVL_Agaci::YaprakBulveYigitEkle(Yigin& yigin)
{
    YaprakBulveYigitEkle(kok,yigin);
}

std::ostream& operator<<(std::ostream& os,AVL_Agaci& agac)
{
    agac.postOrder();  
    return os;  
}