/**
* @file main.cpp
* @description Veri.txt dosyasındaki sayıları okuyarak oluşturduğum avl ağaç dizisine sırayla atıyor ve yaprak olanları yigina atıp gerekekli işlemler yapılıyor.
* @course 2-B
* @assignment 1
* @date 15.12.2023
* @author Hüseyin Akbal huseyinakbal@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Dugum.hpp"
#include "AVL_Agaci.hpp"
#include "Yigin.hpp"
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	AVL_Agaci* agac[500];
	Yigin yigin[500];
	ifstream dosya("Veri.txt");
	int satirSayi = 0;
    int ascii[500];
	if (dosya.is_open())
	{
		string satir;
		while (getline(dosya, satir))
		{
			agac[satirSayi] = new AVL_Agaci();
            
			int geciciSayi;
			stringstream satirOkuyucu(satir);
			while (satirOkuyucu >> geciciSayi)
			{
				if (agac[satirSayi]->Varmi(geciciSayi) == false)
				{
					agac[satirSayi]->Ekle(geciciSayi);
				}
			}
			agac[satirSayi]->YaprakBulveYigitEkle(yigin[satirSayi]);
			int YaprakOlmayanlarToplamlar = agac[satirSayi]->YaprakOlmayanToplam();
			ascii[satirSayi] = YaprakOlmayanlarToplamlar % (90 - 65 + 1) + 65;
			if (satirSayi < 8)
			{
				//cout << yigin[satirSayi];
				//cout << "Toplam : " << YaprakOlmayanlarToplamlar << endl;
				//cout << "Ascii sayi : " << ascii << endl;
				char c = char(ascii[satirSayi]);
				cout <<  c ;
			}
			satirSayi++;
		}
		cout << endl;
	}
	dosya.close();
    
    
	int avlAgacSayi=500;
    int buyukSayiBul = 0;
    int kucukSayiBul = 0;
    int indexK = 0;
    int indexB = 0;
    /*for(int i=0;i<satirSayi;i++)
    {
        while(yigin[i].BosMu()==false)
        {cout<<yigin[i].Getir()<<"    ";
        yigin[i].Cikart();}
        cout<<endl;

    }*/

	while (true)
    {
        if(avlAgacSayi==1)
        break;
        while(true)
        {
            
            for (int i = 0; i < avlAgacSayi; i++)
            {
                
                if (yigin[i].BosMu()==false)
                {
                    if(i==0)
                    kucukSayiBul=yigin[i].Getir();
                    else
                    {  if(yigin[i].Getir() < kucukSayiBul)
                        {
                            kucukSayiBul = yigin[i].Getir();
                            indexK = i;
                        }
                    }
                }
            }
            //cout<<"kucuk sayi: "<<kucukSayiBul<<endl;
            //cout<<"kucuk id: "<<index<<endl;
            yigin[indexK].Cikart();

            if (yigin[indexK].BosMu()==true)
            {
                //cout<<"silinecek: "<<index<<endl;
                avlAgacSayi--;
                ascii[indexK]=0;
                for(int i=0;i<satirSayi;i++)
                {
                    if(ascii[i]!=0)
                    cout<<char(ascii[i]);
                }
                system("cls");
                break;
            }



            
            
            for (int i = 1; i < avlAgacSayi; i++)
            {
                if (yigin[i].BosMu()==false)
                {
                    if(i==0)
                    buyukSayiBul=yigin[i].Getir();
                    else
                    { 
                        if(yigin[i].Getir() > buyukSayiBul)
                        {
                            buyukSayiBul = yigin[i].Getir();
                            indexB = i;
                        }
                    }
                }
            }
            //cout<<"buyuk sayı: "<<buyukSayiBul<<endl;
            //cout<<"buyuk id: "<<indexB<<endl;
            yigin[indexB].Cikart();
            if (yigin[indexB].BosMu())
            {
                //cout<<"silinecek: "<<indexB<<endl;
                avlAgacSayi--;
                ascii[indexB]=0;
                for(int i=0;i<satirSayi;i++)
                {
                    if(ascii[i]!=0)
                    cout<<char(ascii[i]);

                }
                system("cls");
                break;
            }
        }
    }
    /*int YaprakOlmayanlarToplamlar = agac[30]->YaprakOlmayanToplam();
    int ascii = YaprakOlmayanlarToplamlar % (90 - 65 + 1) + 65;
    char a = char(ascii);*/
    //cout << "-------------------------" << endl;
    //cout << "-------------------------" << endl;
    //cout << "|                       |" << endl;
    //cout << "|                       |" << endl;
    //cout << "|                       |" << endl;
    //cout << "|     Son Karakter:" << c << "    |" << endl;
    //cout << "|     AVL No:" << 30 << "          |" << endl;
    //cout << "|                       |" << endl;
    //cout << "|                       |" << endl;
    //cout << "|                       |" << endl;
    //cout << "-------------------------" << endl;
    //cout << "-------------------------" << endl;
	/*for (int i = 0; i < 3; i++)
	{
		if(yigin[i].Getir()<kucukSayiBul)
		{
			kucukSayiBul = yigin[i].Getir();
			index = i;
		}
		if(yigin[i].Getir()==kucukSayiBul)
		{

		}
		
	}*/
	
	/*for (int i = 0; i < 500; i++)
	{
		cout << yigin[i];
	}*/
}