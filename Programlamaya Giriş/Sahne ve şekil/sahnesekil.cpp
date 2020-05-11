/****************************************************************************
**
**				��RENC� ADI...........................:K�bra Y�lmaz
**				��RENC� NUMARASI.............:B181210023
**				DERS GRUBU�������:1/C
****************************************************************************/

#include<iostream>
#include<Windows.h>
#include<time.h>

using namespace std;

int dizigenislik[3] = { 30,40,50 }; //sahne geni�li�inin alabilece�i de�erler
char dizibicim[5] = { '*','#','$','+','@' }; //sahne ve l �eklinin alabilece�i �ekiller


void gotoxy(int x, int y) //konsolda istedi�im koordinatlarda �ekil ��karabilece�im fonksiyon
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct Sahne //Sahne �zelliklerini tan�mlad���m yap�
{
	 int genislik;
	 int yukseklik;
	 char bicim;
};

Sahne sahneOlustur()//Sahne �zelliklerine de�er at�yorum
{
	Sahne sahne;
	int i = rand() % 3;
	char x = rand() % 5;
	sahne.genislik = dizigenislik[i];//diziden rastgele de�er se�iyorum
	sahne.bicim = dizibicim[x];
	sahne.yukseklik = rand() % 11 + 20;

	return sahne;

}

void sahneCiz(Sahne a) //ald��� parametreye g�re istenen koordinatlara L �ekli ��kar�yor
{
	
	for (int i = 0; i <a.genislik ; i++)
	{
		cout <<a.bicim;
	}


	for (int i = 0; i <a.yukseklik; i++)
	{
		gotoxy(a.genislik-1, i); //koordinatlar� boyut cinsinden ayarlayarak boyutlar de�i�se bile sahnemin d�zg�n ��kmas�n� sa�l�yorum
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

struct LSekli //L �eklimin �zelliklerini tan�mlad���m yap�
{
	int x;
	int y;
	int boyut;
	char sekil;
};

LSekli lSekliOlustur() //L �eklinin �zelliklerine parametre at�yorum
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

	return lsekil; //olu�turdu�um de�erleri d�nd�r�yorum
}

void lSekilCiz(LSekli l)
{
	int x = l.x;
	int y = l.y;
	
	gotoxy(x, y);
	for (int i = 0; i < l.boyut / 2; i++)//koordinatlar� boyut cinsinden ayarlayarak boyutlar de�i�se bile L �eklimin d�zg�n ��kmas�n� sa�l�yorum
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

LSekli lSekliAsag�Gotur(LSekli s,Sahne sa) // Parametre olarak ald���m �eklin a�a�� indiren fonksiyon
{
	LSekli sekil2 = s;
	
		sekil2.y++;//y koordinat�n� artt�rarak a�a�� inmesini sa�lad�m

		return sekil2;//yeni �eklimi g�nderdim
}






int main()
{
	srand(time(NULL)); //rastgele de�er atama fonksiyonumu �a��rd�m
	Sahne b = sahneOlustur(); //sahne olu�turma fonksiyonu
	
	while (true)
	{
		LSekli l = lSekliOlustur(); //d�ng� her bitti�inde yeniden olu�mas� i�in d�ng�de tan�mlad�m
		LSekli a = lSekliAsag�Gotur(l, b);

		system("cls"); //ekran� temizler

		sahneCiz(b);
		lSekilCiz(l);
		while (a.y + a.boyut < b.yukseklik) //�eklin sahneden ta�mamas� i�in
		{
			system("cls");
			sahneCiz(b);
			lSekilCiz(a);
		    a = lSekliAsag�Gotur(a, b); //��kan �ekli ko�ul sa�lad�k�a tekrar yerini de�i�tiriyorum
			

			Sleep(100); //�eklimin yava� hareket etmesi i�in
		}
	}

	
	cin.get();
}