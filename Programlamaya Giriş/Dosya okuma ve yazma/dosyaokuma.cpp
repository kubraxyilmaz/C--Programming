/****************************************************************************
**
**				ÖÐRENCÝ ADI...........................:Kübra Yýlmaz
**				ÖÐRENCÝ NUMARASI.............:B181210023
**				DERS GRUBU…………………:1C
****************************************************************************/

#include <iostream> 
#include <fstream> 
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class DosyaYonetim
{
public:
	string IsimOkuma(int sýra)
	{
		ifstream dosyaOku("isimler.txt"); //isimler dosyasini ac 

		if (!dosyaOku) { cout << "Dosya acilamiyor\n"; }

		char isimsatir[255];
		int sayac = 0;
		string word;
		while (!dosyaOku.eof()) {
			dosyaOku.getline(isimsatir, 255);
			sayac++;
			if (sayac == sýra)
			{
				word = isimsatir;
			}

		}
		dosyaOku.close();
		return word;
	}

	string SoyisimOkuma(int sýra)
	{
		ifstream dosyaOku("soyisimler.txt"); //isimler dosyasini ac 

		if (!dosyaOku) { cout << "Dosya acilamiyor\n"; }

		char isimsatir[255];
		int sayac = 0;
		string word;
		while (!dosyaOku.eof()) {
			dosyaOku.getline(isimsatir, 255);
			sayac++;
			if (sayac == sýra)
			{
				word = isimsatir;
			}

		}
		dosyaOku.close();
		return word;
	}

	string KayitlarOkuma(int sýra)
	{
		ifstream dosyaOku("kayitlar.txt"); //isimler dosyasini ac 

		if (!dosyaOku) { cout << "Dosya acilamiyor\n"; }

		char isimsatir[255];
		int sayac = 0;
		string cumlee;
		while (!dosyaOku.eof()) {
			dosyaOku.getline(isimsatir, 255);
			sayac++;
			if (sayac == sýra)
			{
				cumlee = isimsatir; // diðerlerinide yap
			}

		}
		dosyaOku.close();
		return cumlee;
	}

	void dosyaYazma(string ogrenci)
	{
		ofstream dosyaYaz("dosya.txt");
		dosyaYaz << ogrenci + "\n";
		dosyaYaz.close();
	}
};

class Ogrenci
{
	string isim = "";
	string soyisim = "";
	int numara = 0;
public:
	DosyaYonetim dy;
	string ogrenci_isim, ogrenci_soyisim, b = "";
	int rastgeleIsim, rastgelesoyisim;

	int getNumara() {
		return numara;
	}

	int setNumara(int sayi)
	{
		numara = sayi;
		return numara;
	}

	string getIsim()
	{
		return isim;
	}

	void setIsim(string _isim)
	{
		isim = _isim;
	}

	string getSoyisim()
	{
		return soyisim;
	}

	void setSoyisim(string _soyisim)
	{
		soyisim = _soyisim;
	}

	void isimGonder()
	{
		rastgeleIsim = rand() % 4945 + 1;
		setIsim(dy.IsimOkuma(rastgeleIsim)); // Rastgele isim
	}

	void soyisimGonder()
	{
		rastgelesoyisim = rand() % 278 + 1;
		setSoyisim(dy.SoyisimOkuma(rastgelesoyisim)); // Rastgele soyisim
	}

	//void numaraAta() // BAKILACAK
	//{
	//	setNumara(enYuksukNumara);
	//}
};

class Sinif
{

public:
	Ogrenci sinifOgrenciSayisi[100];
	int ogrenciSayisi;
	string sinifIsmi = "";

	string sinifIsmiAta() 
	{
		static const string karakterler = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string sinifsayisi[] = { "1,2,3,4,5,6,7,8,9,10" };
		string sinifIsmi;
		sinifIsmi = karakterler[rand() % 25 + 1];

		return sinifIsmi;
	}

	void ogrenciEkle()
	{
		string tempIsim;
		int tempSayi;

		for (int i = 0; i < 100; i++)
		{
			tempIsim = sinifOgrenciSayisi[i].getIsim();
			if (tempIsim == "")
			{
				tempSayi = i;
				break;
			}
		}

		sinifOgrenciSayisi[tempSayi].isimGonder();
		sinifOgrenciSayisi[tempSayi].soyisimGonder();
		sinifOgrenciSayisi[tempSayi].setNumara(2);
	}

	void ogrenciSil(int numara)
	{
		int tempNo;
		int tempSayi = 0;

		for (int i = 0; i < 100; i++)
		{
			tempNo = sinifOgrenciSayisi[i].getNumara();
			if (tempNo == numara)
			{
				tempSayi = i;
				break;
			}
		}

		sinifOgrenciSayisi[tempSayi].setIsim("");
		sinifOgrenciSayisi[tempSayi].setSoyisim("");
		sinifOgrenciSayisi[tempSayi].setNumara(0);
	}
};


class Okul
{
public:
	DosyaYonetim yy;
	Sinif  sinif[10];
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	Okul()
	{
		string kelime, ad, soyad;
		int no = 0, ogrenciSayisi = 0;
		int sayac = 0;
		ifstream dosyaOku("kayitlar.txt");
		if (!dosyaOku) { cout << "Dosya acista hata\n"; }
		if (dosyaOku.is_open())
		{
			while (!dosyaOku.eof())
			{
				dosyaOku >> kelime;
				sinif[sayac].sinifIsmi = kelime;
				dosyaOku >> ogrenciSayisi;
				sinif[sayac].ogrenciSayisi = ogrenciSayisi;
				for (int i = 0; i < ogrenciSayisi; i++)
				{
					dosyaOku >> ad;
					sinif[sayac].sinifOgrenciSayisi[i].setIsim(ad);
					dosyaOku >> soyad;
					sinif[sayac].sinifOgrenciSayisi[i].setSoyisim(soyad);
					dosyaOku >> no;
					sinif[sayac].sinifOgrenciSayisi[i].setNumara(no);
				}
				sayac++;
			}
		}
		dosyaOku.close();
	}

	void ustYazdir()
	{
		cout << solUstKose;
		for (int i = 0; i < 16; i++)
		{
			cout << duz;
		}
		cout << sagUstKose;
	}

	void sinifIsimYazdir(int toplamSinif)
	{
		for (int k = 0; k < toplamSinif; k++)
		{
			cout << dikey;
			cout << "       " + sinif[k].sinifIsmi + "       ";
			cout << dikey;
		}

	}

	void altYazdir()
	{
		cout << solAltKose;
		for (int i = 0; i < 16; i++)
		{
			cout << duz;
		}
		cout << sagAltKose;
	}

	void birinciSatir()
	{
		cout << "  " << solUstKose;
		for (int i = 0; i < 12; i++)
		{
			cout << duz;
		}
		cout << sagUstKose << "  ";
	}

	void ikinciSatir(int satir, int sutun)
	{
		int harfSayisi;
		harfSayisi = sinif[satir].sinifOgrenciSayisi[sutun].getIsim().length();
		cout << "  " << dikey;
		for (int i = 0; i < (12 - harfSayisi); i++)
		{
			cout << " ";
		}
		cout << sinif[satir].sinifOgrenciSayisi[sutun].getIsim();
		cout << dikey << "  ";
	}

	void ucuncuSatir(int satir, int sutun)
	{
		int harfSayisi;
		harfSayisi = sinif[satir].sinifOgrenciSayisi[sutun].getSoyisim().length();
		cout << "  " << dikey;
		for (int i = 0; i < (12 - harfSayisi); i++)
		{
			cout << " ";
		}
		cout << sinif[satir].sinifOgrenciSayisi[sutun].getSoyisim();
		cout << dikey << "  ";
	}

	void dorduncuSatir(int satir, int sutun)
	{
		int harfSayisi;
		harfSayisi = 3;
		cout << "  " << dikey;
		for (int i = 0; i < (12 - harfSayisi); i++)
		{
			cout << " ";
		}
		cout << sinif[satir].sinifOgrenciSayisi[sutun].getNumara();
		cout << dikey << "  ";
	}

	void besinciSatir()
	{
		cout << "  " << solAltKose;
		for (int i = 0; i < 12; i++)
		{
			cout << duz;
		}
		cout << sagAltKose << "  ";
	}

	int yuksekEleman()
	{
		string deger = "";
		int sayi = 0, enbuyuk = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 100; i++)
			{
				deger = sinif[j].sinifOgrenciSayisi[i].getIsim();
				if (deger == "")
				{
					if (sayi >= enbuyuk)
					{
						enbuyuk = sayi;
						sayi = 0;
						break;
					}
				}
				sayi++;
			}
		}

		return enbuyuk;
	}

	int sinifSayisi()
	{
		int siniftoplami = 0;
		for (int i = 0; i < 10; i++)
		{
			string deger = "";
			deger = sinif[i].sinifIsmi;
			if (deger == "")
			{
				siniftoplami = i - 1;
				break;
			}
		}
		return siniftoplami;
	}


	int elemanSayisi(int classNumber)
	{
		int deger2 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sinif[classNumber].sinifOgrenciSayisi[i].getIsim() == "")
			{
				deger2 = i;
				break;
			}

		}
		return deger2;
	}

	void yazdir()
	{

		for (int k = 0; k < sinifSayisi(); k++) // üst
		{
			ustYazdir();
		}
		cout << endl;
		sinifIsimYazdir(sinifSayisi()); // sýnýf adý
		cout << endl;
		for (int k = 0; k < sinifSayisi(); k++) // alt
		{
			altYazdir();
		}
		cout << endl;

		int bir = 0;
		for (int j = 0; j < yuksekEleman(); j++)
		{
			for (int s = 0; s < sinifSayisi(); s++)
			{

				if (sinif[s].sinifOgrenciSayisi[j].getIsim() != "")
				{
					birinciSatir();
				}
				else
				{
					cout << "                  ";
				}
			}
			cout << endl;
			for (int a = 0; a < sinifSayisi(); a++)
			{
				if (sinif[a].sinifOgrenciSayisi[j].getIsim() != "")
				{
					ikinciSatir(a, j);
				}
				else
				{
					cout << "                  ";
				}
			}
			cout << endl;
			for (int c = 0; c < sinifSayisi(); c++)
			{
				if (sinif[c].sinifOgrenciSayisi[j].getIsim() != "")
				{
					ucuncuSatir(c, j);
				}
				else
				{
					cout << "                  ";
				}
			}
			cout << endl;
			for (int q = 0; q < sinifSayisi(); q++)
			{
				if (sinif[q].sinifOgrenciSayisi[j].getIsim() != "")
				{
					dorduncuSatir(q, j);
				}
				else
				{
					cout << "                  ";
				}
			}
			cout << endl;
			for (int p = 0; p < sinifSayisi(); p++)
			{
				if (sinif[p].sinifOgrenciSayisi[j].getIsim() != "")// boþluða bak
				{
					besinciSatir();
				}
				else
				{
					cout << "                  ";
				}
			}
			cout << endl;
		}

		cout << endl;


	}

	void menuYazdir()
	{
		cout << "1.Ogrenci Ekle" << endl;
		cout << "2.Sinif Ekle" << endl;
		cout << "3.Ogrenci Degistir" << endl;
		cout << "4.Ogrenci Sil" << endl;
		cout << "5.Sinif Sil" << endl;
		cout << "6.Cikis" << endl;
	}

	void dosyaYazdir()
	{
		ofstream dosya1;
		dosya1.open("kayitlar.txt");

		for (int i = 0; i < sinifSayisi(); i++)
		{
			dosya1 << sinif[i].sinifIsmi;
			dosya1 << endl;
			int sayac = 0;
			for (int j = 0; j < 20; j++)
			{
				if (sinif[i].sinifOgrenciSayisi[j].getIsim() == "")
				{
					sayac = j;
					break;
				}
			}
			dosya1 << sayac;
			dosya1 << endl;

			for (int k = 0; k < sayac; k++)
			{
				dosya1 << sinif[i].sinifOgrenciSayisi[k].getIsim() + " " + sinif[i].sinifOgrenciSayisi[k].getSoyisim() + " ";
				dosya1 << sinif[i].sinifOgrenciSayisi[k].getNumara() << endl;
			}

		}
		dosya1.close(); //ile dosya kapanýr 
	}

	int enYuksekNo()
	{
		int buyuk = 0;
		int temp = 0;
		for (int i = 0; i < sinifSayisi(); i++)
		{
			for (int j = 0; j < elemanSayisi(j); j++)
			{
				buyuk = sinif[i].sinifOgrenciSayisi[j].getNumara();
				if (buyuk > temp)
				{
					temp = buyuk;
				}
			}
		}
		return temp + 1;
	}

	void sinifEkle()
	{
		sinif[sinifSayisi()].sinifIsmi = sinif[sinifSayisi()].sinifIsmiAta();
	}
};

class Program
{
public:
	Okul o;

	void calistir()
	{
		string sinif_isim, sinif_isim2;
		int silinecek_ogrenci;
		int sinif_numarasi;

		int secim = 0;
		while (secim != 6)
		{
			system("cls");
			o.yazdir();
			o.menuYazdir();
			cin >> secim;

			switch (secim)
			{
			case 1:
			{
				cout << "sinif adi:";
				cin >> sinif_isim;

				for (int i = 0; i < o.sinifSayisi(); i++) // Sýnýf bulunuyor
				{
					if (o.sinif[i].sinifIsmi == sinif_isim)
					{
						o.sinif[i].ogrenciEkle();
						cout << endl;
						system("cls");
						o.yazdir();
						cout << "ogrenci Adi   :" + o.sinif[i].sinifOgrenciSayisi[o.elemanSayisi(i) - 1].getIsim() << endl;
						cout << "ogrenci soyAdi:" +o.sinif[i].sinifOgrenciSayisi[o.elemanSayisi(i) - 1].getSoyisim() << endl;
						cout << "ogrenci numara:" + o.sinif[i].sinifOgrenciSayisi[o.elemanSayisi(i) - 1].setNumara(o.enYuksekNo()) << endl;
						break;
					}
				}
			}
			break;
			case 2:
			{
				o.sinifEkle();
				system("cls");

			}
			break;
			case 3:
			{
				cout << "ogrenci no:";
				cin >> silinecek_ogrenci;
				int deg, der;
				for (int i = 0; i < o.sinifSayisi(); i++) // Sýnýf bulunuyor
				{
					for (int j = 0; j < o.elemanSayisi(i); j++)
					{
						if (o.sinif[i].sinifOgrenciSayisi[j].getNumara() == silinecek_ogrenci)
						{
							deg = i;
							der = j;
							system("cls");
							break;
						}
					}
				}
				o.sinif[deg].sinifOgrenciSayisi[der].isimGonder();
				o.sinif[deg].sinifOgrenciSayisi[der].soyisimGonder();
				o.sinif[deg].sinifOgrenciSayisi[der].setNumara(o.enYuksekNo());
				cout << endl;
				cout << "ogrenci Adi   :" << o.sinif[deg].sinifOgrenciSayisi[der].getIsim() << endl;
				cout << "ogrenci soyAdi:" << o.sinif[deg].sinifOgrenciSayisi[der].getSoyisim() << endl;
				cout << "ogrenci numara:" << o.sinif[deg].sinifOgrenciSayisi[der].getNumara() << endl;
			}
			break;
			case 4:
			{
				cout << "ogrenci no:";
				cin >> silinecek_ogrenci;

				for (int i = 0; i < o.sinifSayisi(); i++) // Sýnýf bulunuyor
				{
					for (int j = 0; j < o.elemanSayisi(i); j++)
					{
						if (o.sinif[i].sinifOgrenciSayisi[j].getNumara() == silinecek_ogrenci)
						{
							o.sinif[i].ogrenciSil(silinecek_ogrenci);
							cout << endl;
							system("cls");
							break;
						}
					}
				}

			}
			break;
			case 5:
			{
				cout << "sinif adi:";
				cin >> sinif_isim;
				int drg = 0;
				for (int i = 0; i < o.sinifSayisi(); i++) // Sýnýf bulunuyor
				{
					if (o.sinif[i].sinifIsmi == sinif_isim)
					{
						o.sinif[i].sinifIsmi = "";
						drg = o.elemanSayisi(i);
						for (int j = 0; j < drg; j++)
						{
							o.sinif[i].sinifOgrenciSayisi[j].setIsim("");
							o.sinif[i].sinifOgrenciSayisi[j].setSoyisim("");
							o.sinif[i].sinifOgrenciSayisi[j].setNumara(0);
							//o.sinif[i].ogrenciSayisi = 0;
						}
						cout << endl;
						system("cls");
						break;
					}
				}
			}
			break;
			case 6:
				break;
			default:
				break;
			}
			o.dosyaYazdir();
		}

	}
};



int main()
{
	Program prog;
	prog.calistir();


	
	cout << "merhaba";
	system("pause");
	return 0;
}