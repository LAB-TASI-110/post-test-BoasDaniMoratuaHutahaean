#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    float berat_butet, berat_ucok, total_berat;
    
    printf("========================================\n");
    printf("   Sistem Kasir Otomatis Del-Express    \n");
    printf("========================================\n");
    printf("Masukkan data (ketik END untuk selesai):\n\n");

    while (1) {
        scanf("%s", kode);
        
        if (strcmp(kode, "END") == 0) {
            printf("Sistem dihentikan. Terima kasih telah menggunakan Del-Express!\n");
            break;
        }

        scanf("%f", &berat_butet);

        berat_ucok = berat_butet * 1.5;
        total_berat = berat_butet + berat_ucok;

        char kota[50] = "";
        char region[50] = "";
        float tarif_per_kg = 0;

        if (strcmp(kode, "MDN") == 0) {
            strcpy(kota, "Medan");
            strcpy(region, "Dalam Pulau");
            tarif_per_kg = 8000;
        } else if (strcmp(kode, "BLG") == 0) {
            strcpy(kota, "Balige");
            strcpy(region, "Dalam Pulau");
            tarif_per_kg = 5000;
        } else if (strcmp(kode, "JKT") == 0) {
            strcpy(kota, "Jakarta");
            strcpy(region, "Luar Pulau");
            tarif_per_kg = 12000;
        } else if (strcmp(kode, "SBY") == 0) {
            strcpy(kota, "Surabaya");
            strcpy(region, "Luar Pulau");
            tarif_per_kg = 13000;
        } else {
            printf("Error: Kode kota '%s' tidak dikenali. Silakan coba lagi.\n\n", kode);
            continue;
        }

        float total_ongkir = total_berat * tarif_per_kg;
        char info_promo[100] = "-";

        if (total_berat > 10.0 && strcmp(region, "Luar Pulau") == 0) {
            float diskon = total_ongkir * 0.10;
            total_ongkir = total_ongkir - diskon;
            strcpy(info_promo, "Diskon Ongkir 10% + Asuransi Gratis");
        }

        printf("\n========================================\n");
        printf("      STRUK PEMBAYARAN DEL-EXPRESS      \n");
        printf("========================================\n");
        printf("Kota Tujuan         : %s\n", kota);
        printf("Berat Paket Butet   : %.2f kg\n", berat_butet);
        printf("Berat Paket Ucok    : %.2f kg\n", berat_ucok);
        printf("Total Berat         : %.2f kg\n", total_berat);
        printf("Total Ongkos Kirim  : Rp %.0f\n", total_ongkir);
        printf("Promo Diperoleh     : %s\n", info_promo);
        printf("========================================\n\n");
    }

    return 0;
}