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

