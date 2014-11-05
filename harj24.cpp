/*		Valtteri Louhelainen

Muuta harjoitusta 22 niin, etta valikko nayttaa seuraavalta:

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta henkilo
3 Nayta kaikki henkilot
4 Poista henkilon tiedot
5 Tallenna tiedot tiedostoon
6 Hae tiedot tiedostosta


ja toteuta valikossa näkyvät toiminnot.

Valitse haluamasi tallennusformaatti.*/

#include <iostream>
#include <fstream>
using namespace std;

struct DATA
{
	char nimi[15];
	float matka;
	int hattu;
};
DATA rekisteri[10];
DATA luetturek[10];
bool jatka = true;
int valinta;
int valinta2;
int i = 0;
int *pointer = &i;
int it;
ifstream luku;
ofstream kirj;

int Valikko(void)
{
	int temp;
	cout << "VALIKKO\n"
		<< "0 Lopeta\n"
		<< "1 Lis\x84\x84 henkil\x94\n"
		<< "2 N\x84yt\x84 yksi henkil\x94\n"
		<< "3 N\x84yt\x84 kaikki henkil\x94t\n"
		<< "4 Poista henkil\x94n tiedot\n"
		<< "5 Tallenna tiedot tiedostoon\n"
		<< "6 Hae tiedot tiedostosta\n";
	cin >> temp;
	return temp;
}

void LisaaHenkilo(DATA rek[], int *lkm)
{
	if (*lkm == 10)
		cout << "\nRekisteri t\x84ynn\x84\n\n";
	else
	{
		cout << "\nEtunimi: ";
		cin >> rek[*lkm].nimi;
		cout << "Koulumatka: ";
		cin >> rek[*lkm].matka;
		cout << "Hatun koko: ";
		cin >> rek[*lkm].hattu;
		i++;
		cout << "\n";
	}
}

void TulostaHenkilo(DATA rek[], int num)
{
	printf_s("|%-15s|%5.1f|%10i|\n", rek[num].nimi, rek[num].matka, rek[num].hattu);
}

void TulostaYksiHenkilo(DATA rek[])
{
	cout << "Anna henkil\x94n numero: ";
	cin >> valinta2;
	printf_s("\n/===============|=====|==========\\\n|    Etunimi    |Matka|Hatun koko|\n|---------------|-----|----------|\n");
	TulostaHenkilo(rek, valinta2 - 1);
	printf_s("\\===============|=====|==========/\n\n");
}

void TulostaKaikkiHenkilot(DATA rek[], int lkm)
{
	printf_s("\n/===============|=====|==========\\\n|    Etunimi    |Matka|Hatun koko|\n|---------------|-----|----------|\n");
	for (int n = 0; n < lkm; n++)
		TulostaHenkilo(rek, n);
	printf_s("\\===============|=====|==========/\n\n");
}

void PoistaTiedot(DATA rek[])
{
	cout << "Anna henkil\x94n numero: ";
	cin >> valinta2;
	rekisteri[valinta2 - 1] = { "", 0, 0 };

}

void TallennaTiedot()
{
	kirj.open("rekisteri.txt", ios_base::binary);
	if (kirj.is_open())
	{
		kirj.write((char *)rekisteri, sizeof rekisteri);
		kirj.write((char *)&i, sizeof(int));
		kirj.close();
	}
	else
		cout << "Tiedoston avaaminen ep\x84onnistui\n";
}

void LueTiedot()
{
	luku.open("rekisteri.txt", ios_base::binary);
	if (luku.is_open())
	{
		luku.read((char *)luetturek, sizeof luetturek);
		luku.read((char *)&it, sizeof(int));
		TulostaKaikkiHenkilot(luetturek, it);
		luku.close();
	}
	else
		cout << "Tiedoston avaaminen ep\x84onnistui\n";
}

void main()
{
	while (jatka)
	{
		valinta = Valikko();
		if (valinta == 0)
			jatka = false;
		if (valinta == 1)
			LisaaHenkilo(rekisteri, pointer);
		if (valinta == 2)
			TulostaYksiHenkilo(rekisteri);
		if (valinta == 3)
			TulostaKaikkiHenkilot(rekisteri, i);
		if (valinta == 4)
			PoistaTiedot(rekisteri);
		if (valinta == 5)
			TallennaTiedot();
		if (valinta == 6)
			LueTiedot();
	}
}
