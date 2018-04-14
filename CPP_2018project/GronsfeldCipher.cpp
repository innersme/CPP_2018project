//
//  GronsfeldCipher.cpp
//  CPP_2018project
//
//  Created by MJMac on 12/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int findIntLength(int);
int* makeArrayofInt(int, int);
void GronsfeldCipher(int, char*, int, int*, int);

int main()
{
    int keySize = 0, strSize=0, select = 1;
    char str[50] = {0, };
    int key = 0;
    
    cout << "암호문 또는 평문을 입력: ";
    cin >> str;
    cout << "암호는 1번, 복호는 2번 선택";
    cin >> select;
    fflush(stdin);
    cout << "키 값 입력(4자): ";
    cin >> key;
    
    strSize = (int)strlen(str);
    keySize = findIntLength(key);
    int *keyArray = new int[keySize];
    keyArray = makeArrayofInt(key, keySize);
    
    GronsfeldCipher(select, str, strSize, keyArray, keySize);
    
    cout << "\n암호화 또는 복호화된 결과 출력: ";
    cout << str << endl;
    
    return 0;
    
}

int findIntLength(int inp){
    int cnt = 0;
    if (inp < 0) {
        return 0;
    }
    while (inp != 0) {
        inp /= 10;
        cnt++;
    }
    return cnt;
}

int* makeArrayofInt(int key, int keySize){
    int *res = new int[keySize];
    int i = keySize-1;
    while ( i > -1 ) {
        res[i] = key % 10;
        key = key / 10;
        i--;
    }
    return res;
}

void GronsfeldCipher(int select, char* str, int strSize, int* keyArray, int keySize )
{
    int i = 0 , j = 0;
    for (i = 0; i < strSize; i++) {
        // cycle control
        j = i % keySize;
        
        // Encryption
        if (select == 1) {
            // 소문자 일때,
            if ( (str[i] >= 'a') && (str[i] <= 'z')) {
                str[i] -= 'a';
                str[i] = ( str[i] + keyArray[j] ) % 26;
                str[i] += 'a';
            }
            // 대문자 일때,
            else if ( (str[i] >= 'A') && (str[i] <= 'A')) {
                str[i] -= 'A';
                str[i] = ( str[i] + keyArray[j] ) % 26;
                str[i] += 'A';
            }
        }
        
        // Decryption
        if (select == 2) {
            // 소문자 일때,
            if ( (str[i] >= 'a') && (str[i] <= 'z')) {
                str[i] -= 'a';
                if ( ( str[i] - keyArray[j] < 0)) {
                    str[i] += 26;
                }
                str[i] = ( str[i] - keyArray[j] ) % 26;
                str[i] += 'a';
            }
            // 대문자 일때,
            else if ( (str[i] >= 'A') && (str[i] <= 'Z')) {
                str[i] -= 'A';
                if ( ( str[i] - keyArray[j] < 0)) {
                    str[i] += 26;
                }
                str[i] = ( str[i] - keyArray[j] ) % 26;
                str[i] += 'A';
            }
        }
    }
}
