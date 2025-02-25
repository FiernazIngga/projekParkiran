#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

const int maxLahanRodaDua = 20;
int jumlahRodaDua = 0;
const int maxLahanRodaEmpat = 10;
int jumlahRodaEmpat = 0;

struct parkir
{
    int harga, denda;
    string waktuMasuk, waktuKeluar;
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