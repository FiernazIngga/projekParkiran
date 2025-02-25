#include "struct.cpp"

void sleep(int detik){
    this_thread::sleep_for(chrono::seconds(detik));
}

void eksekusiKendaraan(int tipeKendaraan, string plat, string waktuMasuk){
    if (tipeKendaraan == 1)
    {
        kendaraanMotor[jumlahRodaDua].type = "Kendaraan Beroda Dua";
        kendaraanMotor[jumlahRodaDua].plat = plat;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].harga = 3000;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].denda = 0;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].waktuKeluar = "Kendaraan Masih Didalam";
        jumlahRodaDua++;
    } else if (tipeKendaraan == 2)
    {
        kendaraanMobil[jumlahRodaEmpat].type = "Kendaraan Beroda Empat";
        kendaraanMobil[jumlahRodaEmpat].plat = plat;
        kendaraanMobil[jumlahRodaEmpat].parkirMotor[jumlahRodaEmpat].harga = 3000;
        kendaraanMobil[jumlahRodaEmpat].parkirMotor[jumlahRodaEmpat].denda = 0;
        kendaraanMobil[jumlahRodaEmpat].parkirMotor[jumlahRodaDua].waktuKeluar = "Kendaraan Masih Didalam";
        jumlahRodaEmpat++;
    }
}

void cetakKendaraan() {
    for (int i = 0; i < jumlahRodaDua; i++)
    {
        cout << kendaraanMotor[i].type << endl;
        cout << kendaraanMotor[i].plat << endl;
        cout << kendaraanMotor[i].parkirMotor[i].harga << endl;
        cout << kendaraanMotor[i].parkirMotor[i].denda << endl;
        cout << kendaraanMotor[i].parkirMotor[i].waktuKeluar << endl;
        cout << endl;
        cout << endl;
    }
    system("pause");
}

void kendaraanMasuk(){
    int tipeKendaraan, harga;
    bool ulangTipeKendaraan = true;
    string plat, waktuMasuk;
    while (ulangTipeKendaraan)
    {
        system("cls");
        cout << "Pilih Tipe Kendaraan Masukkan Dengan Angka (1/2/3) \n1. Kendaraan Roda Dua\n2. Kendaraan Roda Empat \n3. Roda Empat Keatas\n4. Kembali Ke Menu Utama\nMasukkan Tipe Kendaraan : ";
        cin >> tipeKendaraan;
        cin.ignore();
        switch (tipeKendaraan)
        {
        case 1:
            if (jumlahRodaDua <= maxLahanRodaDua)
            {
                cout << "Masukkan Plat Nomer : "; getline(cin, plat);
                cout << "Masukkan Waktu Kendaraan Masuk : "; getline(cin, waktuMasuk);
                eksekusiKendaraan(tipeKendaraan, plat, waktuMasuk);
                ulangTipeKendaraan = 0;
            } else {
                cout << "Maaf lahan parkir untuk kendaraan beroda dua telah penuh.\nTunggu 3 detik dan sistem otomatis kembali ke tampilan awal." << endl;
                sleep(3);
                ulangTipeKendaraan = 1;
            }
            break;
        case 2:
            if (jumlahRodaEmpat <= maxLahanRodaEmpat)
            {
                cout << "Masukkan Plat Nomer : "; getline(cin, plat);
                cout << "Masukkan Waktu Kendaraan Masuk : "; getline(cin, waktuMasuk);
                eksekusiKendaraan(tipeKendaraan, plat, waktuMasuk);
                ulangTipeKendaraan = 0;
            } else {
                cout << "Maaf lahan parkir untuk kendaraan beroda Empat telah penuh.\nTunggu 3 detik dan sistem otomatis kembali ke tampilan awal." << endl;
                sleep(3);
                ulangTipeKendaraan = 1;
            }
            break;
        
        default:
            break;
        }
    }
    
}