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
