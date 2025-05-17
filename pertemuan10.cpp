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

class Petugas {
private:
    string nama;
    string idPetugas;
    string levelAkses;

public:
    Petugas(string n, string id, string lvl) : nama(n), idPetugas(id), levelAkses(lvl) {}

void prosesPeminjaman(Buku* b, Peminjam* p) {
    if (!b->dipinjam){
        b->dipinjam = true;
        p->totalPinjaman++;
        cout << "Buku berhasil diponjam oleh " << p->nama << endl;
    }
    else {
        cout << "Buku sudah dipinjam.\n";
    }
}

void prosesKembali(Buku* b, Peminjam* p) {
    if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku berhasil dikembalikan oleh " << p->nama << endl;
    }
    else {
        cout << "Buku belum dipinjam.\n";
    }
}
};

