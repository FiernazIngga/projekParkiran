#include "function.cpp"

int main(){
    bool ulangMenu = true;
    while (ulangMenu)
    {
        system("cls");
        int pilihanMenuUtama;
        cout << "Selamat Datang Di Parkiran Mall AffanJaya" << endl;
        cout << "1. Kendaraan Masuk\n2. Cek Kendaraan\n3. Kendaraan Keluar\n4. Keluar Program\nPilih Menu Diatas Masukkan Angka (1/2/3/4) : ";
        cin >> pilihanMenuUtama;
        cin.ignore();
        switch (pilihanMenuUtama)
        {
        case 1:
            kendaraanMasuk();
            ulangMenu = 1;
            break;
        case 2:
            cekKendaraan();
            ulangMenu = 1;
            break;
        case 3:
            /* code */
            ulangMenu = 1;
            break;
        case 4:
            ulangMenu = 0;
            break;
        
        default:
            ulangMenu = 1;
            break;
        }
    }
}