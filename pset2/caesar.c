/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet2(Ш++) pset2/caesar.c**
 * ****Шифрование по алгоритму Цезаря***
 * *************************************
 * ************************************/

/**************************************
 * *****Разбор задания ****************
****1. Получить ключ
****2. Получить текст
****3. Зашифровать
****4. Вывести на экран зашифрованный текст
***********************************/


#include <stdio.h>  // стандартная библиотека ввода вывода
#include <cs50.h>   // библиотека для cs50 IDE
#include <string.h> // для работы strlen()
#include <ctype.h>  // библиотека функций isaplha(), isupper(), islower() 

//==============================================================================
// прототипы функций
int GetKey          ( string argv[]);   // преобразование ключа из строки в целочисленную переменную  
string CaesarShifr  ( int keys );       // Шифр Цезаря
string getString    ( void );           // получение строки от пользователя
void displayCipher  ( string str );     // Вывод зашифрованного текста


//==============================================================================
// точка входа в программу
int main(int argc, string argv[])
{
    if (argc !=2) {                 // если количество аргументов с командной строки больше одного
                                    // инструкция по вызозу программы
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    int key = GetKey(argv);         // получаем корретный ключ
    string temp = CaesarShifr(key); // получаем преобразованную строку
    displayCipher(temp);            // выводим зашифрованную строку
}

//===========================================================================
// преобразование ключа из строки в целочисленную переменную
int GetKey(string argv[])
{
   return atoi(argv[1]);       // возвращает ключ для шифрации
}

//===========================================================================
// получение строки от пользователя
string getString()
{
    printf("plaintext:");
    return get_string();
}
//===========================================================================
// Шифр Цезаря
string CaesarShifr(int keys)
{
    string temp = getString();
    for(int i = 0; i < strlen(temp); i++ ){
        
        if (isalpha(temp[i])){
            
            if (isupper(temp[i]))                       // если вводимые символы будут пропис то
                temp[i] = ((temp[i]-65 + keys) % 26) + 65;
                
            if (islower(temp[i]))                       // если вводимые символы будут строчными то
                temp[i] =(( temp[i]-97 + keys )% 26) + 97;
        }     
    }
    return temp;                                        // возращает зашифрованную строку
}

//===========================================================================
// Вывод зашифрованного текста
void displayCipher (string str)
{
    printf("ciphertext:%s%s", str, "\n");
}
//===========================================================================