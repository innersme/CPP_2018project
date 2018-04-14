//
//  Affinecipther.c
//  CPP_2018project
//
//  Created by MJMac on 12/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <stdio.h>

const int KEYONE = 12;
const int KEYTWO = 8;


char *AffineCipther (char *, int, int, int);
char *DAffineCipther (char *, int, int, int);

int main()
{
    const int STR_LENGTH = 12;
    char str[STR_LENGTH] = "AFFINECIPHER";
    
    
    AffineCipther(str, STR_LENGTH, KEYONE, KEYTWO);
    printf("%s", str);
    DAffineCipther(str, STR_LENGTH, KEYONE, KEYTWO);
    printf("%s", str);
    
    return 0;
}

char *AffineCipther(char *str, int str_size, int keyone, int keytwo)
{
    int i; int tmp;
    
    for (i = 0 ; i < str_size; i++) {
        // 대문자를 입력받음
        if ( (str[i] >= 'A') && (str[i] <= 'Z') ) {
            str[i] -= 'A';
            
            tmp = keyone * str[i] + keytwo;
            
            while (tmp < 0) {
                tmp += 26;
            }
            
            str[i] = tmp % 26;
            str[i] += 'A';
        }
        // 소문자를 입력받음
        else if ( (str[i] >='a') && (str[i] <= 'z') ){
            str[i] -= 'a';
            
            tmp = keyone * str[i] + keytwo;
            
            while ( tmp < 0) {
                tmp += 26;
            }
            str[i] = tmp % 26;
            str[i] += 'a';
        }
        // 문자가 아니라면 아무것도 하지않는다.
        else ;
    }
    return str;
}

char *DAffineCipther (char *str, int str_size, int keyone, int keytwo)
{
    int i; int tmp;
    
    for (i = 0 ; i < str_size; i++) {
        // 대문자를 입력받음
        if ( (str[i] >= 'A') && (str[i] <= 'Z') ) {
            str[i] -= 'A';
            
            // 원함수의 역
            tmp = ( 26 - keyone ) * ( str[i] - keytwo );
            
            while (tmp < 0) {
                tmp += 26;
            }
            
            str[i] = tmp % 26;
            str[i] += 'A';
        }
        // 소문자를 입력받음
        else if ( (str[i] >='a') && (str[i] <= 'z') ){
            str[i] -= 'a';
            
            tmp = ( 26 - keyone ) * ( str[i] - keytwo );
            
            while ( tmp < 0) {
                tmp += 26;
            }
            str[i] = tmp % 26;
            str[i] += 'a';
        }
        // 문자가 아니라면
        else ;
    }
    return str;
}

