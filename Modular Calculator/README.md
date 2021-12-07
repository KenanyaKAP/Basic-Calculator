# DISCLAIMER
> #### DIMOHON UNTUK MEMAHAMI KODE DAN TIDAK HANYA MENGCOPY-PASTE
> #### DIMOHON UNTUK MENGUBAH KODE SEBISA MUNGKIN AGAR TIDAK SAMA SATU DENGAN YANG LAIN
> #### SEGALA KEMIRIPAN KODE DITANGGUNG SENDIRI :D

## Bonus Poin
Bonus Poin pada kalkulator modular bisa bervariasi mulai dari 1 - 4 tergantung dari modul mana yang dipakai
1. Bonus jika bisa menginputkan angka yang jumlah digitnya lebih dari 1. Contoh 11 + 2 + 123 = 136
2. Bonus jika bisa mengimplementasikan simbol kali “\*” dan bagi “/”. Contohnya   1 + 2 * 3 - 4 = 3. (ingat 2*3 dilakukan lebih dulu)
3. Bonus jika bisa menggunakan simbol ^ untuk menandakan tanda pangkat. Contoh 2 ^ 9 + 1 = 513 (harus bisa melakukan perkalian juga)
4. Bonus jika dapat mendeteksi apakah ekspresi yang dimasukan valid atau tidak. Contoh 2 + + 3 itu tidak valid

## How To Use
- Program kalkulator ini sudah disiapkan modular
- Tinggal pilih salah satu secara bebas dari setiap modul
- Setiap modul diprogram untuk bisa bekerja satu dengan lainnya
- Kalkulator minimal harus ada `Modul Input string`, `Modul Hapus Spasi`, `Modul Pemisah Angka dan Operator`, dan `Modul Terakhir (+ -) dan Print Hasil`
- Selebihnya bisa dipakai atau tidak, sesuai dengan nilai yang ingin didapat :v (Jangan lupa kalau pakai modul juga dipahami)
- Secara minimal, kalkulator sudah bisa mendapatkan 1 Bonus yaitu input lebih dari 1 digit

## Base Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    char input[4096];
    
    // Modul Input string
    
    // Modul Hapus Spasi
    
    // Modul Validasi Input
    
    // Modul Pemisah Angka dan Operator
    
    // Modul Operator Pangkat (^)
    
    // Modul Operator Kali dan Bagi (* /)
    
    // Modul Terakhir (+ -) dan Print Hasil
    
    return 0;
}
```

## Modul Input string
```c
scanf("%[^\n]%*c", input);                   // Modul 1
scanf("%[^\n]", input);                      // Modul 2
scanf("%[^\n]s", input);                     // Modul 3
scanf("%[^\n]%*c", &input);                  // Modul 4
scanf("%[^\n]", &input);                     // Modul 5
scanf("%[^\n]s", &input);                    // Modul 6
```
- Berbagai cara untuk menangkap inputan dari user
- Tidak perlu penjelasan

## Modul Hapus Spasi
### 1.
```c
int inputCount = 0;
for (int i = 0; input[i]; i++){
    if (input[i] != ' '){
        input[inputCount] = input[i];
        inputCount += 1;
    }
}
input[inputCount] = '\0';
```
- Penjelasan:
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

### 2.
```c
int i = 0, j = 0;
while (input[i]){
    if (input[i] != ' '){
        input[j] = input[i];
        j += 1;
    }
    i += 1;
}
input[j] = '\0';
```
- Penjelasan:
- Sama dengan [modul 1](https://github.com/KenanyaKAP/Basic-Calculator/new/main#1) hanya saja menggunakan versi while
- Bisa dicoba juga untuk membuat versi sendiri

### 3.
```c
for (int i = 0; input[i]; i++){
    if (input[i] == ' '){
        for (int j = i; j < strlen(input); j++){
            input[j] = input[j+1];
        }
        i -= 1;
    }
}
```
- Penjelasan:
- Berkebalikan dengan modul sebelumnya, modul ini mencari spasi `' '`.
- Bila mendapatkan spasi, maka akan menggeser karakter setelah nya ke kiri
- Dengan `input[j] = input[j+1];`
```
13 +  17 * 2 - 11
^ bukan spasi, lanjut
13 +  17 * 2 - 11
 ^ bukan spasi, lanjut
13 +  17 * 2 - 11
  ^ spasi, lakukan pergeseran ke kiri sehingga menjadi
13+  17 * 2 - 11
  ^ bukan spasi, lanjut
13+  17 * 2 - 11
   ^ spasi, lakukan pergeseran ke kiri sehingga menjadi
13+ 17 * 2 - 11
   ^ masih spasi, geser ke kiri
13+17 * 2 - 11
   ^ bukan spasi, lanjut
Dst
```
- hingga sekarang nilai input menjadi `13+17*2-11`

### 4.
```c
int i = 0;
while (input[i]){
    if (input[i] == ' '){
        for (int j = i; j < strlen(input); j++){
            input[j] = input[j+1];
        }
    }
    else {
        i += 1;
    }
}
```
- Penjelasan:
- Sama dengan [modul 3](https://github.com/KenanyaKAP/Basic-Calculator/new/main#3) hanya saja menggunakan versi while
- Bisa dicoba juga untuk membuat versi sendiri

## Modul Validasi Input






### 1.
```c
```
- Penjelasan:
