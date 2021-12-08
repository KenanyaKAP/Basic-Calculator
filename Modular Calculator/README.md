# DISCLAIMER
> #### DIMOHON UNTUK MEMAHAMI KODE DAN TIDAK HANYA MENGCOPY-PASTE
> #### DIMOHON UNTUK MENGUBAH KODE SEBISA MUNGKIN AGAR TIDAK SAMA SATU DENGAN YANG LAIN
> #### SEGALA KEMIRIPAN KODE DITANGGUNG SENDIRI :D

# Bonus Poin
Bonus Poin pada kalkulator modular bisa bervariasi mulai dari 1 - 4 tergantung dari modul mana yang dipakai
1. Bonus jika bisa menginputkan angka yang jumlah digitnya lebih dari 1. Contoh 11 + 2 + 123 = 136
2. Bonus jika bisa mengimplementasikan simbol kali “\*” dan bagi “/”. Contohnya   1 + 2 * 3 - 4 = 3. (ingat 2*3 dilakukan lebih dulu)
3. Bonus jika bisa menggunakan simbol ^ untuk menandakan tanda pangkat. Contoh 2 ^ 9 + 1 = 513 (harus bisa melakukan perkalian juga)
4. Bonus jika dapat mendeteksi apakah ekspresi yang dimasukan valid atau tidak. Contoh 2 + + 3 itu tidak valid

# How To Use
- Program kalkulator ini sudah disiapkan modular
- Tinggal pilih salah satu secara bebas dari setiap modul
- Setiap modul diprogram untuk bisa bekerja satu dengan lainnya
- Kalkulator minimal harus ada `Modul Input string`, `Modul Hapus Spasi`, `Modul Pemisah Angka dan Operator`, dan `Modul Terakhir (+ -) dan Print Hasil`
- Selebihnya bisa dipakai atau tidak, sesuai dengan nilai yang ingin didapat :v (Jangan lupa kalau pakai modul juga dipahami)
- Secara minimal, kalkulator sudah bisa mendapatkan 1 Bonus yaitu input lebih dari 1 digit

# Base Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    char input[4096];
    printf("Input: ");
    
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

# Modul Input string
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

# Modul Hapus Spasi
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

# Modul Validasi Input
### 1.
```c
    int isNumber = 0;
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            isNumber = 1;
        }
        else {
            if (!(input[i] == '+' || input[i] == '-' || 
                input[i] == '*' || input[i] == '/' || 
                input[i] == '^' )){
                printf("Invalid Input!");
                return 0;
            }
            if (isNumber){
                isNumber = 0;
            }
            else{
                printf("Invalid Input!");
                return 0;
            }
        }
    }
```
- Penjelasan:
- Pertama membuat variable yaitu `isNumber` sebagai boolean atau variable yang bernilai 1 atau 0 untuk menunjukkan `True` or `False`
- Selanjutnya program akan melakukan perulangan ke setiap karakter pada inputan yang sudah dihapus spasinya tadi
- Lalu mengecek apakah karakter tersebut adalah angka, dengan menggunakan `isdigit(input[i])`. `isdigit()` adalah fungsi dari library `<ctype.h>` yakni untuk mengecek apakah sebuah karakter adalah angka. Contohnya `isdigit('3')` mengeluarkan True. Perlu diperhatikan bahwa `'3'` disini bukan bertipe integer, melainkan char.
- Lanjut, kalau ternyata itu isgidit menghasilkan True, maka akan membuat variable isNumber menjadi 1 (True).
- Namun kalau ternyata karakter bukan sebuah angka, maka cek kembali apakah karakter itu adalah antara `'+', '-', '*', '/', '^'`. Karena kalau bukan, maka cetak Invalid Input.
- Lalu selanjutnya ada `if(isNumber) isNumber = 0; else Invalid Input` yakni bila kita sudah menjumpai sebuah operator, tapi setelah itu masih ada operator lain `1 + + 1`, maka cetak Invalid Input. Karena setelah operator haruslah angka.
```
13+17--2
^ angka, isNumber = 1
13+17--2
 ^ angka, isNumber = 1
13+17--2
  ^ bukan angka
  cek apakah operator valid? Valid! Lanjutkan
  if (isNumber) // isNumber terakhir bernilai 1 maka true
    isNumber = 0
13+17--2
   ^ angka, isNumber = 1
13+17--2
    ^ angka, isNumber = 1
13+17--2
     ^ bukan angka
     cek apakah operator valid? Valid! Lanjutkan
     if (isNumber) // isNumber terakhir bernilai 1 maka true
       isNumber = 0
13+17--2
      ^ bukan angka
      cek apakah operator valid? Valid! Lanjutkan
      if (isNumber) // isNumber terakhir bernilai 0 maka false
        printf("Invalid Input");
```

### 2.
```c
    int i = 0; // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    while (input[i]){
        if (!isdigit(input[i])){
            if (!isdigit(input[i+1]) || i == 0 || !(
                input[i] == '*' || input[i] == '/' || 
                input[i] == '+' || input[i] == '-' || 
                input[i] == '^')){

                printf("Invalid Input!");
                return 0;
            }
        }
        i += 1;
    }
```
- Penjelasan:
- Cara kerja hampir mirip dengan sebelumnya, hanya saja ini menggunakan while
- Dan juga langsung mengecek 2 karakter sekaligus
- Bila program menemukan karakter bukan angka, maka cek juga karakter didepannya apakah angka. Kalau bukan angka maka cetak Invalid Input
```
13+17--2
^ angka, skip
13+17--2
 ^ angka, skip
13+17--2
  ^ bukan angka
  cek apakah depannya angka ?
  +17--2
   ^
   ternyata angka, skip
13+17--2
   ^ angka, skip
13+17--2
    ^ angka, skip
13+17--2
     ^ bukan angka
     cek apakah depannya angka ?
     --2
      ^
      ternyata bukan angka, Invalid Input
```

### 3.
```c
    for (int i = 0; i < strlen(input); i++){
        if (!isdigit(input[i])){
            if (!isdigit(input[i+1]) || i == 0 || !(
                input[i] == '*' || input[i] == '/' || 
                input[i] == '+' || input[i] == '-' || 
                input[i] == '^')){

                printf("Invalid Input!");
                return 0;
            }
        }
    }
```
- Penjelasan:
- Sama persis dengan [Modul 2](https://github.com/KenanyaKAP/Basic-Calculator/blob/main/Modular%20Calculator/README.md#2-1)
- Hanya saja menggunakan perulangan for
- Bisa dicoba untuk mengganti-ganti sesuai versi sendiri

### 4.
```c
    char *inputPtr = input;
    while (*inputPtr){
        if (!isdigit(*inputPtr)){
            if (!isdigit(*(inputPtr + 1)) || inputPtr == input || !(
                *inputPtr == '*' || *inputPtr == '/' || 
                *inputPtr == '+' || *inputPtr == '-' || 
                *inputPtr == '^')){

                printf("Invalid Input!");
                return 0;
            }
        }
        inputPtr++;
    }
```
- Penjelasan:
- Cara kerja masih sama dengan [Modul 2](https://github.com/KenanyaKAP/Basic-Calculator/blob/main/Modular%20Calculator/README.md#2-1) dan [Modul 3](https://github.com/KenanyaKAP/Basic-Calculator/blob/main/Modular%20Calculator/README.md#3-1), hanya saja ini menggunakan cara pointer
- Sedikit lebih susah karena harus memahami konsep pointer, memory, dan dereferencing
- Jika ingin memahami lebih lanjut mengenai pointer, silahkan lihat [video ini](https://www.youtube.com/watch?v=h-HBipu_1P0).

# Modul Pemisah Angka dan Operator
### 1.
```c
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    int numberCount = 0;
    int operatorCount = 0;
    int startIndex = 0;
    for (int i = 0; i < strlen(input); i++){
        if (i == strlen(input) - 1){
            number[numberCount] = atoi(input + startIndex);
            numberCount += 1;
        }
        if (!isdigit(input[i])){
            operator[operatorCount] = input[i];
            operatorCount += 1;

            number[numberCount] = atoi(input + startIndex);
            numberCount += 1;

            startIndex = i + 1;
        }
    }
```
- Penjelasan:
- Karena kita akan memisahkan semua angka dan operator, maka pertama-tama kita harus membuat variable array int number, dan char operator. Dan juga diperlukan 3 variable pendukung yaitu numberCount yaitu jumlah angka, operatorCount yaitu jumlah operator, dan startIndex yang akan dijelaskan nanti
- Program akan melakukan perulangan pada setiap karakter pada variable input (Fokus terlebih dahulu pada percabangan if yang kedua)
- Contoh `input = 13+17*2-11`
- Program akan berhenti bila karakter yang dicek bukanlah angka
- Cara masih sama yaitu dengan `isdigit()`
- Saat menemukan karakter yang bukan angka, maka program akan mengambil karakter itu dan ditaruh ke dalam `operator` dan jumlahnya bertambah 1.
- Lalu angka dibelakang karakter tersebut dan dimasukkan kedalam variable `number`
- Caranya dengan fungsi `atoi()` yang terdapat dalam library `<stdlib.h>`
- Dalam fungsi tersebut terdapat `input + startIndex`. Fungsi akan mengambil angka pada string input. Dan `+ startIndex` untuk menentukan dimulai dari index keberapakah input akan dibaca
```
Contoh
string = '12+68-36'

atoi(string + 0)
12+68-36
^
Membaca dari index ke 0, sehingga atoi mengeluarkan 12 saja. Karena didepan angka 2 terpadat karakter yang bukan angka lagi.

atoi(string + 4)
12+68-36
    ^
Membaca dari index ke 4, sehingga atoi hanya mengeluarkan 8. Karena dimulai dari index ke 4, dan didepan angka 8 sudah bukan angka lagi
```
- `startIndex` lah yang berfungsi sebagai penentu `atoi()` untuk membaca dari index ke berapa.
- `startIndex` diisi dengan `i + 1` karena i adalah perulangan index sehingga bisa menentukan index ke berapa `atoi()` akan membaca.
- Lalu perhatikan lagi untuk percabangan if yang pertama. Percabangan ini digunakan untuk mengecek apakah i adalah index terakhir dari input. Kalau iya, maka ambil nomor terakhir dengan cara yang sama. Dan sebaiknya percabangan ini ditaruh diatas untuk mengecek terlebih dahulu apakah i adalah akhir dari index
- Dari sini kita sudah bisa memisah-misahkan angka dan operator yang dimasukkan user

### 2.
```c
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    int numberCount = 0;
    int operatorCount = 0;
    int startIndex = 0;
    for (int i = 0; i < strlen(input); i++){
        if (i == strlen(input) - 1){
            number[numberCount++] = atoi(input + startIndex);
        }
        if (!isdigit(input[i])){
            operator[operatorCount++] = input[i];

            number[numberCount++] = atoi(input + startIndex);
            startIndex = i + 1;
        }
    }
```
- Penjelasan:
- Cara kerja masih sama persis dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-2), hanya saja dipersingkat yakni `number[numberCount++]` dan `operator[operatorCount++]`
- Itu adalah cara praktis untuk menambahkan variable numberCount dengan 1 sekaligus menggunakan nilai numberCount
```
Contoh:
numberCount = 0

number[numberCount++] = 31
             v
            number[0] = 31
        dan numberCount++;
sehingga sekarang 
numberCount = 1

number[numberCount++] = 12
             v
            number[1] = 12
        dan numberCount++;
sehingga sekarang 
numberCount = 2

Dst
```

### 3.
```c
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    int numberCount = 0;
    int operatorCount = 0;
    int startIndex = 0;
    for (int i = 0; i < strlen(input) + 1; i++){
        if (!isdigit(input[i])){
            number[numberCount++] = atoi(input + startIndex);
            startIndex = i + 1;

            if (input[i] == '\0') break;

            operator[operatorCount++] = input[i];
        }
    }
```
- Penjelasan:
- Secara keseluruhan hampir sama dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-2) dan [Modul 2](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#2-2), namun disini lebih diringkas lagi yaitu dengan melakukan perulangan lebih 1 kali
- `i < strlen(input) + 1;`
- Tujuannya adalah untuk menggantikan `if (i == strlen(input) - 1)` apakah i adalah index terakhir
- Cara kerjanya program akan mengambil nomor terlebih dahulu, lalu mengecek apakah karakter ke i adalah `'\0'` alias `Enter`. Kalau ya, maka keluar loop dan tidak perlu mengambil operator

### 4.
```c
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    char *inputPtr = input; // Kalau error, ganti "char *inputPtr = input" jadi "inputPtr = input" atau sebaliknya
    int *numberPtr = number;
    char *operatorPtr = operator;
    int startIndex = 0;
    while (*inputPtr){
        if (*(inputPtr + 1) == '\0'){
            *numberPtr++ = atoi(input + startIndex);
        }
        if (!isdigit(*inputPtr)){
            *operatorPtr++ = *inputPtr;

            *numberPtr++ = atoi(input + startIndex);
            startIndex = inputPtr - input + 1;
        }
        inputPtr += 1;
    }
```
- Penjelasan:
- Sama dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-2) dan [Modul 2](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#2-2), namun menggunakan while
- Bisa dicoba juga untuk membuat versi sendiri

### 5.
```c
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    char *inputPtr = input;
    int *numberPtr = number;
    char *operatorPtr = operator;
    for (int i = 0; i < strlen(input) + 1; i++){
        if (!isdigit(input[i])){
            *numberPtr++ = atoi(inputPtr);
            inputPtr = input + i + 1;

            if (input[i] == '\0') break;
            *operatorPtr++ = input[i];
        }
    }
```
- Penjelasan:
- - Sama dengan [Modul 3](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#3-2), namun menggunakan while
- Bisa dicoba juga untuk membuat versi sendiri

# Modul Operator Pangkat (^)
### 1. (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
```c
    for (int i = operatorCount - 1; i >= 0; i--){
        if (operator[i] == '^'){
            number[i] = pow(number[i], number[i+1]);

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
            }
            for (int j = i; j < operatorCount; j++){
                operator[j] = operator[j+1];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i += 1;
        }
    }
```
- Penjelasan:
- Modul ini digunakan untuk pengoperasian pangkat
- Pertama lakukan loop pada `operator` karena kita akan mengecek operator pangkat `'^'`
- Perlu diingat bahwa pangkat itu dikerjakan dari belakang
- Contoh 2 ^ 2 ^ 3, maka 2 ^ (2 ^ 3) dilakukan dahulu menjadi 2 ^ 8 dan menjadi 256
- Maka dari itu loopnya dimulai dari `operatorCount - 1` hingga `i >= 0` dan i decrement.
- Selanjutnya lakukan pengecekan apakah operator adalah `'^'`
- Kalau ya, maka pangkatkan `number` dari index yang sama dengan angka didepannya. 
- Lalu jika sudah, tinggal menghapus angka yang sudah di pangkatkan.
- Caranya adalah dengan menggeser angka disebelahnya ke kiri
- Dan juga menggeser operator
```
Contoh input: 2 ^ 3 + 4 * 3

Sudah dipecah menjadi:
number {2, 3, 4, 3}
        0  1  2  3        <= index
operator {'^', '+', '*'}
           0    1    2    <= index

Cari '^' dari belakang
{'^', '+', '*'}
            ^ bukan pangkat
{'^', '+', '*'}
       ^ bukan pangkat
{'^', '+', '*'}
  ^ pangkat. Index ke 0
  Pangkatkan number index ke 0 dengan depannya
  
number {2, 3, 4, 3}
        0  1  2  3        <= index
        ^ 
        2 pangkatkan dengan depannya (3)
      = 8
        v
number {8, 3, 4, 3}

Selanjutnya hapus angka yang sudah dipangkatkan (3) dengan geser ke kiri
number {8, 3, 4, 3}
              ^  ^
              geser ke kiri
number {8, 4, 3, 0}
           ^  ^

Operator juga
{'^', '+', '*'}
       ^    ^
       geser ke kiri
{'+', '*', ''}

Lalu jangan lupa untuk mengurangi numberCount dan operatorCount karena pangkat sudah bergabung
```

### 2. (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
```c
    for (int i = operatorCount - 1; i >= 0; i--){
        if (operator[i] == '^'){
            number[i] = pow(number[i], number[i+1]);

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
                operator[j-1] = operator[j];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i += 1;
        }
    }
```
- Penjelasan:
- Sama persis dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-wajib-menggunakan-modul-1--2--3-pada-modul-pemisah-angka-dan-operator). Hanya saja dalam menghapus / menggeser `number` dan `operator` dilakukan dalam loop yang sama
- Hanya memperingkas kode
- Bisa dicoba juga untuk membuat versi sendiri

### 3.
```c
    int i = 1024; // Kalau error, ganti "int i = 1024;" jadi "i = 1024;" atau sebaliknya
    while (i >= 0){
        if (operator[i] == '^'){
            number[i] = pow(number[i], number[i+1]);

            for (int j = i + 1; j < 1023; j++){
                number[j] = number[j+1];
                operator[j-1] = operator[j];
            }
        }
        else {
            i--;
        }
    }
```
- Penjelasan:
- Sama dengan [Modul 2](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#2-wajib-menggunakan-modul-1--2--3-pada-modul-pemisah-angka-dan-operator) tapi menggunakan loop while
- Bisa dicoba juga untuk membuat versi sendiri

# Modul Operator Kali dan Bagi (* /)
- Cara kerja dari operator Kali dan Bagi ini sama persis dengan [Modul Pangkat](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#modul-operator-pangkat-)
- Yang membedakan hanya loop dimulai dari depan, dan bukan dari belakang
- Selebihnya logika kerja program sama persis

### 1. (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
```c
    for (int i = 0; i < operatorCount; i++){
        if (operator[i] == '*' || operator[i] == '/'){
            if (operator[i] == '*')
                number[i] = number[i] * number[i+1];
            else
                number[i] = number[i] / number[i+1];

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
            }
            for (int j = i; j < operatorCount; j++){
                operator[j] = operator[j+1];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i -= 1;
        }
    }
```

### 2. (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
```c
    for (int i = 0; i < operatorCount; i++){
        if (operator[i] == '*' || operator[i] == '/'){
            if (operator[i] == '*')
                number[i] = number[i] * number[i+1];
            else
                number[i] = number[i] / number[i+1];

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
                operator[j-1] = operator[j];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i -= 1;
        }
    }
```

### 3.
```c
    i = 0; // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    while (operator[i]){
        if (operator[i] == '*' || operator[i] == '/'){
            if (operator[i] == '*')
                number[i] = number[i] * number[i+1];
            else
                number[i] = number[i] / number[i+1];

            for (int j = i + 1; j < 1023; j++){
                number[j] = number[j+1];
                operator[j-1] = operator[j];
            }
        }
        else {
            i++;
        }
    }
```

# Modul Terakhir (+ -) dan Print Hasil
### 1.
```c
    int result = number[0];
    for (int i = 0; i < 1024; i++){
        if (operator[i] == '\0') break;

        if (operator[i] == '+')
            result += number[i+1];
        if (operator[i] == '-')
            result -= number[i+1];
    }
    printf("Result: %d", result);
```
- Penjelasan:
- Modul ini digunakan untuk menghintung hasil akhir, yaitu hanya operator `'+'` dan `'-'`
- Caranya adalah membuat variable result terlebih dahulu, dan diinisialisasi dengan angka awal `number[0]`
- Sealnjutnya akan melakukan perulangan
- Lalu lakukan perhitungan sesuai dengan operator yang sudah ada
- Juga terdapat `if (operator[i] == '\0') break;` di paling atas yaitu untuk mengecek apabila operator sudah kosong `'\0'`, maka bisa keluar loop
- Paling akhir adalah tinggal mencetak `result` dan selesai

### 2.
```c
    int result = number[0];
    for (int i = 0; i < 1024; i++){
        if (operator[i] == '\0') break;

        switch (operator[i]){
        case '+':
            result += number[i+1];
            break;
        case '-':
            result -= number[i+1];
            break;
        }
    }
    printf("Result: %d", result);
```
- Penjelasan:
- Sama persis dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-3) hanya saja menggunakan switch case
- Bisa dicoba juga untuk membuat versi sendiri

### 3.
```c
    int result = number[0];
    i = 0;  // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    while (operator[i]){
        if (operator[i] == '+')
            result += number[i+1];
        if (operator[i] == '-')
            result -= number[i+1];
        i += 1;
    }
    printf("Result: %d", result);
```
- Penjelasan:
- Sama dengan [Modul 1](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#1-3) tapi disini menggunakan while dengan yang dicek adalah `operator[i]`. `operator[i]` akan bernilai 1 (True) bila operator memiliki nilai, namun akan 0 (False) bilai nilai operator adalah kosong `'\0'`
- Bisa dicoba juga untuk membuat versi sendiri



# Contoh Penggunaan
Sebagai contoh, akan digunakan modul pertama pada setiap modul. Sehingga kalkulator sudah lengkap dengan 4 bonus. Modul yang dipasang harus berurutan sesuai dengan [Base Code](https://github.com/KenanyaKAP/Basic-Calculator/tree/main/Modular%20Calculator#base-code)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    char input[4096];
    printf("Input: ");
    
    // Modul Input string 1
    scanf("%[^\n]%*c", input);
    
    // Modul Hapus Spasi 1
    int inputCount = 0;
    for (int i = 0; input[i]; i++){
        if (input[i] != ' '){
            input[inputCount] = input[i];
            inputCount += 1;
        }
    }
    input[inputCount] = '\0';
    
    // Modul Validasi Input 1
    int isNumber = 0;
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            isNumber = 1;
        }
        else {
            if (!(input[i] == '+' || input[i] == '-' || 
                input[i] == '*' || input[i] == '/' || 
                input[i] == '^' )){
                printf("Invalid Input!");
                return 0;
            }
            if (isNumber){
                isNumber = 0;
            }
            else{
                printf("Invalid Input!");
                return 0;
            }
        }
    }
    
    // Modul Pemisah Angka dan Operator 1
    int number[1024] = {0};
    char operator[1024] = {'\0'};
    int numberCount = 0;
    int operatorCount = 0;
    int startIndex = 0;
    for (int i = 0; i < strlen(input); i++){
        if (i == strlen(input) - 1){
            number[numberCount] = atoi(input + startIndex);
            numberCount += 1;
        }
        if (!isdigit(input[i])){
            operator[operatorCount] = input[i];
            operatorCount += 1;

            number[numberCount] = atoi(input + startIndex);
            numberCount += 1;

            startIndex = i + 1;
        }
    }
    
    // Modul Operator Pangkat (^) 1
    for (int i = operatorCount - 1; i >= 0; i--){
        if (operator[i] == '^'){
            number[i] = pow(number[i], number[i+1]);

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
            }
            for (int j = i; j < operatorCount; j++){
                operator[j] = operator[j+1];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i += 1;
        }
    }
    
    // Modul Operator Kali dan Bagi (* /) 1
    for (int i = 0; i < operatorCount; i++){
        if (operator[i] == '*' || operator[i] == '/'){
            if (operator[i] == '*')
                number[i] = number[i] * number[i+1];
            else
                number[i] = number[i] / number[i+1];

            for (int j = i + 1; j < numberCount; j++){
                number[j] = number[j+1];
            }
            for (int j = i; j < operatorCount; j++){
                operator[j] = operator[j+1];
            }
            numberCount -= 1;
            operatorCount -= 1;

            i -= 1;
        }
    }
    
    // Modul Terakhir (+ -) dan Print Hasil 1
    int result = number[0];
    for (int i = 0; i < 1024; i++){
        if (operator[i] == '\0') break;

        if (operator[i] == '+')
            result += number[i+1];
        if (operator[i] == '-')
            result -= number[i+1];
    }
    printf("Result: %d", result);
    
    return 0;
}
```

#### That's it from me, hope can help you guys :D
