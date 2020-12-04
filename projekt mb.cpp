#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void remove(std::vector<int> &v) //Funkcja odpowiedzialna za usuwanie duplikatów z wektora zawieraj¹cego powtarzaj¹ce siê elementy
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}

int main()
{
    int n;
    cout << "Wprowadz liczbe calkowita (n) okreslajaca rozmiar tablicy: "; // Zapytanie o rozmiar tablicy czyli iloœæ wczytywanych liczb
    cin >> n;
    if(n>=2) // sprawdzenie czy podana d³ugoœæ tablicy jest wiêksza od jeden, w przeciwnym razie przerwij
    {
    char nazwaPliku[30];
	cout<< "Podaj nazwe pliku do odczytu: ";
	cin>>nazwaPliku; // Utworzenie zmiennej, zapytanie i wczytanie do niej nazwy pliku do odczytu
	int tablica[n]; // Utworzenie tablicy do liczb wczytanych z pliku
	ifstream plikOdczyt(nazwaPliku); // Otwarcie pliku do odczytu
	int cnt=0, x;
	cout<< "Wczytane liczby: ";
	while(cnt < n && plikOdczyt >> x){ // Wczytanie liczb z pliku i wypisanie ich do konsoli
		if(x<n){
			tablica[cnt++] = x;
			cout<< x << " ";
		}
	}
	plikOdczyt.close(); // Zamkniêcie pliku do odczytu
    cout << "\n\nPowtarzajace sie elementy to: ";
    vector<int> v;
    for(int i = 0; i <= n; i++) // Stworzenie wektora i przypisanie powtarzaj¹cych siê liczb
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(tablica[i] == tablica [j])
            {
                v.push_back(tablica[i]);
            }
        }
    }
    remove(v); // Wywo³anie funkcji eliminuj¹cej duplikaty z wektora
    for (auto it = v.cbegin(); it != v.cend(); ++it) //Wypisanie liczb z wektora
        cout << *it << ' ';
    char nazwaPlikuZapis[30];
    cout<< "\nPodaj nazwe pliku do zapisu: ";
    cin>>nazwaPlikuZapis; // utworzenie zmiennej, zapytanie i zapis nazwy pliku do zapisu
    ofstream plikZapis(nazwaPlikuZapis); // Otwarcie pliku do zapisu
    plikZapis << "Wczytane liczby: ";
    for(int i=0; i<n; i++){ // Wypisanie do pliku wczytanych wczeœniej liczb
    	plikZapis << tablica[i] << " ";
	}
	plikZapis << "\nPowtarzajace sie elementy to: ";
	for(vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) { // wypisanie do pliku powtarzaj¹cych siê liczb
    plikZapis << *i << ' ';
	}
	plikZapis.close();
	cout<<"\nWynik zapisano do pliku"; // Powiadomienie o zapisie do pliku
    }
    else
    {
    cout <<"\nWprowadzona liczba musi byc wieksza badz rowna 2"<<endl;
    return main();
    }
return 0;
}
