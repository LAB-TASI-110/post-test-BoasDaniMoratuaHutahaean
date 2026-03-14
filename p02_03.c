#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_PESANAN 50
#define MAX_MENU 8

typedef struct {
    int id;
    char nama[50];
    long harga;
} Menu;

typedef struct {
    char namaMenu[50];
    int jumlah;
    long subtotal;
} Pesanan;

Menu daftarMenu[MAX_MENU] = {
    {1, "Nasi Goreng Spesial KL", 15000},
    {2, "Mie Goreng Telur", 12000},
    {3, "Ayam Penyet + Nasi", 18000},
    {4, "Soto Ayam Del", 13000},
    {5, "Kopi Hitam", 5000},
    {6, "Es Teh Manis", 4000},
    {7, "Es Jeruk", 6000},
    {8, "Snack Gorengan (Isi 5)", 5000}
};

void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void tampilkanMenu() {
    printf("\n======================================================\n");
    printf("         MENU KANTIN LAMA (KL) - IT DEL\n");
    printf("======================================================\n");
    printf("ID\t| Nama Menu\t\t\t| Harga\n");
    printf("------------------------------------------------------\n");
    for(int i = 0; i < MAX_MENU; i++) {
        printf("%d\t| %-25s\t| Rp %ld\n", daftarMenu[i].id, daftarMenu[i].nama, daftarMenu[i].harga);
    }
    printf("======================================================\n");
}

int main() {
    char namaCustomer[50];
    char noWA[20];
    Pesanan keranjang[MAX_PESANAN];
    int jumlahPesanan = 0;
    long totalBelanja = 0;
    int pilihanMenu, kuantitas, lanjut;

    printf("======================================================\n");
    printf("    SISTEM PEMESANAN ONLINE KANTIN LAMA (KL) IT DEL\n");
    printf("======================================================\n");
    printf("Admin KL WA: 0812-3456-7890 (Untuk Bantuan & Konfirmasi)\n\n");

    printf("Masukkan Nama Anda: ");
    fgets(namaCustomer, sizeof(namaCustomer), stdin);
    namaCustomer[strcspn(namaCustomer, "\n")] = 0;

    printf("Masukkan Nomor WA Anda: ");
    fgets(noWA, sizeof(noWA), stdin);
    noWA[strcspn(noWA, "\n")] = 0;

    do {
        tampilkanMenu();
        printf("Pilih ID Menu yang ingin dipesan: ");
        scanf("%d", &pilihanMenu);

        if(pilihanMenu < 1 || pilihanMenu > MAX_MENU) {
            printf("ID Menu tidak valid! Silakan coba lagi.\n");
            bersihkanBuffer();
            continue;
        }

        printf("Jumlah pesanan: ");
        scanf("%d", &kuantitas);

        int indexMenu = pilihanMenu - 1;
        strcpy(keranjang[jumlahPesanan].namaMenu, daftarMenu[indexMenu].nama);
        keranjang[jumlahPesanan].jumlah = kuantitas;
        keranjang[jumlahPesanan].subtotal = daftarMenu[indexMenu].harga * kuantitas;
        
        totalBelanja += keranjang[jumlahPesanan].subtotal;
        jumlahPesanan++;

        printf("Tambah pesanan lain? (1 = Ya, 0 = Tidak): ");
        scanf("%d", &lanjut);
        bersihkanBuffer();

    } while (lanjut != 0 && jumlahPesanan < MAX_PESANAN);

    printf("\n======================================================\n");
    printf("                 RINGKASAN PESANAN\n");
    printf("======================================================\n");
    printf("Nama Pemesan : %s\n", namaCustomer);
    printf("Nomor WA     : %s\n", noWA);
    printf("------------------------------------------------------\n");
    for(int i = 0; i < jumlahPesanan; i++) {
        printf("%-25s x%d\t: Rp %ld\n", keranjang[i].namaMenu, keranjang[i].jumlah, keranjang[i].subtotal);
    }
    printf("------------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN\t\t: Rp %ld\n", totalBelanja);
    printf("======================================================\n");

    int metodePembayaran;
    printf("\nPilih Metode Pembayaran Digital:\n");
    printf("1. QRIS (All Payment)\n");
    printf("2. DANA\n");
    printf("3. GoPay\n");
    printf("4. BRImo\n");
    printf("5. Wondr by BNI\n");
    printf("Pilihan Anda (1-5): ");
    scanf("%d", &metodePembayaran);

    printf("\nMemproses pembayaran...\n");
    Sleep(2000);
    printf("PEMBAYARAN BERHASIL! Saldo telah terpotong.\n");

    printf("\nPesanan Anda sedang disiapkan oleh pihak Kantin Lama...\n");
    Sleep(3000);

    printf("\n******************************************************\n");
    printf("                    PESANAN SELESAI!\n");
    printf("******************************************************\n");
    printf("Memanggil customer...\n");
    Sleep(1000);
    printf("Sistem mengirim pesan WA ke %s (%s)...\n", namaCustomer, noWA);
    printf("Pesan: \"Halo %s, pesanan Anda sudah siap! Silakan ambil di konter Kantin Lama (KL). Terima kasih!\"\n", namaCustomer);
    printf("******************************************************\n");

    return 0;
}