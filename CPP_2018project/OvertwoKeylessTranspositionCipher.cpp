//
//  OvertwoKeylessTranspositionCipher.cpp
//  CPP_2018project
//
//  Created by MJMac on 12/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX_LEN = 100;

int main()
{
    /*
     size: size of text
     select: 1: Enc, 2:Dec
     rowNum / colNum
     
     */
    int size=0, select=0, railNum = 0;
    char text[MAX_LEN];
    

    cout << "암호는 1번, 복호는 2번 선택";
    cin >> select;
    
    if (select == 1) {
        cout << "평문입력: ";
        cin >> text;
        size = (int)strlen(text);
    }
    else if(select == 2){
        cout << "암호문입력: ";
        cin >> text;
        size = (int)strlen(text);
    }
    else ;

    cout << "Rail의 갯수:";
    cin >> railNum;
    
    char **tmpText = NULL;
    tmpText = new char *[railNum];
    for (int i = 0; i < railNum; i++) {
        tmpText[i] = new char[size/railNum];
    }
    
    for (int i = 0 ; i < size; i++) {
        if ( ( (text[i]>='a') && (text[i]<='z') ) || ( (text[i]>='A') && (text[i]<='Z') ) ) {
            int j = i / railNum;
            int k = i % railNum;
            tmpText[k][j] = text[i];
            
        }
    }
    // return 값
    char *PCText = new char[size];
    int clk=0;
    for (int i = 0 ; i < railNum; i++) {
        int cnt = 0;
        while ( cnt != (size/railNum) ) {
            PCText[cnt+clk] = tmpText[i][cnt];
            cnt++;
        }
        clk = cnt;
    }
    
    // print
    int i = 0;
    while (PCText[i] != '\0') {
        cout << PCText[i];
        i++;
    }
    
    delete []PCText;
    for (int i = 0; i < railNum; i++) {
        delete[] tmpText[i];
    }
    delete []tmpText;
    return 0;
}
