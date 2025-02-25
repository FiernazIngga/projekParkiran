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
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].harga = 3000;
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].denda = 0;
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].waktuKeluar = "Kendaraan Masih Didalam";
        jumlahRodaEmpat++;
    }
}

void cetakKendaraanMotor(int rodaDua) {
    if (jumlahRodaDua == 0)
    {
        cout << "Belum ada kendaraan beroda dua" << endl;
    } else if (rodaDua < jumlahRodaDua)
    {
        cout << kendaraanMotor[rodaDua].type << endl;
        cout << kendaraanMotor[rodaDua].plat << endl;
        cout << kendaraanMotor[rodaDua].parkirMotor[rodaDua].harga << endl;
        cout << kendaraanMotor[rodaDua].parkirMotor[rodaDua].denda << endl;
        cout << kendaraanMotor[rodaDua].parkirMotor[rodaDua].waktuKeluar << endl;
        cout << endl;
        cout << endl;
        cetakKendaraanMotor(rodaDua+1);
    } 
}

void cetakKendaraanMobil(int rodaEmpat){
    if (jumlahRodaEmpat == 0)
    {
        cout << "Belum ada kendaraan beroda empat" << endl;
    } else if (rodaEmpat < jumlahRodaEmpat)
    {
        cout << kendaraanMobil[rodaEmpat].type << endl;
        cout << kendaraanMobil[rodaEmpat].plat << endl;
        cout << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].harga << endl;
        cout << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].denda << endl;
        cout << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].waktuKeluar << endl;
        cout << endl;
        cout << endl;
        cetakKendaraanMobil(rodaEmpat+1);
    } 
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

void cekKendaraan(){
    int pilihanCek;
    system("cls");
    cout << "Pilih menu dibawah ini untuk melihat kendaraan" << endl;
    cout << "1. Cek Semua Kendaraan" << endl;
    cout << "2. Cek Berdasarkan Plat Kendaraan" << endl;
    cout << "3. Cek Berdasarkan Waktu Masuk Kendaraan" << endl;
    cout << "Masukkan pilihan (1/2/3) : "; cin >> pilihanCek;
    cin.ignore();
    switch (pilihanCek)
    {
    case 1:
        system("cls");
        if (jumlahRodaDua == 0 && jumlahRodaEmpat == 0)
        {
            cout << "Belum ada kendaraan terpakir" << endl;
        } else {
            cetakKendaraanMotor(0);
            cetakKendaraanMobil(0);
        }
        system("pause");
        break;
    
    default:
        break;
    }
}