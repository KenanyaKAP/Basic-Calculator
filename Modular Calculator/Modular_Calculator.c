// ================== Information ==================
// Semua kode dibawah ini sudah disiapkan modular
// Setiap modul bekerja satu dengan lainnya
// Bisa dipilih salah satu
// Jangan lupa hapus '//' kalo mau pake
// Dan hapus modul yang gak dipake
// =================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    char input[4096];
    printf("Input: ");

    // ========================= Modul Input string =========================
    
    scanf("%[^\n]%*c", input);                   // Modul 1
    // scanf("%[^\n]", input);                      // Modul 2
    // scanf("%[^\n]s", input);                     // Modul 3
    // scanf("%[^\n]%*c", &input);                  // Modul 4
    // scanf("%[^\n]", &input);                     // Modul 5
    // scanf("%[^\n]s", &input);                    // Modul 6

    // ======================================================================





    // ========================= Modul Hapus Spasi ==========================

    // Modul 1
    int inputCount = 0;
    for (int i = 0; input[i]; i++){
        if (input[i] != ' '){
            input[inputCount] = input[i];
            inputCount += 1;
        }
    }
    input[inputCount] = '\0';
    // End Modul 1

    // Modul 2
    // int i = 0, j = 0;
	// while (input[i]){
	//     if (input[i] != ' '){
    //         input[j] = input[i];
    //         j += 1;
    //     }
	// 	i += 1;
	// }
	// input[j] = '\0';
    // End Modul 2

    // Modul 3
    // for (int i = 0; input[i]; i++){
    //     if (input[i] == ' '){
    //         for (int j = i; j < strlen(input); j++){
    //             input[j] = input[j+1];
    //         }
    //         i -= 1;
    //     }
    // }
    // End Modul 3

    // Modul 4
    // int i = 0;
    // while (input[i]){
    //     if (input[i] == ' '){
    //         for (int j = i; j < strlen(input); j++){
    //             input[j] = input[j+1];
    //         }
    //     }
    //     else {
    //         i += 1;
    //     }
    // }
    // End Modul 4

    // ======================================================================





    // ======================== Modul Validasi Input ========================

    // Modul 1
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
    // End Modul 1
    
    // Modul 2
    // int i = 0; // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    // while (input[i]){
    //     if (!isdigit(input[i])){
    //         if (!isdigit(input[i+1]) || i == 0 || !(
    //             input[i] == '*' || input[i] == '/' || 
    //             input[i] == '+' || input[i] == '-' || 
    //             input[i] == '^')){
                    
    //             printf("Invalid Input!");
    //             return 0;
    //         }
    //     }
    //     i += 1;
    // }
    // End Modul 2

    // Modul 3
    // for (int i = 0; i < strlen(input); i++){
    //     if (!isdigit(input[i])){
    //         if (!isdigit(input[i+1]) || i == 0 || !(
    //             input[i] == '*' || input[i] == '/' || 
    //             input[i] == '+' || input[i] == '-' || 
    //             input[i] == '^')){
                    
    //             printf("Invalid Input!");
    //             return 0;
    //         }
    //     }
    // }
    // End Modul 3

    // Modul 4
    // char *inputPtr = input;
    // while (*inputPtr){
    //     if (!isdigit(*inputPtr)){
    //         if (!isdigit(*(inputPtr + 1)) || inputPtr == input || !(
    //             *inputPtr == '*' || *inputPtr == '/' || 
    //             *inputPtr == '+' || *inputPtr == '-' || 
    //             *inputPtr == '^')){
                    
    //             printf("Invalid Input!");
    //             return 0;
    //         }
    //     }
    //     inputPtr++;
    // }
    // End Modul 4

    // ======================================================================





    // ================== Modul Pemisah Angka dan Operator ==================

    // Modul 1
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
    // End Modul 1

    // Modul 2
    // int number[1024] = {0};
    // char operator[1024] = {'\0'};
    // int numberCount = 0;
    // int operatorCount = 0;
    // int startIndex = 0;
    // for (int i = 0; i < strlen(input); i++){
    //     if (i == strlen(input) - 1){
    //         number[numberCount++] = atoi(input + startIndex);
    //     }
    //     if (!isdigit(input[i])){
    //         operator[operatorCount++] = input[i];

    //         number[numberCount++] = atoi(input + startIndex);
    //         startIndex = i + 1;
    //     }
    // }
    // End Modul 2

    // Modul 3
    // int number[1024] = {0};
    // char operator[1024] = {'\0'};
    // int numberCount = 0;
    // int operatorCount = 0;
    // int startIndex = 0;
    // for (int i = 0; i < strlen(input) + 1; i++){
    //     if (!isdigit(input[i])){
    //         number[numberCount++] = atoi(input + startIndex);
    //         startIndex = i + 1;

    //         if (input[i] == '\0') break;

    //         operator[operatorCount++] = input[i];
    //     }
    // }
    // End Modul 3

    // Modul 4
    // int number[1024] = {0};
    // char operator[1024] = {'\0'};
    // char *inputPtr = input; // Kalau error, ganti "char *inputPtr = input" jadi "inputPtr = input" atau sebaliknya
    // int *numberPtr = number;
    // char *operatorPtr = operator;
    // int startIndex = 0;
    // while (*inputPtr){
    //     if (*(inputPtr + 1) == '\0'){
    //         *numberPtr++ = atoi(input + startIndex);
    //     }
    //     if (!isdigit(*inputPtr)){
    //         *operatorPtr++ = *inputPtr;

    //         *numberPtr++ = atoi(input + startIndex);
    //         startIndex = inputPtr - input + 1;
    //     }
    //     inputPtr += 1;
    // }
    // End Modul 4

    // Modul 5
    // int number[1024] = {0};
    // char operator[1024] = {'\0'};
    // char *inputPtr = input;
    // int *numberPtr = number;
    // char *operatorPtr = operator;
    // for (int i = 0; i < strlen(input) + 1; i++){
    //     if (!isdigit(input[i])){
    //         *numberPtr++ = atoi(inputPtr);
    //         inputPtr = input + i + 1;

    //         if (input[i] == '\0') break;
    //         *operatorPtr++ = input[i];
    //     }
    // }
    // End Modul 5

    // ======================================================================





    // ===================== Modul Operator Pangkat (^) =====================

    // Modul 1 (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
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
    // End Modul 1

    // Modul 2 (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
    // for (int i = operatorCount - 1; i >= 0; i--){
    //     if (operator[i] == '^'){
    //         number[i] = pow(number[i], number[i+1]);

    //         for (int j = i + 1; j < numberCount; j++){
    //             number[j] = number[j+1];
    //             operator[j-1] = operator[j];
    //         }
    //         numberCount -= 1;
    //         operatorCount -= 1;

    //         i += 1;
    //     }
    // }
    // End Modul 2

    // Modul 3 
    // int i = 1024; // Kalau error, ganti "int i = 1024;" jadi "i = 1024;" atau sebaliknya
    // while (i >= 0){
    //     if (operator[i] == '^'){
    //         number[i] = pow(number[i], number[i+1]);

    //         for (int j = i + 1; j < 1023; j++){
    //             number[j] = number[j+1];
    //             operator[j-1] = operator[j];
    //         }
    //     }
    //     else {
    //         i--;
    //     }
    // }
    // End Modul 3

    // ======================================================================





    // ================= Modul Operator Kali dan Bagi (* /) =================

    // Modul 1 (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
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
    // End Modul 1

    // Modul 2 (WAJIB menggunakan modul 1 / 2 / 3 pada Modul Pemisah Angka dan Operator)
    // for (int i = 0; i < operatorCount; i++){
    //     if (operator[i] == '*' || operator[i] == '/'){
    //         if (operator[i] == '*')
    //             number[i] = number[i] * number[i+1];
    //         else
    //             number[i] = number[i] / number[i+1];

    //         for (int j = i + 1; j < numberCount; j++){
    //             number[j] = number[j+1];
    //             operator[j-1] = operator[j];
    //         }
    //         numberCount -= 1;
    //         operatorCount -= 1;

    //         i -= 1;
    //     }
    // }
    // End Modul 2

    // Modul 3 
    // i = 0; // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    // while (operator[i]){
    //     if (operator[i] == '*' || operator[i] == '/'){
    //         if (operator[i] == '*')
    //             number[i] = number[i] * number[i+1];
    //         else
    //             number[i] = number[i] / number[i+1];

    //         for (int j = i + 1; j < 1023; j++){
    //             number[j] = number[j+1];
    //             operator[j-1] = operator[j];
    //         }
    //     }
    //     else {
    //         i++;
    //     }
    // }
    // End Modul 3

    // ======================================================================
    




    // ================ Modul Terakhir (+ -) dan Print Hasil ================

    // Modul 1
    int result = number[0];
    for (int i = 0; i < 1024; i++){
        if (operator[i] == '\0') break;

        if (operator[i] == '+')
            result += number[i+1];
        if (operator[i] == '-')
            result -= number[i+1];
    }
    printf("Result: %d", result);
    // End Modul 1

    // Modul 2
    // int result = number[0];
    // for (int i = 0; i < 1024; i++){
    //     if (operator[i] == '\0') break;

    //     switch (operator[i]){
    //     case '+':
    //         result += number[i+1];
    //         break;
    //     case '-':
    //         result -= number[i+1];
    //         break;
    //     }
    // }
    // printf("Result: %d", result);
    // End Modul 2

    // Modul 3
    // int result = number[0];
    // i = 0;  // Kalau error, ganti "int i = 0;" jadi "i = 0;" atau sebaliknya
    // while (operator[i]){
    //     if (operator[i] == '+')
    //         result += number[i+1];
    //     if (operator[i] == '-')
    //         result -= number[i+1];
    //     i += 1;
    // }
    // printf("Result: %d", result);
    // End Modul 3

    // ======================================================================
    
    return 0;
}
