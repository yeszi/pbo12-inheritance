#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Karakter {
protected:
    string nama, tipe;
    int maxDmg, health;
public:
    Karakter(string n, string t, int md, int h) : nama(n), tipe(t), maxDmg(md), health(h) {}
    virtual void tampil() { cout << nama << " | " << tipe << " | Damage:" << maxDmg << " | HP:" << health; }
    virtual int serang() { int d = rand() % maxDmg + 1; cout << d << " damage"; return d; }
    string getNama() { return nama; }
    string getTipe() { return tipe; }
    int getMaxDmg() { return maxDmg; }
    int getHealth() { return health; }
    virtual ~Karakter() {}
};

class Golem : public Karakter {
public:
    Golem(string n, int h = 150) : Karakter(n, "SHORT", 500, h) {}
    void tampil() override { cout << "[GOLEM] "; Karakter::tampil(); }
};

class Knight : public Karakter {
public:
    Knight(string n, int h = 120) : Karakter(n, "MEDIUM", 2000, h) {}
    void tampil() override { cout << "[KNIGHT] "; Karakter::tampil(); }
};

class Archer : public Karakter {
public:
    Archer(string n, int h = 90) : Karakter(n, "LONG", 3000, h) {}
    void tampil() override { cout << "[ARCHER] "; Karakter::tampil(); }
};

class Sorcerer : public Karakter {
public:
    Sorcerer(string n, int h = 70) : Karakter(n, "AREA", 5000, h) {}
    void tampil() override { cout << "[SORCERER] "; Karakter::tampil(); }
};

class Game {
    vector<Karakter*> data;
    string file = "karakter.txt";
    
public:
    ~Game() { for(auto k : data) delete k; }
    
    void tambah(Karakter* k) { data.push_back(k); }
    
    void simpan() {
        ofstream f(file);
        for(auto k : data) {
            f << k->getNama() << "|" << k->getTipe() << "|" 
              << k->getMaxDmg() << "|" << k->getHealth() << endl;
        }
        f.close();
        cout << "Data tersimpan!\n";
    }
    
    void tampilData() {
        if(data.empty()) { cout << "Tidak ada data!\n"; return; }
        cout << "\n=== DATA KARAKTER ===\n";
        for(int i = 0; i < data.size(); i++) {
            cout << i+1 << ". ";
            data[i]->tampil();
            cout << endl;
        }
    }
    
    void mulaiSerang() {
        if(data.size() < 2) { cout << "Minimal 2 karakter!\n"; return; }
        
        cout << "\n=== PERTARUNGAN ===\n";
        for(int i = 0; i < data.size() - 1; i += 2) {
            int a = i, b = i + 1;
            cout << "\n" << data[a]->getNama() << " VS " << data[b]->getNama() << endl;
            cout << "-------------------\n";
            
            cout << data[a]->getNama() << " menyerang: ";
            int d1 = data[a]->serang();
            cout << endl;
            
            cout << data[b]->getNama() << " menyerang: ";
            int d2 = data[b]->serang();
            cout << endl;
            
            cout << "Hasil: ";
            if(d1 > d2) cout << data[a]->getNama() << " MENANG!";
            else if(d2 > d1) cout << data[b]->getNama() << " MENANG!";
            else cout << "SERI!";
            cout << " (" << d1 << " vs " << d2 << ")\n";
        }
        if(data.size() % 2 == 1) {
            cout << "\n" << data[data.size()-1]->getNama() << " tanpa lawan\n";
        }
    }
};

int main() {
    srand(time(0));
    Game game;
    int pilih;
    
    game.tambah(new Golem("Rocky", 450));
    game.tambah(new Knight("Arthur", 650));
    game.tambah(new Archer("Legolas", 900));
    game.tambah(new Sorcerer("Merlin", 780));
    game.simpan();
    
    do {
        cout << "\n--Menu--"
             << "\n1. Tampil Data"
             << "\n2. Serang"
             << "\n3. Keluar"
             << "\nPilihan: ";
        cin >> pilih;
        
        switch(pilih) {
            case 1: game.tampilData(); break;
            case 2: game.mulaiSerang(); break;
            case 3: cout << "Sampai jumpa!\n"; break;
            default: cout << "Pilihan salah!\n";
        }
    } while(pilih != 3);
    
    return 0;
}