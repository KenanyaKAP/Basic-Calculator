# DISCLAIMER
> #### DIMOHON UNTUK MEMAHAMI KODE DAN TIDAK HANYA MENGCOPY-PASTE
> #### DIMOHON UNTUK MENGUBAH KODE SEBISA MUNGKIN AGAR TIDAK SAMA SATU DENGAN YANG LAIN
> #### SEGALA KEMIRIPAN KODE DITANGGUNG SENDIRI :D

## Bonus Poin
1. Bonus jika bisa menginputkan angka yang jumlah digitnya lebih dari 1. Contoh 11 + 2 + 123 = 136
2. Bonus jika bisa mengimplementasikan simbol kali “\*” dan bagi “/”. Contohnya   1 + 2 * 3 - 4 = 3. (ingat 2*3 dilakukan lebih dulu)
3. Bonus jika dapat mendeteksi apakah ekspresi yang dimasukan valid atau tidak. Contoh 2 + + 3 itu tidak valid

## Program
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char input[512] = "13 + 17 * 2 - 11";
    
    printf("Masukan Input: ");
    scanf("%[^\n]", &input);

    // Menghilangkan spasi pada input
    int inputCount = 0;
    for (int i = 0; input[i]; i++)
        if (input[i] != ' ')
            input[inputCount++] = input[i];
    input[inputCount] = '\0';
    
    // Program untuk memisah misah angka dan operator
    int number[512] = {0};
    char oper[512] = {'\0'};
    int numberCount = 0;
    int operCount = 0;
    int numberStartIndex = 0;
    for (int i = 0; i < 512; i++){
        if (!isdigit(input[i])){
            number[numberCount] = atoi(input + numberStartIndex);
            numberCount++;
            numberStartIndex = i + 1;
            
            if (input[i] == '\0') break;
            
            oper[operCount] = input[i];
            operCount++;

            if (!isdigit(input[i+1])) {
                printf("Invalid Input");
                return 0;
            }
        }
    }
    
    // Program mencari perkalian dahulu
    for (int i = 0; i < operCount; i++){
        if (oper[i] == '*' || oper[i] == '/'){
            if (oper[i] == '*')
                number[i] *= number[i+1];
            if (oper[i] == '/')
                number[i] /= number[i+1];
            
            for (int j = i+1; j < 512; j++){
                number[j] = number[j+1];
                oper[j-1] = oper[j];
            }
            numberCount--;
            operCount--;

            i--;
        }
    }


    // Tinggal menambahkan dan mengurangi sisanya
    int result = number[0];
    for (int i = 0; i < operCount; i++){
        switch (oper[i]){
        case '+':
            result += number[i+1];
            break;
        case '-':
            result -= number[i+1];
            break;
        default:
            printf("Invalid Input");
            return 0;
        }
    }

    // Cetak result
    printf("Result: %d\n", result);
    return 0;
}
```

## Penjelasan // Menghilangkan spasi pada input
```c
int inputCount = 0;
for (int i = 0; input[i]; i++)
    if (input[i] != ' ')
        input[inputCount++] = input[i];
input[inputCount] = '\0';
```
- Input pada awalnya akan memiliki spasi. Contohnya:
- `13 + 17 * 2 - 11`
- Program akan mengkopikan nilai dari index ke i bila nilai nya bukan spasi `' '`
```
13 + 17 * 2 - 11
^ bukan spasi, copy 1 => input = 1
13 + 17 * 2 - 11
 ^ bukan spasi, copy 3 => input = 13
13 + 17 * 2 - 11
  ^ spasi, lewati
13 + 17 * 2 - 11
   ^ bukan spasi, copy + => input = 13+
13 + 17 * 2 - 11
    ^ spasi, lewati
13 + 17 * 2 - 11
     ^ bukan spasi, copy 1 => input = 13+1
13 + 17 * 2 - 11
      ^ bukan spasi, copy 7 => input = 13+17
Dst
```
- hingga sekarang nilai input menjadi `13+17*2-11`

## Penjelasan // Program untuk memisah misah angka dan operator
```c
int number[512] = {0};
char oper[512] = {'\0'};
int numberCount = 0;
int operCount = 0;
int numberStartIndex = 0;
for (int i = 0; i < 512; i++){
    if (!isdigit(input[i])){
        number[numberCount] = atoi(input + numberStartIndex);
        numberCount++;
        numberStartIndex = i + 1;

        if (input[i] == '\0') break;

        oper[operCount] = input[i];
        operCount++;

        if (!isdigit(input[i+1])) {
            printf("Invalid Input");
            return 0;
        }
    }
}
```
- Setelah spasi dihilangkan, selanjutnya kita akan memisah-misahkan angka dan operator
- Disini juga akan sekaligus memvalidasi apakah inputan sesuai format
- Contoh inputan tidak valid yang bisa ditangkap
```
12 + + 34
42 + - 84
23 x 57
```
- Program akan melakukan perulangan pada setiap karakter pada variable input
- input = `13+17*2-11`
- Program akan berhenti bila karakter yang dicek bukanlah angka
- Cara untuk mengecek adalah dengan `isdigit()` fungsi yang terdapat pada library `<ctype.h>`
- Saat menemukan karakter yang bukan angka, maka program akan mengambil angka dibelakang karakter tersebut dan dimasukkan kedalam variable number
- Caranya dengan fungsi `atoi()` yang terdapat dalam library `<stdlib.h>`
- Dalam fungsi tersebut terdapat `input + numberStartIndex`. Fungsi akan mengambil angka pada string input. Dan `+ numberStartIndex` untuk menentukan dimulai dari index keberapakah input akan dibaca
```
Contoh
string = '12 + 34568 - 36'

atoi(string + 0)
12 + 34568 - 36
^
Membaca dari index ke 0, sehingga atoi mengeluarkan 12.

atoi(string + 4)
12 + 34568 - 36
    ^
Membaca dari index ke 4, sehingga atoi mengeluarkan 34568.
```
- Selanjutnya program akan mengecek apakah karakter yang didapat adalah `\0` yang berarti akhir atau ujung dari sebuah string.
- Kalau ya, maka keluar loop
- Kalau bukan `\0` maka ambil itu sebagai operator
- Dan selanjutnya program akan mengecek apakah karakter setelahnya ada angka, kalau bukan angka berarti input tidak valid. Karena setelah operator harus angka. Maka keluar.
```
Cara kerja: kalau nilai ke i itu angka, lewati
13+17*2-11
^ angka, lewati
13+17*2-11
 ^ angka, lewati
13+17*2-11
  ^ bukan angka maka
     number[0] = 13
     apakah '+' bukan '\0' ? 
     Bukan! lanjutkan
     oper[0] = '+'
     cek apakah depan dari '+' adalah angka ?
     +17*2
      ^ angka, lanjutkan
13+17*2-11
   ^ angka, lewati
13+17*2-11
    ^ angka, lewati
13+17*2-11
     ^ bukan angka maka
     number[1] = 17
     apakah '+' bukan '\0' ? 
     Bukan! lanjutkan
     oper[1] = '*'
     cek apakah depan dari '*' adalah angka ?
     *2-11
      ^ angka, lanjutkan
dst
Sehingga didapatkan
number[] = {13, 17, 2, 11} => Jumlah ada 4 => numberCount = 4
oper[] = {'+', '*', '-'} => Jumlah ada 3 => numberCount = 3
```

## Penjelasan // Program mencari perkalian dahulu
```c
for (int i = 0; i < operCount; i++){
    if (oper[i] == '*' || oper[i] == '/'){
        if (oper[i] == '*')
            number[i] *= number[i+1];
        if (oper[i] == '/')
            number[i] /= number[i+1];

        for (int j = i+1; j < 512; j++){
            number[j] = number[j+1];
            oper[j-1] = oper[j];
        }
        numberCount--;
        operCount--;

        i--;
    }
}
```
- Melakukan perulangan sebanyak jumlah operator (3)
- `oper[] = {'+', '*', '-'}`
- `number[] = {13, 17, 2, 11}`
- Cari hingga ketemu `*` atau `/`
- Setelah ketemu, maka kalikan atau bagikan angka pada index yang sama dengan `* atau /`, dengan angka didepannya
```
oper[] = {'+', '*', '-'}
                ^ index ke 1
number[] = {13, 17, 2, 11}
                ^ index ke 1
                Kalikan dengan angka depannya
                sehingga
number[] = {13, 34, 2, 11}
```
- Selanjutnya adalah menghapus angka yang sudah tidak dipakai. Dalam kasus ini adalah 2. Karena sudah dikalikan dengan 17 dan bergabung menjadi angka 34
- Dan juga jangan lupa menghapus operator * karena sudah dilakukan
- Caranya dengan menggeser nilai didepannya ke kiri
```
number[] = {13, 17, 2, 11}
                       ^ geser ke kiri
number[] = {13, 17, 11, 0}

oper[] = {'+', '*', '-'}
                     ^ geser ke kiri
oper[] = {'+', '-', ''}
```
- Sehingga akan menyisakan operasi `+ atau -` dan akan dieksekusi selanjutnya

## Penjelasan // Tinggal menambahkan dan mengurangi sisanya
```c
int result = number[0];
for (int i = 0; i < operCount; i++){
    switch (oper[i]){
    case '+':
        result += number[i+1];
        break;
    case '-':
        result -= number[i+1];
        break;
    default:
        printf("Invalid Input");
        return 0;
    }
}
```
- Buat variable result dengan variable awal adalah angka pertama
- Selanjutnya lakukan perulangan sebanyak operator yang tersisa
- `number[] = {13, 17, 11}`
- `oper[] = {'+', '-'}`
- Lalu lakukan penjumlahan atau pengurangan sesuai dengan operator yang didapatkan
- Disini juga terdapat pengecekan apabila operator yang ada bukan `+` atau `-` maka keluar dan cetak Invalid Input

## Dan yang terakhir adalah // Cetak result
```c
printf("Result: %d\n", result);
```

Selesai :D















