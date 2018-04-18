//
//  OvertwoKeylessTranspositionCipher.cpp
//  CPP_2018project
//
//  Created by MJMac on 12/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX_LEN = 64;


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
    
    
    
    if (select == 1) {
        
        char **tmpText = NULL;
        tmpText = new char *[railNum];
        for (int i = 0; i < railNum; i++) {
            tmpText[i] = new char[(size/railNum)*2];
        }
        
        int *arrayNum = new int[railNum];
        for (int i = 0; i < railNum; i++) {
            arrayNum[i] = 0;
        }
        
        bool inc = true; int cnt = 0;
        for (int i = 0 ; i < size; i++) {
            // 만약 문자라면,
            if ( ( (text[i]>='a') && (text[i]<='z') ) || ( (text[i]>='A') && (text[i]<='Z') ) ) {
                // cout << text[i] << endl;
                if (inc) {
                    tmpText[cnt][arrayNum[cnt]++] = text[i];
                    // cout <<cnt <<" " << arrayNum[cnt]-1<< " " << tmpText[cnt][arrayNum[cnt]-1] << endl;
                    cnt++;
                }
                else{
                    tmpText[cnt][arrayNum[cnt]++] = text[i];
                    // cout <<cnt <<" " << arrayNum[cnt]-1 <<" "<< tmpText[cnt][arrayNum[cnt]-1] << endl;
                    cnt--;
                }
                if (i != 0 && cnt == railNum) {
                    inc = false;
                    cnt = railNum-2;
                }
                else if (i != 0 && cnt == -1)
                {
                    inc = true;
                    cnt = 1;
                }
                else
                    ;
                
            }
        }
        
        for (int i = 0; i < railNum; i++) {
            tmpText[i][arrayNum[i]] = '\0';
        }
        // return 값
        char *PCText = new char[size];
        int clk=0;
        for (int i = 0 ; i < railNum; i++) {
            cnt = 0;
            while ( tmpText[i][cnt] != '\0' ) {
                PCText[cnt+clk] = tmpText[i][cnt];
                cnt++;
            }
            clk += cnt;
        }
        
        // print
        int i = 0;
        while (i < size) {
            cout << PCText[i];
            i++;
        }
        cout << endl;
        
        delete []arrayNum;
        delete []PCText;
        for (int i = 0; i < railNum; i++) {
            delete[] tmpText[i];
        }
        delete []tmpText;
    }
    
    // 복호화 알고리즘
    else if ( select == 2 )
    {
        
        // line수 array 동적할당
        int *arrayNum = new int[railNum];
        for (int i = 0; i < railNum; i++) {
            arrayNum[i] = 0;
        }
        
        // 각 line수 number 구하기 (arrayNum[cnt])
        bool inc = true; int cnt = 0;
        for (int i = 0 ; i < size; i++) {
            if ( ( (text[i]>='a') && (text[i]<='z') ) || ( (text[i]>='A') && (text[i]<='Z') ) ) {
                if (inc) {
                    arrayNum[cnt]++;
                    cnt++;
                }
                else{
                    arrayNum[cnt]++;
                    cnt--;
                }
                if (i != 0 && cnt == railNum) {
                    inc = false;
                    cnt = railNum-2;
                }
                else if (i != 0 && cnt == -1)
                {
                    inc = true;
                    cnt = 1;
                }
                else
                    ;
                
            }
        }
        
        
        char **tmpText = NULL;
        tmpText = new char *[railNum];
        for (int i = 0; i < railNum; i++) {
            tmpText[i] = new char[arrayNum[i]];
            // cout << arrayNum[i] << endl;
        }
        
        int k = 0;
        for (int i = 0; i < railNum; i++) {
            for (int j = 0; j < arrayNum[i]; j++) {
                // cout << i << " " << j << " " << text[k] << endl;
                tmpText[i][j] = text[k];
                k++;
            }
        }
        
        
        // return 값
        // arrayNum의 배열을 0으로 초기화
        for (int i = 0; i < railNum; i++) {
            arrayNum[i] = 0;
        }
        inc = true; cnt = 0;
        for (int i = 0 ; i < size; i++) {
            if ( ( (text[i]>='a') && (text[i]<='z') ) || ( (text[i]>='A') && (text[i]<='Z') ) ) {
                if (inc) {
                    cout << tmpText[cnt][arrayNum[cnt]++];
                    cnt++;
                }
                else{
                    cout << tmpText[cnt][arrayNum[cnt]++];
                    cnt--;
                }
                if (i != 0 && cnt == railNum) {
                    inc = false;
                    cnt = railNum-2;
                }
                else if (i != 0 && cnt == -1)
                {
                    inc = true;
                    cnt = 1;
                }
                else
                    ;
                
            }
        }
        cout << endl;
        
        
        delete []arrayNum;
        for (int i = 0; i < railNum; i++) {
            delete[] tmpText[i];
        }
        delete []tmpText;
    }
    
    return 0;
}

