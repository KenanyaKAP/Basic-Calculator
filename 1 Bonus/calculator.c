// Bonus angka digit lebih dari 1

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

/*
Logika berpikir:
Secara default sum = 0 dan operator = '+'
Ambil angka dulu, lalu dioperasikan ke sum
(karena operator awal +, maka sum akan bernilai angka pertama)
lalu ambil operator selanjutnya

kembali lagi keatas
ambil angka, lalu operasikan ke sum
bila operator +, sum += value
bila operator -, sum -= value
ambil operator selanjutnya lagi

dilakukan terus menerus
sampai bila operator bernilai '\n'
yaitu apabila pengguna menekan enter
maka break / keluar loop

lalu cetak hasil
*/
