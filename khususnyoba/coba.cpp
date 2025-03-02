#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

int main(){
    time_t waktu_sekarang;
    // Deklarasi variabel waktu_sekarang bertipe time_t untuk menyimpan waktu saat ini
    time(&waktu_sekarang);
        // Mendapatkan waktu saat ini dalam format UNIX dan menyimpannya dalam waktu_sekarang
    tm* waktu_lokal = localtime(&waktu_sekarang);
        // Mengonversi waktu UNIX menjadi waktu lokal dalam bentuk struktur tm
    put_time(waktu_lokal, "%H:%M:%S %d-%B-%Y");
        // Menampilkan waktu dalam format "HH:MM:SS DD-Bulan-YYYY" menggunakan std::put_time
}
