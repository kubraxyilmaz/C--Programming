/****************************************************************************
**
**				ÖÐRENCÝ ADI..................:Kübra Yýlmaz
**				ÖÐRENCÝ NUMARASI.............:b181210023
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

	cout << "Matrisimizin boyutu kaç olsun?" << endl << "boyut  : ";
	cin >> boyut;

	//matris boyutunu kontrol ediyor
	while (boyut > 25 || boyut < 5)
	{
		cout << endl << endl << "Lütfen 5 ve 25 arasýnda bir deðer girin. 5 ve 25 dahildir." << endl << "boyut  : " << endl;
		cin >> boyut;
	}
	cout << endl << endl << endl;

	//matrisi ekran çýkarýyor
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
			cout << setw(5) << matris[i][j]; //matrise rastgele deðer atýyor
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
		{   //kullanýcýya seçim sunuluyor
			cout << endl << endl << "1. Sütun Satýr Deðiþtir : " << endl << "2. Tekleri baþa al : " << endl << "3.Ters Çevir (Sütun) : " << endl
				<< "4.Toplamlarý Yazdýr : " << endl << endl << "seçiminiz  : " << endl << endl;
			cin >> secim;

			if (secim == 1)
			{
				int kesisen;
				cout << "satýr sayýsý girin : ";
				cin >> satir;
				cout << endl << endl << "sütun sayýsý girin : ";
				cin >> sutun;
				while (satir > boyut || sutun > boyut)
				{
					if (satir > boyut)
						cout << endl << endl << "Seçtiðiniz satýr sayýsý matrisin satýr sayýsýndan büyük olmamalý, tekrar seçin" << endl;
					else
						cout << endl << "Seçtiðiniz sütun sayýsý matrisin sütun sayýsýndan büyük olmamalý" << endl;

					cout << "satýr sayýsý girin : " << endl;
					cin >> satir;
					cout << "sütun sayýsý girin : " << endl;
					cin >> sutun;

				}
				kesisen = matris[satir - 1][satir - 1] + matris[sutun - 1][sutun - 1];
				//kesiþen satýr ve sütundaki deðerlerin toplanmasý saðlanýyor

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
					//satýr ve sütun deðiþiyor
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
				//sütun deðeri kontrol ediliyor
				do
				{
					cout << "Sütun: ";
					cin >> sutun;
					if (sutun<1 || sutun>boyut)
					{
						cout << "Hatalý deðer girdiniz yeniden girin!" << endl;
					}
				} while (sutun<1 || sutun>boyut);

				sutun--;
				//matrisin tersi yedek matrise atanýyor
				for (i = 0; i < boyut; i++)
				{
					yedek[i][sutun] = matris[(boyut - 1) - i][sutun];
				}
				//matrise yedek matris deðerleri atanýyor
				for (i = 0; i < boyut; i++)
				{
					matris[i][sutun] = yedek[i][sutun];
				}

				//matris yazdýrýlýyor
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
				//matriste tüm deðerler toplanýyor
				for (i = 0; i < boyut; i++)
				{
					for (j = 0; j < boyut; j++)
					{
						toplam += matris[i][j];
					}
				}
				yedek[0][0] = toplam;
				//her deðer çýkarýlarak matrise yazdýrýlýyor
				for (i = 0; i < boyut; i++)
				{
					for (j = 0; j < boyut; j++)
					{

						yedek[i][j] = toplam - matris[i][j];
						toplam -= matris[i][j];
					}
				}

				//matris yazdýrýlýyor
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
			cout << "satýr sayýsý girin : ";
			cin >> satir;
			//girilen satýr sayýsý boyuttan büyük çýkarsa hata veriyor
			while (satir > boyut)
			{
				cout << endl << endl << " Girilen sayý matrisin boyutundan büyük olamaz" << endl;

				//matris ekrana yazdýrýlýyor
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
				//buradaki while döngüsünü kýrýp menünün tekrar ortaya çýkmasý için döngü baþýna gidiyor. (while=true)
				break;
			}
			if (satir <= boyut)
			{
				for (int i = 0; i < boyut; i++)
				{
					int gecici;
					//tek elemanlarý buluyor
					if (matris[satir - 1][i] % 2 == 0)
					{
						for (int j = i; j < boyut; j++)
						{
							//eðer tek bulursa çifti geçiciye teki çifte tekin yerinede çifti alýyor.
							if (matris[satir - 1][j] % 2 != 0)
							{
								gecici = matris[satir - 1][i];
								matris[satir - 1][i] = matris[satir - 1][j];
								matris[satir - 1][j] = gecici;


							}
						}

						//matris ekrana yazdýrýlýyor
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