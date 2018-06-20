//
//  OSP_hw5.c
//  CPP_2018project
//
//  Created by MJMacBook on 23/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 50
static int size = 0;

typedef struct _phone {
    char name[10];
    char number[13];
}Phone;

void RegisterP(Phone[]);
void SearchP(Phone[]);
void SearchAll(Phone[]);
void DeleteP(Phone[]);

int main()
{
    char pwd[20];
    int menu;
    int whilecnt = 0;
    Phone book[MAX];
    printf("전화번호관리\n\n");
    
    while (1) {
        printf("1. 등록   2. 전체검색 3. 특정인검색    4. 제거   5.종료\n");
        printf("메뉴 선택: "); scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("비밀번호: ");
                while (scanf("%s", pwd)) {
                    if (!strcmp(pwd, "qwer1234")) {
                        break;
                    }
                    whilecnt++;
                    if (whilecnt < 3) {
                        printf("비밀번호(%d회실패):", whilecnt);
                    }
                    else
                    {
                        printf("비밀번호(%d회실패): 등록할 수 없음!\n", whilecnt);
                        printf("프로그램을 종료합니다.\n");
                        return 0;
                    }
                }
                RegisterP(book);
                break;
                
            case 2:
                SearchAll(book);
                break;
                
            case 3:
                SearchP(book);
                break;
                
            case 4:
                DeleteP(book);
                break;
                
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
                break;
                
            default:
                printf("메뉴선택: ");
                break;
        }
    }
    return 0;
}

void RegisterP(Phone phone[])
{
    printf("등록할 이름: "); scanf("%s",phone[size].name);
    printf("전화번호: "); scanf("%s",phone[size].number);
    printf("%s님, 정보 등록 완료!\n", phone[size].name);
    size++;
}

void SearchP(Phone phone[])
{
    int i;
    char sname[10];
    printf("검색할 이름: "); scanf("%s", sname);
    for (i = 0; i < size; i++) {
        if (!strcmp(phone[i].name, sname)) {
            printf("%s\t%s\n", phone[i].name, phone[i].number);
        }
    }
}
void SearchAll(Phone phone[])
{
    int i;
    printf(" << 전화번호목록 >> \n");
    for (i = 0; i < size; i++) {
        printf("%s\t%s\n", phone[i].name, phone[i].number);
    }
}
void DeleteP(Phone phone[])
{
    int i; int cnt = size;
    char sname[10];
    printf("검색할 이름: "); scanf("%s", sname);
    for (i = 0; i < size; i++) {
        if (!strcmp(phone[i].name, sname)) {
            cnt = i;
        }
    }
    for (i = cnt ; i < size ; i++) {
        phone[i] = phone[i+1];
    }
    size--;
}
