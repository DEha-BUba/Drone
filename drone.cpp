#include <iostream>
#include <cstdlib>
using namespace std;

class Drone {
public:
    int hiz;
    int Maxhiz;
    int x, y, z;       
    int kalanPil;
    float yuk;
    float maxYuk;
    bool ucusIzni;

    Drone() {
        hiz = 0;
        Maxhiz = 10;
        x = 0;
        y = 20;
        z = 0;       
        kalanPil = 100;
        maxYuk = 500;
        yuk = 0;
        ucusIzni = false;
    }

    void hiz_arttir() {
        if (hiz < Maxhiz) {
            hiz++;
            cout << "Hiz 1 artirildi. Yeni hiz: " << hiz << " m/s\n";
        } else {
            cout << "Maksimum hiz asildi!\n";
        }
    }

    void hiz_azalt() {
        if (hiz > 0) {
            hiz--;
            cout << "Hiz 1 azaltildi. Yeni hiz: " << hiz << " m/s\n";
        } else {
            cout << "Drone zaten duruyor.\n";
        }
    }

    void hareket(char yon) {
        if (hiz == 0) {
            cout << "Hareket etmek icin hiz 0'dan buyuk olmalidir!\n";
            return;
        }

        switch (yon) {
            case 'i':
                x += hiz;
                break;
            case 'g': 
                x -= hiz;
                break;
            case 's': 
                y += hiz;
                break;
            case 'l':
                y -= hiz;
                break;
            case 'u': 
                z += hiz;
                break;
            case 'a':
                z -= hiz;
                if (z < 0) z = 0;
                break;
            default:
                cout << "Gecersiz yon secimi!\n";
                return;
        }

        kalanPil -= hiz;
        if (kalanPil < 0) kalanPil = 0;

        cout << "Drone konumu: X=" << x << ", Y=" << y << ", Z=" << z << endl;
        cout << "Kalan pil: " << kalanPil << "%\n";
    }

    bool yuk_kontrol() { 
        return yuk <= maxYuk; 
    }

    bool ucus_izni_kontrol() {
        if (!ucusIzni) {
            cout << "Ucus izni yok! Ucamaz.\n";
            return false;
        }
        if (!yuk_kontrol()) {
            cout << "Asiri yuk! Ucamaz.\n";
            return false;
        }
        if (kalanPil < 30) {
            cout << "Pil cok dusuk! Ucamaz.\n";
            return false;
        }
        if (y > 200) {
            cout << "Radar disi! Ucamaz.\n";
            return false;
        }
        if (y < 20) {
            cout << "Yukseklik cok dusuk! Ucamaz.\n";
            return false;
        }
        if (x < -100 || x > 100 || z < -100 || z > 100) {
            cout << "Radar disi! Ucamaz.\n";
            return false;
        }
        return true;
    }

    void durum_goster() {
        cout << "\n---- DRONE DURUM ----\n";
        cout << "Hiz: " << hiz << " m/s\n";
        cout << "Maksimum Hiz: " << Maxhiz << " m/s\n";
        cout << "Yuk: " << yuk << " gram\n";
        cout << "Ucus izni: " << ucusIzni << "\n";
        cout << "Kalan pil: " << kalanPil << "%\n";
        cout << "Konum: X=" << x << ", Y=" << y << ", Z=" << z << endl;
        cout << "Alan sinirlari: X[-100,100], Y[20,200], Z[-100,100]\n";
        cout << "----------------------\n";
    }

    void ekran_temizle() {
        system("cls");
    }

    void erken_kontrol() {
        if (!ucus_izni_kontrol()) {
            system("pause");
            exit(0);
        }
    }
};

int main() {
    Drone D;
    int secim;

    cout << "Max Yuk: " << D.maxYuk << " gram\n";
    cout << "Dronun Tasidigi Yuk (gram): ";
    cin >> D.yuk;
    D.erken_kontrol();

    do {
        cout << "Ucus Izni (1=Evet, 0=Hayir): ";
        cin >> D.ucusIzni;
        if (D.ucusIzni != 0 && D.ucusIzni != 1) {
            cout << "Lutfen 1 veya 0 giriniz.\n";
        }
    } while (D.ucusIzni != 0 && D.ucusIzni != 1);
    D.erken_kontrol(); 

    do {
        cout << "Pil Yuzdesi (0-100): ";
        cin >> D.kalanPil;
        if (D.kalanPil < 0 || D.kalanPil > 100) {
            cout << "Lutfen 0 ile 100 arasinda bir deger giriniz.\n";
        }
    } while (D.kalanPil < 0 || D.kalanPil > 100);
    D.erken_kontrol();  

    while (D.ucus_izni_kontrol()) {
        cout << "\nNe yapmak istersiniz?\n";
        cout << "1- Hareket Et (x, y, z yonleri)\n";
        cout << "2- Hiz Arttir\n";
        cout << "3- Hiz Azalt\n";
        cout << "4- Durum Goster\n";
        cout << "5- Cikis\n";
        cout << "6- Ekrani Temizle\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
            case 1: {
                char yon;
                cout << "Yon seciniz (i=ileri, g=geri, s=sag, l=sol, u=yukari, a=asagi): ";
                cin >> yon;
                D.hareket(yon);
                break;
            }
            case 2: D.hiz_arttir(); break;
            case 3: D.hiz_azalt(); break;
            case 4: D.durum_goster(); break;
            case 5: return 0;
            case 6: D.ekran_temizle(); break;
            default: cout << "Gecersiz secim!\n"; break;
        }
    }

    cout << "\nDrone artik guvensiz! Program sonlandi.\n";
    system("pause");
    return 0;
}
