// Bonus angka digit lebih dari 1
// Bonus perkalian pembagian
// Bonus deteksi tidak valid

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char input[512] = "13 + 17 * 2 - 11";
    int number[512] = {0}; int numberCount = 0; // Buat tampungan angka saat nanti dipisah-pisah
    char oper[512]; int operCount = 0; // Buat tampungan operator saat nanti dipisah-pisah
    
    printf("Masukan Input: "); // Memasukkan Input
    // scanf("%[^\n]", &input);

    // Menghilangkan spasi pada input
    int inputCount = 0;
    for (int i = 0; input[i]; i++)
        if (input[i] != ' ') // Kalau input yang ke i bukan spasi, 
            input[inputCount++] = input[i]; // Copy nilainya
    input[inputCount] = '\0';
    // Caranya yaitu mencopy nilai dari index ke i kalau nilainya bukan spasi
    // 13 + 17 * 2 - 11
    // ^ bukan spasi, copy 1 => input = 1
    // 13 + 17 * 2 - 11
    //  ^ bukan spasi, copy 3 => input = 13
    // 13 + 17 * 2 - 11
    //   ^ spasi, lewati
    // 13 + 17 * 2 - 11
    //    ^ bukan spasi, copy + => input = 13+
    // Dst
    // hingga input = 13+17*2-11
    
    // Program untuk memisah misah angka dan operator
    int numberStartIndex = 0;
    for (int i = 0; i < 512; i++){ // Looping di setiap input = 13+17*2-11
        if (!isdigit(input[i])){ // Kalau nilai dari index ke i bukan nomer, maka
            number[numberCount] = atoi(input + numberStartIndex); // Ambil angka mulai index ke numberStartIndex
            numberCount++; // Jumlah angka bertambah
            numberStartIndex = i + 1; // numberStartIndex berubah menjadi i+1
            
            if (input[i] == '\0') break; // Kalau sudah akhir dari input, maka keluar
            
            oper[operCount] = input[i]; // Ambil operator
            operCount++; // Jumlah operator bertambah

            if (!isdigit(input[i+1])) { // Ini cek untuk apakah nilai dari index selanjutnya adalah angka
                                        // Kalau bukan angka, berarti input tidak valid => keluar program
                printf("%d Invalid Input", i+1);
                return 0;
            }
        }
    }
    // Cara kerja, kalau nilai ke i itu angka, lewati
    // 13+17*2-11
    // ^ angka, lewati
    // 13+17*2-11
    //  ^ angka, lewati
    // 13+17*2-11
    //   ^ bukan angka maka
    //      number[0] = 13
    //      apakah nilai index ada ? nilai index = '+'
    //      ada! lanjutkan
    //      oper[0] = '+'
    //      cek apakah depan dari '+' adalah angka ?
    //      +17*2
    //       ^ angka, lanjutkan
    // 13+17*2-11
    //    ^ angka, lewati
    // 13+17*2-11
    //     ^ angka, lewati
    // 13+17*2-11
    //      ^ bukan angka maka
    //      number[1] = 17
    //      apakah nilai index ada ? nilai index = '*'
    //      ada! lanjutkan
    //      oper[1] = '*'
    //      cek apakah depan dari '*' adalah angka ?
    //      *2
    //       ^ angka, lanjutkan
    // dst
    // Sehingga didapatkan
    // number[] = {13, 17, 2, 11} => Jumlah ada 4 => numberCount = 4
    // oper[0] = {'+', '*', '-'} => Jumlah ada 3 => numberCount = 3

    // Program mencari perkalian dahulu
    for (int i = 0; i < operCount; i++){
        if (oper[i] == '*' || oper[i] == '/'){ // Jika nilai ke index itu * atau / maka
            if (oper[i] == '*')
                number[i] *= number[i+1];   // Number ke index itu dikali nilai depannya
            if (oper[i] == '/')
                number[i] /= number[i+1]; // Number ke index itu dibagi nilai depannya
            
            for (int j = i+1; j < 512; j++){ // Geser sisa angka dan operator
                number[j] = number[j+1];
                oper[j-1] = oper[j];
            }
            numberCount--;  // Karena sudah dilakukan perkalian, maka jumlah
            operCount--;    // number dan operator berkurang 1

            i--;    // Untuk mengecek operator ke index yang sama sprt sekarang
        }
    }
    // numer = {13, 17, 2, 11}
    // oper = {'+', '*', '-'}
    
    // {'+', '*', '-'}
    //   ^ bukan * atau /, lewati
    // {'+', '*', '-'}
    //        ^ nilai = * maka
    //          {13, 17, 2, 11} 17 * angka depannya => 17 * 2
    //          {13, 34, 2, 11} jadi seperti ini
    //          hapus nilai 2 dan geser ke kiri sisanya
    //          {13, 34, 11}
    //          hapus juga '*' dan geser ke kiri sisanya
    //          {'+', '-'} jadi seperti ini
    //          lanjut
    // {'+', '-'}       tetap check index yang sama, soalnya i--;
    //        ^ bukan * atau /, lewati
    // selesai
    // number = {13, 34, 11}
    // oper = {'+', '-'}

    int result = number[0];

    // Tinggal menambahkan dan mengurangi sisanya
    for (int i = 0; i < operCount; i++){
        switch (oper[i]){
        case '+':
            result += number[i+1];
            break;
        case '-':
            result -= number[i+1];
            break;
        default:
            printf("%d Invalid Input", i+1);
            return 0;
            break;
        }
    }
    // number = {13, 34, 11}
    // oper = {'+', '-'}
    // result = 13
    // oper +, maka
    // result = 13 + 34 = 47
    // oper -, maka
    // result = 47 - 11 = 36
    // Selesai

    // Cetak result
    printf("Result: %d\n", result);
    return 0;
}
