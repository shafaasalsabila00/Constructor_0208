//Latihan B

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

    friend class Admin;
};

class Admin {
public:
    void ubahLevelAkses(Petugas* p, string levelBaru) {
        p->levelAkses = levelBaru;
        cout << "Level akses petugas diubah menjadi: " << levelBaru << endl;
    }

    friend void lihatStatus(Admin* a, Peminjam* p, Buku* b);
};

void lihatStatus(Admin* a, Peminjam* p, Buku* b) {
    cout << "Admin melihat: " << p->totalPinjaman << " buku sedang dipinjam.\n";
    cout << "Status buku: " << (b->dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

int main() {
    Buku buku1("Pemrograman C++", "Budi");
    Peminjam peminjam1("Andi", "P001");
    Petugas petugas1("Sita", "T001", "normal");
    Admin admin1;

    buku1.tampilkanInfo();

    petugas1.prosesPeminjaman(&buku1, &peminjam1);
    buku1.tampilkanInfo();

    lihatStatus(&admin1, &peminjam1, &buku1);

    admin1.ubahLevelAkses(&petugas1, "supervisor");

    petugas1.prosesKembali(&buku1, &peminjam1);
    buku1.tampilkanInfo();

    return 0;
}











// Act 9

// chainfunction
#include <iostream>
using namespace std;

class buku
{
    string judul;

public:
    buku setJudul(string judul)
    {
        this->judul = judul;
        return *this; // chain function
    }

    string getJudul()
    {
        return this->judul;
    }

} bukunya;

int main()
{
    // bukunya.setJudul("Matematika");
    // cout << bukunya.getJudul();
    cout << bukunya.setJudul("Matematika").getJudul(); // chain function calls
    return 0;
}


// destruktor
#include <iostream>
using namespace std;

class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int);       // Constructor
    ~angka();         // Destructor
    void cetakData();
    void isiData();
};

// Definisi member function
angka::angka(int i) { // Constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka() { // Destructor
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}

void angka::cetakData() {
    for (int i = 1; i < panjang; i++) {
        cout << i << " = " << arr[i] << endl;
    }
}

void angka::isiData() {
    for (int i = 1; i < panjang; i++) {
        cout << i << " = "; cin >> arr[i];
    }
    cout << endl;
}

int main() {
    angka belajarcpp(3);                // Constructor Dipanggil
    angka *ptrBelajarcpp = new angka(5); // Constructor Dipanggil
    delete ptrBelajarcpp;              // Destructor Dipanggil

    return 0;
} // Destructor Dipanggil


// konstruktor
#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    int nim;
    string nama;

public:
    mahasiswa();
    mahasiswa(int);
    mahasiswa(string);
    mahasiswa(int iNim, string iNama);
    void cetak();
};

mahasiswa::mahasiswa() {
    nim = 0;
    nama = "";
}

mahasiswa::mahasiswa(int iNim) {
    nim = iNim;
}

mahasiswa::mahasiswa(string iNama) {
    nama = iNama;
}

mahasiswa::mahasiswa(int iNim, string iNama) {
    nim = iNim;
    nama = iNama;
}

void mahasiswa::cetak() {
    cout << endl << "Nim = " << nim << endl;
    cout << "Nama = " << nama << endl;
}

int main() {
    mahasiswa mhs1;
    mahasiswa mhs2(20);
    mahasiswa mhs3("Indra");
    mahasiswa mhs4(30, "Fauzan");

    mhs1.cetak();
    mhs2.cetak();
    mhs3.cetak();
    mhs4.cetak();

    return 0;
}


//mbrStatikfunc
#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    static int nim;

public:
    int id;
    string nama;

    void setID();
    void printAll();

    static void setNim(int pNim) { nim = pNim; }   // Definisi Function
    static int getNim() { return nim; }           // Definisi Function
};