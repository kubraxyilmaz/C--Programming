/****************************************************************************
**
**				ÖÐRENCÝ ADI...........................:Kübra Yýlmaz
**				ÖÐRENCÝ NUMARASI.............:B181210023
**				DERS GRUBU…………………:1/C
****************************************************************************/

#include<iostream>
#include<Windows.h>
#include<time.h>

using namespace std;

int dizigenislik[3] = { 30,40,50 }; //sahne geniþliðinin alabileceði deðerler
char dizibicim[5] = { '*','#','$','+','@' }; //sahne ve l þeklinin alabileceði þekiller


void gotoxy(int x, int y) //konsolda istediðim koordinatlarda þekil çýkarabileceðim fonksiyon
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct Sahne //Sahne özelliklerini tanýmladýðým yapý
{
	 int genislik;
	 int yukseklik;
	 char bicim;
};

Sahne sahneOlustur()//Sahne özelliklerine deðer atýyorum
{
	Sahne sahne;
	int i = rand() % 3;
	char x = rand() % 5;
	sahne.genislik = dizigenislik[i];//diziden rastgele deðer seçiyorum
	sahne.bicim = dizibicim[x];
	sahne.yukseklik = rand() % 11 + 20;

	return sahne;

}

void sahneCiz(Sahne a) //aldýðý parametreye göre istenen koordinatlara L þekli çýkarýyor
{
	
	for (int i = 0; i <a.genislik ; i++)
	{
		cout <<a.bicim;
	}


	for (int i = 0; i <a.yukseklik; i++)
	{
		gotoxy(a.genislik-1, i); //koordinatlarý boyut cinsinden ayarlayarak boyutlar deðiþse bile sahnemin düzgün çýkmasýný saðlýyorum
		cout <<a.bicim << endl;
	}

	for (int i = a.genislik; i >= 0; i--)
	{
		gotoxy(i - 1, a.yukseklik);
		cout <<a.bicim;
	}

	for (int i = a.yukseklik; i >= 0; i--)
	{
		gotoxy(0, i);
		cout <<a.bicim<< endl;
	}
}

struct LSekli //L Þeklimin özelliklerini tanýmladýðým yapý
{
	int x;
	int y;
	int boyut;
	char sekil;
};

LSekli lSekliOlustur() //L Þeklinin özelliklerine parametre atýyorum
{
	char L = rand() % 5;
	LSekli lsekil;
	lsekil.x=rand() % 21 + 5;
	lsekil.y = 3;
	lsekil.boyut = rand() % 6 + 2;
	if (lsekil.boyut % 2 == 1)
	{
		lsekil.boyut = lsekil.boyut + 1;
	}
	lsekil.sekil = dizibicim[L];

	return lsekil; //oluþturduðum deðerleri döndürüyorum
}

void lSekilCiz(LSekli l)
{
	int x = l.x;
	int y = l.y;
	
	gotoxy(x, y);
	for (int i = 0; i < l.boyut / 2; i++)//koordinatlarý boyut cinsinden ayarlayarak boyutlar deðiþse bile L Þeklimin düzgün çýkmasýný saðlýyorum
	{
		cout <<l.sekil;
	}
	for (int i = 0; i < l.boyut / 2; i++)
	{
		gotoxy(x + (l.boyut / 2) - 1, y + 1);
		cout <<l.sekil << endl;
		y++;
	}
	for (int i = 0; i < l.boyut / 2; i++)
	{
		gotoxy(x + (l.boyut / 2) - 1, y);
		cout <<l.sekil;
		x++;
	}
	for (int i = 0; i < l.boyut / 2; i++)
	{
		gotoxy(x + (l.boyut / 2) - 1, y);
		cout <<l.sekil;
		y++;
	}
	for (int i = 0; i < l.boyut; i++)
	{
		gotoxy(x + (l.boyut / 2) - 1, y);
		cout <<l.sekil;
		x--;
	}
	for (int i = 0; i < l.boyut - 1; i++)
	{
		gotoxy(x + (l.boyut / 2), y + 1 - l.boyut);
		cout <<l.sekil<< endl;
		y++;
	}

}

LSekli lSekliAsagýGotur(LSekli s,Sahne sa) // Parametre olarak aldýðým þeklin aþaðý indiren fonksiyon
{
	LSekli sekil2 = s;
	
		sekil2.y++;//y koordinatýný arttýrarak aþaðý inmesini saðladým

		return sekil2;//yeni þeklimi gönderdim
}






int main()
{
	srand(time(NULL)); //rastgele deðer atama fonksiyonumu çaðýrdým
	Sahne b = sahneOlustur(); //sahne oluþturma fonksiyonu
	
	while (true)
	{
		LSekli l = lSekliOlustur(); //döngü her bittiðinde yeniden oluþmasý için döngüde tanýmladým
		LSekli a = lSekliAsagýGotur(l, b);

		system("cls"); //ekraný temizler

		sahneCiz(b);
		lSekilCiz(l);
		while (a.y + a.boyut < b.yukseklik) //þeklin sahneden taþmamasý için
		{
			system("cls");
			sahneCiz(b);
			lSekilCiz(a);
		    a = lSekliAsagýGotur(a, b); //çýkan þekli koþul saðladýkça tekrar yerini deðiþtiriyorum
			

			Sleep(100); //þeklimin yavaþ hareket etmesi için
		}
	}

	
	cin.get();
}