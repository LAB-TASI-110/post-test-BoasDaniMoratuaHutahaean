/*
 * Program: Kalkulasi Stok Kategori Barang Gudang (Versi Struct)
 * Author: Boas Dani Moratua Hutahaean
 * Compiler Target: MinGW-W64 x86_64-ucrt-posix-seh 14.2.0
 */

#include <stdio.h>
#include <string.h>

// 1. Mendefinisikan struct untuk merepresentasikan entitas Barang
struct Barang {
    char nama[50];
    int stok;
    int kategori; // Kode: 1 = Sembako, 2 = Perlengkapan Sekolah
};

int main() {
    int N;

    // Menentukan jumlah total data (N)
    printf("Masukkan jumlah data (N): ");
    if (scanf("%d", &N) != 1) return 1;

    // Membersihkan sisa karakter newline ('\n') dari buffer setelah scanf
    getchar();

    // Membuat array dari struct Barang sebanyak N
    struct Barang daftar_barang[N];

    // 2. Meminta input detail untuk tiap barang
    printf("\n=== INPUT DATA BARANG ===\n");
    for (int i = 0; i < N; i++) {
        printf("\nData Barang ke-%d\n", i + 1);
        
        printf("Nama Barang  : ");
        // Menggunakan fgets agar bisa membaca string yang mengandung spasi
        fgets(daftar_barang[i].nama, sizeof(daftar_barang[i].nama), stdin);
        // Menghilangkan karakter enter/newline yang terbawa oleh fgets
        daftar_barang[i].nama[strcspn(daftar_barang[i].nama, "\n")] = 0;

        printf("Jumlah Stok  : ");
        scanf("%d", &daftar_barang[i].stok);

        printf("Kode Kategori (1=Sembako, 2=Perlengkapan Sekolah): ");
        scanf("%d", &daftar_barang[i].kategori);

        // Membersihkan buffer lagi sebelum looping kembali ke fgets
        getchar();
    }

    // 3. Meminta input kategori yang ingin dihitung
    int target_kategori;
    printf("\nMasukkan kode kategori yang ingin dihitung total stoknya: ");
    scanf("%d", &target_kategori);

    // Proses menghitung total stok dan menampilkan rinciannya
    int total_stok = 0;
    
    printf("\n================ HASIL ================\n");
    printf("Rincian barang untuk kategori %d:\n", target_kategori);
    
    for (int i = 0; i < N; i++) {
        if (daftar_barang[i].kategori == target_kategori) {
            printf("- %s \t: %d pcs\n", daftar_barang[i].nama, daftar_barang[i].stok);
            total_stok += daftar_barang[i].stok;
        }
    }

    printf("---------------------------------------\n");
    printf("TOTAL STOK \t\t: %d pcs\n", total_stok);
    printf("=======================================\n");

    return 0;
}