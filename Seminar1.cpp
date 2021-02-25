#include <iostream>
#include <exception>
using namespace std;

class ExceptieAssignment2 :public std::exception
{

};
int numarElementeMaiMari(int* valori, int nrValori, int valoarePrag)
{
	int nrMaiMari = 0;
	for (int i = 0; i < nrValori; i++)
		if (valori[i] >= valoarePrag)nrMaiMari++;       // 1.  lipsa acoladelor in cadrul for-ului ceea ce ingreuneaza citirea codului
	return nrMaiMari;
}
int* filtrareElementeMaiMari(int* valori, int nrValori, int valoarePrag)
{
	int *elementeMaiMari;
	elementeMaiMari = new int[numarElementeMaiMari(valori, nrValori, valoarePrag)];
	int k = 0;
	for (int i = 0; i < nrValori; i++)
		if (valori[i] >= valoarePrag)elementeMaiMari[k++] = valori[i];
	if (numarElementeMaiMari(valori, nrValori, valoarePrag) == 0)elementeMaiMari = NULL;
	return elementeMaiMari;
}
void filtrareElementeMaiMari2(int* valori, int nrValori, int valoarePrag, int** valoriMaiMari)        // 2. nume nesugestibil de functie care se poate confunda cu precedenta
{
	*valoriMaiMari = filtrareElementeMaiMari(valori, nrValori, valoarePrag);
	if (numarElementeMaiMari(valori, nrValori, valoarePrag) == 0)*valoriMaiMari = NULL;
}
int getElement(int* valori, int nrValori, int index)
{
	if (index >= 0 && index < nrValori)return valori[index];
	else throw new ExceptieAssignment2();
}
int* slice(int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector)       // 3. functie cu prea multi parametri
{
	int *subVector, i = 0;
	if (indexFinal < 0)throw new ExceptieAssignment2();
	dimensiuneSubvector = indexFinal - indexStart + 1;
	subVector = new int[dimensiuneSubvector];
	if (indexStart < 0 || indexStart > indexFinal || indexFinal >= nrValori)throw new ExceptieAssignment2();
	else if (indexFinal == indexStart)*subVector = getElement(valori, nrValori, indexStart);        // 4. fragilitatea codului, instructiune in cadrul unei functii ce depinde de o alta functie
	else
	{
		for (int j = indexStart; j <= indexFinal; j++)
			subVector[i++] = valori[j];
	}
	return subVector;
}
void afisareVector(int v[100], int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
}

int main()                //    5.         main-ul este foarte incarcat, putem crea o functie sau mai multe pentru a scurta din cod si a nu mai avea linii aprox repetitive de cod care face acelasi lucru                      
{



	int nrValori, valoarePrag, i, nrElem, index, indexStart, indexFinal, dimSlice;
	int *valori;
	int *valoriMaiMari;
	cout << "Numarul elementelor din vector este: ";
	cin >> nrValori;
	cout << "Valoarea prag este: ";
	cin >> valoarePrag;
	valori = new int[nrValori];
	for (i = 0; i < nrValori; i++)
	{
		cout << "valori[" << i << "]=";
		cin >> valori[i];
	}
	cout << "Numarul de elemente din vector mai mari sau egale cu valoarea data este: ";
	cout << numarElementeMaiMari(valori, nrValori, valoarePrag);
	cout << endl << endl;
	int* vectorNou;
	int* vectorNou1;
	nrElem = numarElementeMaiMari(valori, nrValori, valoarePrag);
	vectorNou = filtrareElementeMaiMari(valori, nrValori, valoarePrag);
	cout << "Elementele din vector mai mari sau egale cu valoarea data sunt: ";
	afisareVector(vectorNou, nrElem);
	cout << endl << endl;
	cout << "Vectorul cu elementele mai mari sau egale cu valoarea prag este: ";
	filtrareElementeMaiMari2(valori, nrValori, valoarePrag, &valoriMaiMari);
	for (i = 0; i < nrElem; i++)
		cout << valoriMaiMari[i] << " ";
	cout << endl << endl;
	cout << "Indexul este: ";
	cin >> index;
	cout << "Elementul din vector de pe pozitia index este: ";
	cout << getElement(valori, nrValori, index);
	cout << endl << endl;
	cout << "Indexul de start este: ";
	cin >> indexStart;
	cout << "Indexul final este: ";
	cin >> indexFinal;
	vectorNou1 = slice(valori, nrValori, indexStart, indexFinal, dimSlice);
	cout << "Subvectorul cuprins de la indexul de start pana la cel final este: ";
	afisareVector(vectorNou1, dimSlice);
	cout << endl << endl;
	return 0;
}