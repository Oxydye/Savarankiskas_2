#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
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
            do {
                cout << "Kiek pazymiu norite ivesti siam mokiniui? (Nuo 0 iki 10)" << endl;
                cin >> kiek;
                if (kiek < 0 || kiek > pazymiuMax) {
                    cout << "Galima ivesti nuo 0 iki 10 pazymiu" << endl;
                }
            } while (kiek < 0 || kiek > pazymiuMax);
 
            for (int i = 0; i < kiek; i++) {
                int pazymys;
                do {
                    cout << "Iveskite " << i + 1 << " pazymi (1-10): ";
                    cin >> pazymys;
                    if (pazymys < 1 || pazymys > 10) {
                        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta." << endl;
                    }
                } while (pazymys < 1 || pazymys > 10);
                Pazymiai[DabartinisVarduKiekis][i] = pazymys;
            }
 
            PazymiuKiekis[DabartinisVarduKiekis] = kiek;
            DabartinisVarduKiekis++;
            cout << "Mokinys pridetas." << endl;
        }
 
        //  2 //
        if (pasirinkimas == 2) {
            if (DabartinisVarduKiekis == 0) {
                cout << "Mokiniu sarasas yra tuscias." << endl;
            }
            for (int i = 0; i < DabartinisVarduKiekis; i++) {
                cout << i + 1 << ". " << VisiVardai[i] << ": ";
                if (PazymiuKiekis[i] == 0) {
                    cout << "Pazymiu sarase nera";
                }
                for (int j = 0; j < PazymiuKiekis[i]; j++) {
                    cout << Pazymiai[i][j] << " ";
                }
                cout << endl;
            }
        }
 
        //  Kiti menu pasirinkimai: 3, 4, 5, 6 //
        if (pasirinkimas >= 3 && pasirinkimas <= 6) {
            if (DabartinisVarduKiekis == 0) {
                cout << "Mokiniu sarasas yra tuscias." << endl;
                continue;
            }
 
            int nr;
            do {
                cout << "Iveskite mokinio numeri (1-" << DabartinisVarduKiekis << "): ";
                cin >> nr;
                if (nr < 1 || nr > DabartinisVarduKiekis) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << DabartinisVarduKiekis << "." << endl;
                }
            } while (nr < 1 || nr > DabartinisVarduKiekis);
            int mokinys = nr - 1;
 
            // 3 (Konkretaus mokinio pazymiai)//
            if (pasirinkimas == 3) {
                cout << VisiVardai[mokinys] << ": ";
                if (PazymiuKiekis[mokinys] == 0) {
                    cout << "Pazymiu sarase nera";
                }
                for (int j = 0; j < PazymiuKiekis[mokinys]; j++) {
                    cout << Pazymiai[mokinys][j] << " ";
                }
                cout << endl;
            }
 
            // 4 Pazymio atnaujinimas//
            if (pasirinkimas == 4) {
                if (PazymiuKiekis[mokinys] == 0) {
                    cout << "Sis mokinys pazymiu neturi." << endl;
                } else {
                    int pnr;
                    do {
                        cout << "Iveskite pazymio numeri (1-" << PazymiuKiekis[mokinys] << "): ";
                        cin >> pnr;
                        if (pnr < 1 || pnr > PazymiuKiekis[mokinys]) {
                            cout << "Neteisingas pazymio numeris. Iveskite skaiciu nuo 1 iki " << PazymiuKiekis[mokinys] << "." << endl;
                        }
                    } while (pnr < 1 || pnr > PazymiuKiekis[mokinys]);
 
                    int pazymys;
                    do {
                        cout << "Iveskite nauja pazymi (1-10): ";
                        cin >> pazymys;
                        if (pazymys < 1 || pazymys > 10) {
                            cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta." << endl;
                        }
                    } while (pazymys < 1 || pazymys > 10);
                    Pazymiai[mokinys][pnr - 1] = pazymys;
                    cout << "Pazymys atnaujintas." << endl;
                }
            }
 
            // 5 Vidurkis//
            if (pasirinkimas == 5) {
                if (PazymiuKiekis[mokinys] == 0) {
                    cout << "Sis mokinys pazymiu neturi, vidurkio apskaiciuoti negalima." << endl;
                } else {
                    double suma = 0;
                    for (int j = 0; j < PazymiuKiekis[mokinys]; j++) {
                        suma = suma + Pazymiai[mokinys][j];
                    }
                    double vidurkis = suma / PazymiuKiekis[mokinys];
                    cout << VisiVardai[mokinys] << " vidurkis: " << vidurkis << endl;
                }
            }
 
            // 6 Pasalinti mokini//
            if (pasirinkimas == 6) {
                //  Mokiniu stumimas i prieki
                for (int i = mokinys; i < DabartinisVarduKiekis - 1; i++) {
                    VisiVardai[i] = VisiVardai[i + 1];
                    PazymiuKiekis[i] = PazymiuKiekis[i + 1];
                    for (int j = 0; j < pazymiuMax; j++) {
                        Pazymiai[i][j] = Pazymiai[i + 1][j];
                    }
                }
                DabartinisVarduKiekis--;
                cout << "Mokinys pasalintas." << endl;
            }
        }
 
        // Darbo pabaiga//
        if (pasirinkimas == 7) {
            cout << "Geros dienos." << endl;
        }
 
        if (pasirinkimas < 1 || pasirinkimas > 7) {
            cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 7." << endl;
        }
 
    } while (pasirinkimas != 7);
 
    return 0;
}

