#include <iostream>
#include <string>
using namespace std;

class Petugas;
class Admin;
class Peminjam;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

void tampilkanInfo() {
    cout << "Judul: " << judul << ", Penulis: " << penulis
         << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

    friend class Petugas;
    friend void lihatStatus(Admin*, Peminjam*, Buku*);

};

class Peminjam {
private:
    string nama;
    string id;
    int totalPinjaman;

public:
    Peminjam(string n, string i) : nama(n), id(i), totalPinjaman(0) {}

    friend class Petugas;
    friend void lihatStatus(Admin*, Peminjam*, Buku*);
};

