//
//  Feistel.c
//  CPP_2018project
//
//  Created by MJMacBook on 04/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <stdio.h>

const int BLOCK_SIZE = 6;
const int ROUND_NUM = 2;

char Feistel_Enc(char);
char Feistel_Dec(char);
int main()
{
    char p_bit = 0x2B;
    char c_bit, d_bit;
    int temp = 0, i = 0;
    
    printf("평문: ");
    for (i = BLOCK_SIZE-1; i >= 0 ; i--) {
        temp = (p_bit >> i) & 0x01;
        printf("%d", temp);
    }
    printf("\n");
    
    c_bit = Feistel_Dec(p_bit);
    
    printf("암호문: ");
    for (i = BLOCK_SIZE-1; i >= 0 ; i--) {
        temp = (c_bit >> i) & 0x01;
        printf("%d", temp);
    }
    printf("\n");
    
    d_bit = Feistel_Dec(c_bit);
    
    printf("복호문: ");
    for (i = BLOCK_SIZE-1; i >= 0 ; i--) {
        temp = (d_bit >> i) & 0x01;
        printf("%d", temp);
    }
    printf("\n");
    
    return 0;
}

char Feistel_Enc(char in)
{
    int i;
    char temp, left, right;
    
    left = (in >> 3) & 0x07;
    right = in & 0x07;
    
    for (i = 0; i < ROUND_NUM; i++) {
        if (i == 0) {
            left = left ^ F1
        }
    }
}
