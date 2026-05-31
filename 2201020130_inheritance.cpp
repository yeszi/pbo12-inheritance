#include <iostream>
#include <vector>
using namespace std;

class Manusia {
protected:
    string nama;
    string alamat;
    string ttl;      

public:
    Manusia(string n, string a, string t)
        : nama(n), alamat(a), ttl(t) {}

    virtual void tampilInfo() {
        cout << "Nama    : " << nama << endl;
        cout << "Alamat  : " << alamat << endl;
        cout << "TTL     : " << ttl << endl;
    }

    virtual ~Manusia() {}
};

class Mahasiswa : public Manusia {
private:
    string nim;

public:
    Mahasiswa(string n, string a, string t, string nim)
        : Manusia(n, a, t), nim(nim) {}

    void tampilInfo() override {
        cout << "[MAHASISWA]" << endl;
        Manusia::tampilInfo();
        cout << "NIM     : " << nim << endl;
    }
};

class Pegawai : public Manusia {
protected:
    string nip;
    string reg;       

public:
    Pegawai(string n, string a, string t, string nip, string reg)
        : Manusia(n, a, t), nip(nip), reg(reg) {}

    void tampilInfo() override {
        cout << "[PEGAWAI]" << endl;
        Manusia::tampilInfo();
        cout << "NIP     : " << nip << endl;
        cout << "REG     : " << reg << endl;
    }
};

class Staff : public Pegawai {
private:
    string jobDesc;

public:
    Staff(string n, string a, string t, string nip, string reg, string job)
        : Pegawai(n, a, t, nip, reg), jobDesc(job) {}

    void tampilInfo() override {
        cout << "[STAFF]" << endl;
        Pegawai::tampilInfo();
        cout << "Job Desc: " << jobDesc << endl;
    }
};

class Dosen : public Pegawai {
private:
    string jadwal;
    string matkul;    
    string diampu;    

public:
    Dosen(string n, string a, string t, string nip, string reg, string jadwal, string mk, string diampu)
        : Pegawai(n, a, t, nip, reg), jadwal(jadwal), matkul(mk), diampu(diampu) {}

    void tampilInfo() override {
        cout << "[DOSEN]" << endl;
        Pegawai::tampilInfo();
        cout << "Jadwal  : " << jadwal << endl;
        cout << "Matkul  : " << matkul << endl;
        cout << "Diampu  : " << diampu << endl;
    }
};

int main() {
    vector<Manusia*> data;

    data.push_back(new Mahasiswa(
        "Andi Pratama",
        "Jl. Merdeka No. 5",
        "Batam, 12-03-2003",
        "2023001"
    ));

    data.push_back(new Staff(
        "Budi Santoso",
        "Jl. Sudirman No. 10",
        "Tanjungpinang, 05-07-1985",
        "NIP001", "REG-A1",
        "Administrasi Akademik"
    ));

    data.push_back(new Dosen(
        "Dr. Citra Lestari",
        "Jl. Pahlawan No. 3",
        "Pekanbaru, 20-01-1979",
        "NIP002", "REG-B2",
        "Senin 08.00-10.00",
        "Pemrograman OOP",
        "Algoritma & Struktur Data"
    ));

    cout << "===== DATA CIVITAS AKADEMIKA =====" << endl;
    for (auto p : data) {
        cout << "----------------------------------" << endl;
        p->tampilInfo();  
    }
    cout << "==================================" << endl;

    for (auto p : data) delete p;
    return 0;
}