#ifndef AVL_Agaci_HPP
#define AVL_Agaci_HPP
#include "Dugum.hpp"
#include "Yigin.hpp"
#include <iostream>
using namespace std;
class AVL_Agaci
{
private:
    int yaprakOlmayanToplamlar;
    Dugum* kok;
    Dugum* SagaDondur(Dugum* buyukEbeveyn);
    Dugum* SolaDondur(Dugum* buyukEbeveyn);
    Dugum* Ekle(int veri,Dugum* aktif);
    Dugum* Sil(int veri,Dugum* aktif);
    void YaprakBulveYigitEkle(Dugum*aktif,Yigin& yigin);
    bool Varmi(int aranan,Dugum* aktif);
    int Yukseklik(Dugum* aktif);
    int MinDeger(Dugum* aktif);
    int MaxDeger(Dugum* aktif);
    int DengesizlikYonu(Dugum* aktif);
    void YaprakOlmayanToplam(Dugum* aktif);
    void levelOrder();
	void preOrder(Dugum* aktif);
	void postOrder(Dugum* index);
	void inOrder(Dugum* index);
public:
    AVL_Agaci();
    ~AVL_Agaci();
    void Ekle(int veri); 
    void Sil(int veri);
    void preOrder();
	void postOrder();
	void inOrder();
    void YaprakBulveYigitEkle(Yigin& yigin);
    int YaprakOlmayanToplam();
    int Yukseklik();
    bool Varmi(int aranan);
    friend ostream& operator<<(ostream& os,AVL_Agaci& kuyruk);
};

#endif