#include "struct.cpp"

void sleep(int detik){
    this_thread::sleep_for(chrono::seconds(detik));
}

string waktuSaatIni(){
    time_t waktu_sekarang;
    time(&waktu_sekarang);
    tm* waktu_lokal = localtime(&waktu_sekarang);
    stringstream ss;
    ss << put_time(waktu_lokal, "%H:%M:%S %d-%B-%Y");
    return ss.str();
}

void eksekusiKendaraan(int tipeKendaraan, string plat, string waktuMasuk){
    if (tipeKendaraan == 1)
    {
        kendaraanMotor[jumlahRodaDua].type = "Kendaraan Beroda Dua";
        kendaraanMotor[jumlahRodaDua].plat = plat;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].harga = 3000;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].denda = 0;
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].eksekusiWaktuMasuk();
        kendaraanMotor[jumlahRodaDua].parkirMotor[jumlahRodaDua].waktuKeluar = "Kendaraan Masih Didalam";
        jumlahRodaDua++;
    } else if (tipeKendaraan == 2)
    {
        kendaraanMobil[jumlahRodaEmpat].type = "Kendaraan Beroda Empat";
        kendaraanMobil[jumlahRodaEmpat].plat = plat;
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].harga = 3000;
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].denda = 0;
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].eksekusiWaktuMasuk();
        kendaraanMobil[jumlahRodaEmpat].parkirMobil[jumlahRodaEmpat].waktuKeluar = "Kendaraan Masih Didalam";
        jumlahRodaEmpat++;
    }
}

int dendaKendaraan(string tipe, int indeks){
    tm* waktu_lokal = waktuLocal();
    int tahun = ((waktu_lokal->tm_year) + 1900);
    int bulan = (waktu_lokal->tm_mon)+1;
    int tanggal = waktu_lokal->tm_mday;
    int jam = waktu_lokal->tm_hour;
    int menit = waktu_lokal->tm_min;
    int detik = waktu_lokal->tm_sec;
    bool tahunKabisat = false;
    if (tipe == "rodaDua")
    {
        if ((tahun - kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[5]) != 0)
        {
            if ((tahun % 4) == 0)
            {
                if ((tahun % 100) == 0)
                {
                    if ((tahun % 400) == 0)
                    {
                        kendaraanMotor[indeks].parkirMotor[indeks].denda += (((tahun - kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[5]) * 366 * 24 * 60) / 3) * 3000;
                        tahunKabisat = 1;
                    } else {
                        kendaraanMotor[indeks].parkirMotor[indeks].denda += (((tahun - kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[5]) * 365 * 24 * 60) / 3) * 3000;
                    }
                } else {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += (((tahun - kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[5]) * 366 * 24 * 60) / 3) * 3000;
                    tahunKabisat = 1;
                }
            } else {
                kendaraanMotor[indeks].parkirMotor[indeks].denda += (((tahun - kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[5]) * 365 * 24 * 60) / 3) * 3000;
            }
        } else {
            if ((bulan - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[4])) > 0)
            {
                if (bulan == 2 && tahunKabisat == 1)
                {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += (((28 * 24 * 60) / 3) * 3000);
                } else if (bulan == 2 && tahunKabisat == 0) 
                {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += (((29 * 24 * 60) / 3) * 3000);
                } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11)
                {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += (((30 * 24 * 60) / 3) * 3000);
                } else {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += (((31 * 24 * 60) / 3) * 3000);
                }
            } else {
                if ((tanggal - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[3])) > 0)
                {
                    kendaraanMotor[indeks].parkirMotor[indeks].denda += ((tanggal - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[3]) * 24 * 60) / 3) * 3000;
                } else {
                    if ((jam - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[2])) > 0)
                    {
                        kendaraanMotor[indeks].parkirMotor[indeks].denda += ((jam - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[3])) * 60 / 3) * 3000;
                    } else {
                        if ((menit - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[1])) > 3)
                        {
                            kendaraanMotor[indeks].parkirMotor[indeks].denda += (menit - (kendaraanMotor[indeks].parkirMotor[indeks].waktuMasuk[1])) * 3000;
                        } else {
                            kendaraanMotor[indeks].parkirMotor[indeks].denda += 0;
                        }
                    }
                }
            } 
        }
    }
    
}

void cetakKendaraanMotor(int rodaDua) {
    if (jumlahRodaDua == 0)
    {
        cout << "Belum ada kendaraan beroda dua" << endl;
    } else if (rodaDua < jumlahRodaDua)
    {
        dendaKendaraan("rodaDua", rodaDua);
        cout << "Tipe Kendaraan         : " << kendaraanMotor[rodaDua].type << endl;
        cout << "Plat Kendaraan         : " << kendaraanMotor[rodaDua].plat << endl;
        cout << "Biaya Parkir           : " << kendaraanMotor[rodaDua].parkirMotor[rodaDua].harga << endl;
        cout << "Denda Parkir           : " << kendaraanMotor[rodaDua].parkirMotor[rodaDua].denda << endl;
        cout << "Waktu Masuk Kendaraan  : " ; kendaraanMotor[rodaDua].parkirMotor[rodaDua].lihatWaktu();
        cout << "Waktu Keluar Kendaraan : " << kendaraanMotor[rodaDua].parkirMotor[rodaDua].waktuKeluar << endl;
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
        cout << "Tipe Kendaraan         : "  << kendaraanMobil[rodaEmpat].type << endl;
        cout << "Plat Kendaraan         : "  << kendaraanMobil[rodaEmpat].plat << endl;
        cout << "Biaya Parkir           : "  << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].harga << endl;
        cout << "Denda Parkir           : "  << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].denda << endl;
        cout << "Waktu Masuk Kendaraan  : "  ; kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].lihatWaktu();
        cout << "Waktu Keluar Kendaraan : "  << kendaraanMobil[rodaEmpat].parkirMobil[rodaEmpat].waktuKeluar << endl;
        cout << endl;
        cout << endl;
        cetakKendaraanMobil(rodaEmpat+1);
    } 
}

void cariKendaraanPlat(int cariPlatRoda){
    string platDiCari;
    int i = 0;
    if (cariPlatRoda == 1)
    {
        cout << "Masukkan plat yang anda cari: "; getline(cin, platDiCari);
        kendaraanMotor[jumlahRodaDua + 1].plat = platDiCari;
        while (kendaraanMotor[i].plat != platDiCari)
        {
            i++;
        }
        if (i < jumlahRodaDua)
        { 
            dendaKendaraan("rodaDua", i);
            cout << "Kendaraan yang anda cari berdasarkan plat: " << platDiCari << endl;
            cout << "Tipe Kendaraan         : " << kendaraanMotor[i].type << endl;
            cout << "Plat Kendaraan         : " << kendaraanMotor[i].plat << endl;
            cout << "Biaya Parkir           : " << kendaraanMotor[i].parkirMotor[i].harga << endl;
            cout << "Denda Parkir           : " << kendaraanMotor[i].parkirMotor[i].denda << endl;
            cout << "Waktu Masuk Kendaraan  : "; kendaraanMotor[i].parkirMotor[i].lihatWaktu();
            cout << "Waktu Keluar Kendaraan : " << kendaraanMotor[i].parkirMotor[i].waktuKeluar << endl;
        } else {
            cout << "Kendaraan dengan plat "<< platDiCari <<" tidak ditemukan" << endl;
        }
    } else {
        cout << "Masukkan plat yang anda cari: "; getline(cin, platDiCari);
        kendaraanMobil[jumlahRodaEmpat+1].plat = platDiCari;
        while (kendaraanMobil[i].plat != platDiCari)
        {
            i++;
        }
        if (i < jumlahRodaEmpat)
        {
            cout << "Kendaraan yang anda cari berdasarkan plat: " << platDiCari << endl;
            cout << "Tipe Kendaraan         : "  << kendaraanMobil[i].type << endl;
            cout << "Plat Kendaraan         : "  << kendaraanMobil[i].plat << endl;
            cout << "Biaya Parkir           : "  << kendaraanMobil[i].parkirMobil[i].harga << endl;
            cout << "Denda Parkir           : "  << kendaraanMobil[i].parkirMobil[i].denda << endl;
            cout << "Waktu Masuk Kendaraan  : "  << kendaraanMobil[i].parkirMobil[i].waktuMasuk << endl;
            cout << "Waktu Keluar Kendaraan : "  << kendaraanMobil[i].parkirMobil[i].waktuKeluar << endl;
        } else {
            cout << "Kendaraan dengan plat "<< platDiCari <<" tidak ditemukan" << endl;
        }
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
                system("cls");
                cout << "Masukkan Plat Nomer : "; getline(cin, plat);
                waktuMasuk = waktuSaatIni();
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
                system("cls");
                cout << "Masukkan Plat Nomer : "; getline(cin, plat);
                waktuMasuk = waktuSaatIni();
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
    int pilihanCek, cariPlatRoda;
    system("cls");
    cout << "Pilih menu dibawah ini untuk melihat kendaraan" << endl;
    cout << "1. Cek Semua Kendaraan" << endl;
    cout << "2. Cek Berdasarkan Plat Kendaraan" << endl;
    cout << "3. Cek Sorting Berdasarkan Denda" << endl;
    cout << "Masukkan pilihan (1/2/3) : "; cin >> pilihanCek;
    cin.ignore();
    switch (pilihanCek)
    {
    case 1:
        system("cls");
            cetakKendaraanMotor(0);
            cetakKendaraanMobil(0);
        system("pause");
        break;
    case 2:
        system("cls");
            cout << "Cari \n1. Kendaraan roda dua\n2. Kendaraan roda tiga\nMasukkan pilihan anda: "; cin >> cariPlatRoda; cin.ignore();
            cariKendaraanPlat(cariPlatRoda);
        system("pause");
        break;
    
    default:
        break;
    }
}