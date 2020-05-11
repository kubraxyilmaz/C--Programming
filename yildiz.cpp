/****************************************************************************
**
**				ÖÐRENCÝ ADI...........................:Kübra Yýlmaz
**				ÖÐRENCÝ NUMARASI.............:B181210023
**				DERS GRUBU…………………:1/C
****************************************************************************/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter kullanmak için setlocale fonksiyonunu kullandým

	int satirSayisi;
	int sutunSayisi;

	do
		//döngünün bir kereliðine koþul aramadan gerçekleþmesi için 'do while' fonksiyonunu kullandým 
	{
		cout << "Sütun sayýsý, satýr sayýsýnýn 2 katý olacak þekilde deðer girin." << endl << endl << endl;


		cout << "Þeklimiz kaç satýrdan oluþsun?" << endl;
		cin >> satirSayisi;

		while (satirSayisi < 5 || satirSayisi>15)
			//satýr sayýsý verilen koþullara uyana kadar dýþardan bilgi istenmesini saðladým
		{
			cout << "Lütfen 5 le 15 arasýnda bir sayý giriniz. (5 ile 15 dahildir.)" << endl;
			cin >> satirSayisi;
		}

		cout << "Þeklimiz kaç sütundan oluþsun?" << endl;
		cin >> sutunSayisi;

		while (sutunSayisi < 5 || sutunSayisi>40)
			////sütun sayýsý verilen koþullara uyana kadar dýþardan bilgi istenmesini saðladým
		{
			cout << "Lütfen 5 le 40 arasýnda bir sayý giriniz. (5 ile 40 dahildir.)" << endl;
			cin >> sutunSayisi;
		}

	} while (sutunSayisi != 2 * satirSayisi);
	//sütun sayýsý, satýr sayýsýnýn 2 katý olana kadar yukarýdaki kod blogu çalýþacak, koþul saðlandýðýnda þekil ekrana çizilecek
	{
		cout << endl << endl << "Satýr sayýsý = " << satirSayisi << endl << "Sütun sayýsý = " << sutunSayisi << endl << endl << endl;

		for (int i = 0; i <= sutunSayisi - 1; i++)
			//sütun sayýsý kadar yanyana * bastýrýlýyor
		{
			cout << "*";
		}
		cout << endl;
		Sleep(150);

		for (int i = 1; i < satirSayisi - 1; i++)
			//satýr sayýsý kadar döngü gerçekleþiyor
		{
			cout << "*";

			for (int a = (satirSayisi - 3) - i; a >= 0; a--)
				//þekille orantýlý, giderek azalan boþluklar yazdýrdým
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
			Sleep(150); //adýmlarýn yavaþ yavaþ gerçekleþmesi için sleep() fonksiyonunu kullandým
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
			////satýr sayýsý kadar döngü gerçekleþiyor
		{
			cout << "*";

			for (int a = 2; a <= i; a++)
				////þekille orantýlý, giderek artan boþluklar yazdýrdým
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