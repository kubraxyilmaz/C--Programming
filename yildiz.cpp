/****************************************************************************
**
**				��RENC� ADI...........................:K�bra Y�lmaz
**				��RENC� NUMARASI.............:B181210023
**				DERS GRUBU�������:1/C
****************************************************************************/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); //T�rk�e karakter kullanmak i�in setlocale fonksiyonunu kulland�m

	int satirSayisi;
	int sutunSayisi;

	do
		//d�ng�n�n bir kereli�ine ko�ul aramadan ger�ekle�mesi i�in 'do while' fonksiyonunu kulland�m 
	{
		cout << "S�tun say�s�, sat�r say�s�n�n 2 kat� olacak �ekilde de�er girin." << endl << endl << endl;


		cout << "�eklimiz ka� sat�rdan olu�sun?" << endl;
		cin >> satirSayisi;

		while (satirSayisi < 5 || satirSayisi>15)
			//sat�r say�s� verilen ko�ullara uyana kadar d��ardan bilgi istenmesini sa�lad�m
		{
			cout << "L�tfen 5 le 15 aras�nda bir say� giriniz. (5 ile 15 dahildir.)" << endl;
			cin >> satirSayisi;
		}

		cout << "�eklimiz ka� s�tundan olu�sun?" << endl;
		cin >> sutunSayisi;

		while (sutunSayisi < 5 || sutunSayisi>40)
			////s�tun say�s� verilen ko�ullara uyana kadar d��ardan bilgi istenmesini sa�lad�m
		{
			cout << "L�tfen 5 le 40 aras�nda bir say� giriniz. (5 ile 40 dahildir.)" << endl;
			cin >> sutunSayisi;
		}

	} while (sutunSayisi != 2 * satirSayisi);
	//s�tun say�s�, sat�r say�s�n�n 2 kat� olana kadar yukar�daki kod blogu �al��acak, ko�ul sa�land���nda �ekil ekrana �izilecek
	{
		cout << endl << endl << "Sat�r say�s� = " << satirSayisi << endl << "S�tun say�s� = " << sutunSayisi << endl << endl << endl;

		for (int i = 0; i <= sutunSayisi - 1; i++)
			//s�tun say�s� kadar yanyana * bast�r�l�yor
		{
			cout << "*";
		}
		cout << endl;
		Sleep(150);

		for (int i = 1; i < satirSayisi - 1; i++)
			//sat�r say�s� kadar d�ng� ger�ekle�iyor
		{
			cout << "*";

			for (int a = (satirSayisi - 3) - i; a >= 0; a--)
				//�ekille orant�l�, giderek azalan bo�luklar yazd�rd�m
			{
				cout << " ";
			}

			cout << "*";

			for (int j = 1; j <= 2 * i; j++)
			{
				cout << " ";
			}

			cout << "*";

			for (int a = (satirSayisi - 3) - i; a >= 0; a--)
			{
				cout << " ";
			}

			cout << "*";

			cout << endl;
			Sleep(150); //ad�mlar�n yava� yava� ger�ekle�mesi i�in sleep() fonksiyonunu kulland�m
		}

		Sleep(150);

		for (int i = 0; i <= sutunSayisi - 1; i++)
		{
			cout << "*";
		}

		cout << endl << endl << endl;
		Sleep(170);

		for (int i = 0; i <= sutunSayisi - 1; i++)
		{
			cout << "*";
		}

		cout << endl;
		Sleep(150);

		for (int i = 1; i < satirSayisi - 1; i++)
			////sat�r say�s� kadar d�ng� ger�ekle�iyor
		{
			cout << "*";

			for (int a = 2; a <= i; a++)
				////�ekille orant�l�, giderek artan bo�luklar yazd�rd�m
			{
				cout << " ";
			}

			cout << "*";

			for (int j = (sutunSayisi - 3); j >= 2 * i; j--)
			{
				cout << " ";
			}

			cout << "*";

			for (int a = 2; a <= i; a++)
			{
				cout << " ";
			}

			cout << "*";

			cout << endl;
			Sleep(150);
		}
		Sleep(150);

		for (int i = 0; i <= sutunSayisi - 1; i++)
		{
			cout << "*";
		}
	}



	system("pause");
	return 0;

}