/****************************************************************************
**
**				��RENC� ADI..................:K�bra Y�lmaz
**				��RENC� NUMARASI.............:b181210023
**				DERS GRUBU...................:1/C
****************************************************************************/





#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;



int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(0));
	int secim;
	int boyut;
	int i;
	int j;
	int satir;
	int sutun;
	int temp;
	int yedek[25][25];
	int matris[25][25];
	int toplam = 0;

	cout << "Matrisimizin boyutu ka� olsun?" << endl << "boyut  : ";
	cin >> boyut;

	//matris boyutunu kontrol ediyor
	while (boyut > 25 || boyut < 5)
	{
		cout << endl << endl << "L�tfen 5 ve 25 aras�nda bir de�er girin. 5 ve 25 dahildir." << endl << "boyut  : " << endl;
		cin >> boyut;
	}
	cout << endl << endl << endl;

	//matrisi ekran ��kar�yor
	cout << "    ";
	for (int j = 0; j < boyut; j++)
	{
		cout << setw(5) << j + 1;
	}
	cout << endl << "      ";
	for (int j = 0; j < boyut * 5; j++)
	{
		cout << "_";
	}
	cout << endl << endl;
	cout << " 1 |";
	for (i = 0; i < boyut; i++)
	{
		int str = 0;
		for (j = 0; j < boyut; j++)
		{
			matris[i][j] = rand() % 10;
			cout << setw(5) << matris[i][j]; //matrise rastgele de�er at�yor
		}
		if (i == boyut - 1)
			break;
		cout << endl << endl << setw(2) << str + 2 + i << " |";
		str++;

	}


	cout << endl << endl;

	while (true)
	{
		do
		{   //kullan�c�ya se�im sunuluyor
			cout << endl << endl << "1. S�tun Sat�r De�i�tir : " << endl << "2. Tekleri ba�a al : " << endl << "3.Ters �evir (S�tun) : " << endl
				<< "4.Toplamlar� Yazd�r : " << endl << endl << "se�iminiz  : " << endl << endl;
			cin >> secim;

			if (secim == 1)
			{
				int kesisen;
				cout << "sat�r say�s� girin : ";
				cin >> satir;
				cout << endl << endl << "s�tun say�s� girin : ";
				cin >> sutun;
				while (satir > boyut || sutun > boyut)
				{
					if (satir > boyut)
						cout << endl << endl << "Se�ti�iniz sat�r say�s� matrisin sat�r say�s�ndan b�y�k olmamal�, tekrar se�in" << endl;
					else
						cout << endl << "Se�ti�iniz s�tun say�s� matrisin s�tun say�s�ndan b�y�k olmamal�" << endl;

					cout << "sat�r say�s� girin : " << endl;
					cin >> satir;
					cout << "s�tun say�s� girin : " << endl;
					cin >> sutun;

				}
				kesisen = matris[satir - 1][satir - 1] + matris[sutun - 1][sutun - 1];
				//kesi�en sat�r ve s�tundaki de�erlerin toplanmas� sa�lan�yor

				sutun--;
				satir--;
				cout << "    ";
				for (int j = 0; j < boyut; j++)
				{
					cout << setw(5) << j + 1;
				}
				cout << endl << "      ";
				for (int j = 0; j < boyut * 5; j++)
				{
					cout << "_";
				}
				cout << endl << endl;
				cout << " 1 |";
				for (i = 0; i < boyut; i++)
				{
					//sat�r ve s�tun de�i�iyor
					int str = 0;
					for (j = 0; j < boyut; j++)
					{
						if (i == satir)
						{
							yedek[i][j] = matris[j][sutun];
						}
						else if (j == sutun)
						{
							yedek[i][j] = matris[satir][i];

						}
						else
							yedek[i][j] = matris[i][j];

						kesisen = matris[satir][satir] + matris[sutun][sutun];
						yedek[satir][sutun] = kesisen;

						cout << setw(5) << yedek[i][j];
					}

					if (i == boyut - 1)
						break;
					cout << endl << endl << setw(2) << str + 2 + i << " |";
					str++;

				}
			}

			if (secim == 3)
			{
				//s�tun de�eri kontrol ediliyor
				do
				{
					cout << "S�tun: ";
					cin >> sutun;
					if (sutun<1 || sutun>boyut)
					{
						cout << "Hatal� de�er girdiniz yeniden girin!" << endl;
					}
				} while (sutun<1 || sutun>boyut);

				sutun--;
				//matrisin tersi yedek matrise atan�yor
				for (i = 0; i < boyut; i++)
				{
					yedek[i][sutun] = matris[(boyut - 1) - i][sutun];
				}
				//matrise yedek matris de�erleri atan�yor
				for (i = 0; i < boyut; i++)
				{
					matris[i][sutun] = yedek[i][sutun];
				}

				//matris yazd�r�l�yor
				cout << "    ";
				for (int j = 0; j < boyut; j++)
				{
					cout << setw(5) << j + 1;
				}
				cout << endl << "      ";
				for (int j = 0; j < boyut * 5; j++)
				{
					cout << "_";
				}
				cout << endl << endl;
				cout << " 1 |";
				for (i = 0; i < boyut; i++)
				{
					int str = 0;
					for (j = 0; j < boyut; j++)
					{
						cout << setw(5) << matris[i][j];
					}
					if (i == boyut - 1)
						break;
					cout << endl << endl << setw(2) << str + 2 + i << " |";
					str++;


				}
			}

			if (secim == 4)
			{
				//matriste t�m de�erler toplan�yor
				for (i = 0; i < boyut; i++)
				{
					for (j = 0; j < boyut; j++)
					{
						toplam += matris[i][j];
					}
				}
				yedek[0][0] = toplam;
				//her de�er ��kar�larak matrise yazd�r�l�yor
				for (i = 0; i < boyut; i++)
				{
					for (j = 0; j < boyut; j++)
					{

						yedek[i][j] = toplam - matris[i][j];
						toplam -= matris[i][j];
					}
				}

				//matris yazd�r�l�yor
				cout << "    ";
				for (int j = 0; j < boyut; j++)
				{
					cout << setw(5) << j + 1;
				}
				cout << endl << "      ";
				for (int j = 0; j < boyut * 5; j++)
				{
					cout << "_";
				}
				cout << endl << endl;
				cout << " 1 |";
				for (i = 0; i < boyut; i++)
				{
					int str = 0;
					for (j = 0; j < boyut; j++)
					{
						cout << setw(5) << yedek[i][j];
					}
					if (i == boyut - 1)
						break;
					cout << endl << endl << setw(2) << str + 2 + i << " |";
					str++;

				}
			}
		} while (secim != 2);
		{
			cout << "sat�r say�s� girin : ";
			cin >> satir;
			//girilen sat�r say�s� boyuttan b�y�k ��karsa hata veriyor
			while (satir > boyut)
			{
				cout << endl << endl << " Girilen say� matrisin boyutundan b�y�k olamaz" << endl;

				//matris ekrana yazd�r�l�yor
				cout << "    ";
				for (int j = 0; j < boyut; j++)
				{
					cout << setw(5) << j + 1;
				}
				cout << endl << "      ";
				for (int j = 0; j < boyut * 5; j++)
				{
					cout << "_";
				}
				cout << endl << endl;
				cout << " 1 |";
				for (i = 0; i < boyut; i++)
				{
					int str = 0;
					for (j = 0; j < boyut; j++)
					{
						cout << setw(5) << matris[i][j];
					}
					if (i == boyut - 1)
						break;
					cout << endl << endl << setw(2) << str + 2 + i << " |";
					str++;
				}
				//buradaki while d�ng�s�n� k�r�p men�n�n tekrar ortaya ��kmas� i�in d�ng� ba��na gidiyor. (while=true)
				break;
			}
			if (satir <= boyut)
			{
				for (int i = 0; i < boyut; i++)
				{
					int gecici;
					//tek elemanlar� buluyor
					if (matris[satir - 1][i] % 2 == 0)
					{
						for (int j = i; j < boyut; j++)
						{
							//e�er tek bulursa �ifti ge�iciye teki �ifte tekin yerinede �ifti al�yor.
							if (matris[satir - 1][j] % 2 != 0)
							{
								gecici = matris[satir - 1][i];
								matris[satir - 1][i] = matris[satir - 1][j];
								matris[satir - 1][j] = gecici;


							}
						}

						//matris ekrana yazd�r�l�yor
						cout << endl << endl;
						cout << "    ";
						for (int j = 0; j < boyut; j++)
						{
							cout << setw(5) << j + 1;
						}
						cout << endl << "   ";
						for (int j = 0; j < boyut * 5; j++)
						{
							cout << "_";
						}
						cout << endl << endl;
						cout << " 1 |";
						for (i = 0; i < boyut; i++)
						{
							int str = 0;
							for (j = 0; j < boyut; j++)
							{
								cout << setw(5) << matris[i][j];
							}
							if (i == boyut - 1)
								break;
							cout << endl << endl << setw(2) << str + 2 + i << " |";
							str++;
						}
					}

				}

				
			}

		}
	}

	

	
	
	system("pause");
	return 0;
}