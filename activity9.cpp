#include <iostream>
using namespace std;

class Mahasiswa {
    private : 
        static int totalMahasiswa;
    public : 
        string nama;
        string status;
        int umur;

        Mahasiswa(string pNama, int pUmur) {
            nama = pNama;
            umur = pUmur;
            status = "Mahasiswa Baru";
            ++totalMahasiswa;
            cout << nama << " Created" << " Status " 
            << status << endl;
            cout << endl;
        }

        ~Mahasiswa() {
            cout << nama << " Destroyed" << endl;
            --totalMahasiswa;
            cout << endl;
        }

        static int gettotalMahasiswa() 
        {
            return totalMahasiswa;
        }

        static void settotalMahasiswa(int a) {
            totalMahasiswa = a;
        }
};

int Mahasiswa::totalMahasiswa = 0;

int main() {

    cout << "Total mahasiswa adalah " <<
    Mahasiswa::gettotalMahasiswa() << endl;

    Mahasiswa mhs1("Maman", 40);
    Mahasiswa mhs2("Agus", 34);

    Mahasiswa::settotalMahasiswa(10);

    cout << "Total mahasiswa adalah " <<
    Mahasiswa::gettotalMahasiswa() << endl;

    {
        Mahasiswa mhs3("Budi", 19);
        Mahasiswa mhs4("Caca", 21);
        cout << "Total mahasiswa adalah " <<
        Mahasiswa::gettotalMahasiswa() << endl;
    }

    cout << "Total mahasiswa adalah " <<
    Mahasiswa::gettotalMahasiswa() << endl;
    
}