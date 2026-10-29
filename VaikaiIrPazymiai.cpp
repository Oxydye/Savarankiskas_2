#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

setprecision(2);

int main() {
    const int varduMax = 100;
    const int pazymiuMax = 10;

    string VisiVardai[varduMax];
    int Pazymiai[varduMax][pazymiuMax];
    int PazymiuKiekis[varduMax];
    int DabartinisVarduKiekis = 0;

    int pasirinkimas;
    cout << fixed << setprecision(2);

    do {
        cout << "Sveiki, pasirinkite funkcija:" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> pasirinkimas;

        //         1         //
        if (pasirinkimas == 1) {
            if (DabartinisVarduKiekis >= varduMax) {
            cout << "Pasiektas mokiniu limitas (100)." << endl;
            continue;
            }
 
        cout << "Iveskite mokinio varda: ";
        cin >> VisiVardai[DabartinisVarduKiekis];

        int kiek;