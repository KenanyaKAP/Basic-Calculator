// Bonus angka digit lebih dari 1
// Bonus perkalian pembagian
// Bonus deteksi tidak valid

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
