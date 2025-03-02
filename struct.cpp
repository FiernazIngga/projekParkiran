#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

const int maxLahanRodaDua = 20;
int jumlahRodaDua = 0;
const int maxLahanRodaEmpat = 10;
int jumlahRodaEmpat = 0;

tm* waktuLocal(){
    time_t waktu_sekarang;
    time(&waktu_sekarang);
    tm* waktu_lokal = localtime(&waktu_sekarang);
    return waktu_lokal;
}

struct parkir
{
    int harga, denda;
    int waktuMasuk[6];
    string waktuKeluar;

    tm* waktu_lokal = waktuLocal();
    void eksekusiWaktuMasuk(){
        this->waktuMasuk[0] = waktu_lokal->tm_sec;
        this->waktuMasuk[1] = waktu_lokal->tm_min;
        this->waktuMasuk[2] = waktu_lokal->tm_hour;
        this->waktuMasuk[3] = waktu_lokal->tm_mday;
        this->waktuMasuk[4] = (waktu_lokal->tm_mon)+1;
        this->waktuMasuk[5] = (waktu_lokal->tm_year)+1900;
    }
    void lihatWaktu(){
        string bulan[12] = {
            "Januari", 
            "Februari", 
            "Maret", 
            "April", 
            "Mei", 
            "Juni", 
            "Juli", 
            "Agustus", 
            "September", 
            "Oktober", 
            "November", 
            "Desember"
        };        
        
        cout << this->waktuMasuk[0] << ":" << this->waktuMasuk[1]
        << ":" << this->waktuMasuk[2]  << " " << this->waktuMasuk[3] 
        << "-" << bulan[(this->waktuMasuk[4]) - 1]  << "-" << this->waktuMasuk[5] << endl;
    }
};

struct DataKendaraan
{
    int jumlahRodaDua;
    string type, plat;
    parkir parkirMotor[maxLahanRodaDua];
    parkir parkirMobil[maxLahanRodaEmpat];
};

DataKendaraan kendaraanMotor[maxLahanRodaDua]; 
DataKendaraan kendaraanMobil[maxLahanRodaEmpat]; 