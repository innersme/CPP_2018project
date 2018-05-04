//
//  DES.c
//  CPP_2018project
//
//  Created by MJMacBook on 04/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <stdio.h>
#include "IPIIP.h"

void IP(BYTE *in, BYTE *out);
void IIP(BYTE *in, BYTE *out);
void BtoW(BYTE, UNIT, UNIT);

int main()
{
    BYTE Ptext[8] = {"abdcdef\0"};
    BYTE Ctext[8];
    BYTE PPText[8];
    IP(Ptext, Ctext);
    IIP(Ctext, PPText);
    printf("%s\n", Ptext);
    printf("%s\n", Ctext);
    printf("%s\n", PPText);
    return 0;
}

void IP(BYTE *in, BYTE *out)
{
    int i;
    
    BYTE index, bit, mask = 0x80;
    
    for (i = 0; i < 64; i++) {
        index = (ip[i]) / 8;
        bit = (ip[i]) % 8;
        if (in[index] & (mask >> bit)) {
            // bit OR 연산자
            out[i/8] |= mask >> (i % 8);
        }
    }
}

void IIP(BYTE *in, BYTE *out)
{
    int i;
    
    BYTE index, bit, mask =0x80;
    
    for (i = 0 ; i < 64; i++) {
        index = (iip[i]) / 8;
        bit = (iip[i]) % 8;
        
        if (in[index] & (mask >> bit)) {
            out[i/8] |= mask >> (i % 8);
        }
    }
}

