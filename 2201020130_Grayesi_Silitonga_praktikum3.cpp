#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void simpanMahasiswa() {
    string nama, nim, prodi, fakultas;
    float ipk;

    cout << "==============================" << endl;
    cout << "     INPUT DATA MAHASISWA     " << endl;
    cout << "==============================" << endl;
    cout << "Nama     : "; getline(cin, nama);
    cout << "NIM      : "; getline(cin, nim);
    cout << "Prodi    : "; getline(cin, prodi);
    cout << "Fakultas : "; getline(cin, fakultas);
    cout << "IPK      : "; cin >> ipk;
    cin.ignore();

    ofstream file("mahasiswa.txt", ios::app);
    if (file.is_open()) {
        file << "==============================" << endl;
        file << "Nama     : " << nama << endl;
        file << "NIM      : " << nim << endl;
        file << "Prodi    : " << prodi << endl;
        file << "Fakultas : " << fakultas << endl;
        file << "IPK      : " << ipk << endl;
        file.close();
        cout << "\nData mahasiswa berhasil disimpan ke mahasiswa.txt" << endl;
    } else {
        cout << "Gagal membuka file!" << endl;
    }
}

void tampilkanMahasiswa() {
    string isiText;
    ifstream file("mahasiswa.txt");

    cout << "\n==============================" << endl;
    cout << "     DATA MAHASISWA           " << endl;
    cout << "==============================" << endl;

    if (file.is_open()) {
        while (getline(file, isiText)) {
            cout << isiText << endl;
        }
        file.close();
    } else {
        cout << "File tidak ditemukan!" << endl;
    }
}

void simpanPegawai() {
    string nama, nip, jabatan, divisi;
    float gaji;

    cout << "\n==============================" << endl;
    cout << "      INPUT DATA PEGAWAI      " << endl;
    cout << "==============================" << endl;
    cout << "Nama    : "; getline(cin, nama);
    cout << "NIP     : "; getline(cin, nip);
    cout << "Jabatan : "; getline(cin, jabatan);
    cout << "Divisi  : "; getline(cin, divisi);
    cout << "Gaji    : "; cin >> gaji;
    cin.ignore();

    fstream file("pegawai.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << "==============================" << endl;
        file << "Nama    : " << nama << endl;
        file << "NIP     : " << nip << endl;
        file << "Jabatan : " << jabatan << endl;
        file << "Divisi  : " << divisi << endl;
        file << "Gaji    : Rp " << gaji << endl;
        file.close();
        cout << "\nData pegawai berhasil disimpan ke pegawai.txt" << endl;
    } else {
        cout << "Gagal membuka file!" << endl;
    }
}

void tampilkanPegawai() {
    string isiText;
    fstream file("pegawai.txt", ios::in);

    cout << "\n==============================" << endl;
    cout << "       DATA PEGAWAI           " << endl;
    cout << "==============================" << endl;

    if (file.is_open()) {
        while (getline(file, isiText)) {
            cout << isiText << endl;
        }
        file.close();
    } else {
        cout << "File tidak ditemukan!" << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n==============================" << endl;
        cout << "          MENU UTAMA          " << endl;
        cout << "==============================" << endl;
        cout << "1. Simpan Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Simpan Data Pegawai" << endl;
        cout << "4. Tampilkan Data Pegawai" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : "; cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: simpanMahasiswa();    break;
            case 2: tampilkanMahasiswa(); break;
            case 3: simpanPegawai();      break;
            case 4: tampilkanPegawai();   break;
            case 0: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
