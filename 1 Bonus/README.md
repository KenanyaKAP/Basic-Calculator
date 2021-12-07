# DISCLAIMER
> #### DIMOHON UNTUK MEMAHAMI KODE DAN TIDAK HANYA MENGCOPY-PASTE
> #### DIMOHON UNTUK MENGUBAH KODE SEBISA MUNGKIN AGAR TIDAK SAMA SATU DENGAN YANG LAIN
> #### SEGALA KEMIRIPAN KODE DITANGGUNG SENDIRI :D

## Bonus Poin
1. Bonus jika bisa menginputkan angka yang jumlah digitnya lebih dari 1. Contoh 11 + 2 + 123 = 136

## Program
```c
#include <stdio.h>

int main(){
    int value = 0;
    int sum = 0;
    char operator = '+';
    
    printf("Masukkan inputan: ");

    while (1){
        scanf("%d", &value); // Ambil angka

        switch (operator){ // Lakukan operator
        case '+':
            sum += value;
            break;
        case '-':
            sum -= value;
            break;
        }

        scanf("%c", &operator); // Ambil spasi
        if (operator == '\n') break; // Kalo yang terambil ternyata \n, keluar loop

        scanf("%c", &operator); // Ambil operator
    }

    // Cetak hasil akhir
    printf("Hasil akhir: %d\n", sum);
    return 0;
}
```

## Logika Berpikir
- Pertama-tama buat variable int value, sum, dan char operator
- Lalu program akan melakukan perulangan / loop hingga program menemukan `\n` yaitu saat user menekan `Enter`.
- Pertama-tama program akan mengambil angka dengan `scanf("%d", &value);`
- Lanjut ke switch case. Karena `operator` secara default memiliki nilai `+`, maka nilai sum pertama kali akan ditambah dengan angka yang sudah didapatkan tadi.
- Selanjutnya program akan mengscan satu buah character dengan `scanf("%c", &operator);`
- Lakukan pengecekan apakah user menginputkan `Enter` alias `\n`. Kalau iya, maka program akan keluar perulangan / loop. Namun bila tidak, maka kode ini akan berguna untuk mendapatkan spasi
- Setelah spasi pastilah akan terdapat operator. Baik itu `+` atau `-`. Sehingga program sekali lagi `scanf("%c", &operator);`.
- Kembali lagi keatas untuk mendapatkan angka. Loop berulang hingga user menekan tombol `Enter` alias `\n`

Perlu diperhatikan bahwa program seperti ini sangat sensitif dan tidak bisa mendeteksi bila format yang diinputkan user salah.
