// 매입 매출 관리프로그램.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>


int money = 10000;
int sellprice = 500;
int restment_quantity = 0;

typedef struct customer {
	char name[20];
	int age;
	int birthday;
	int phonenumber;
	int bought;
	int perchased;
}cus;

typedef struct factory {
	char name[20];
	int price;
}fac;

typedef struct bought {
	char name[20];
	int qty;
}tra;


int main()
{
	cus arr_c[10];
	fac arr_f[3];
	tra arr_t[3];

	int i_temp;
	int a, i;
	char c_temp[20];
	char name[20];
	int bought;

	printf("관리항목 입력(고객관리:1,매입처관리:2,매입관리:3,재고관리:4,매출관리:5,수익관리:6)");
	scanf_s("%d", &i_temp);
	switch (i_temp) {
	case 1:
		int a;
		printf("관리 항목 입력(고객정보입력:1,고객정보 조회:2)");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			for (i = 0; i < 10; i++) {
				printf("고객의 이름,나이,생일,전화번호,구입수,결제가격 입력\n");
				scanf_s("%s %d %d %d %d %d", arr_c[i].name, &arr_c[i].age, &arr_c[i].birthday, &arr_c[i].phonenumber, &arr_c[i].bought, &arr_c[i].perchased);
			}
			break;
		case 2:
			printf("조회하려는 고객이름 입력==>\n");
			scanf_s("%s", &c_temp);

			for (i = 0; i < 10; i++) {
				if (strcmp(c_temp, arr_c[i].name) == 0) {
					printf("%s님의 나이:%d\n", arr_c[i].name, arr_c[i].age);
					printf("%s님의 생일:%d\n", arr_c[i].name, arr_c[i].birthday);
					printf("%s님의 전화번호:%d\n", arr_c[i].name, arr_c[i].phonenumber);
					printf("%s님의 구입수:%d\n", arr_c[i].name, arr_c[i].bought);
					printf("%s님의 결제가격:%d\n", arr_c[i].name, arr_c[i].perchased);
				}
			}
			break;
		}
		break;

	case 2:
		for (i = 0; i < 3; i++) {
			printf("매입처명과 상품 개수별 가격 입력\n");
			scanf_s("%s %d", arr_f[i].name, &arr_f[i].price);
		}
		break;

	case 3:
		printf("매입처명 및 구입수량 입력\n");
		scanf_s("%s %d", c_temp, &bought);

		for (i = 0; i < 3; i++) {
			if (strcmp(arr_f[i].name, c_temp) == 0) {
				money = money - arr_f[i].price*bought;
				restment_quantity = restment_quantity + bought;
				break;
			}
		}
		break;

	case 4:
		printf("현재 재고:%d\n", restment_quantity);
		break;

	case 5:
		printf("구매자명 및 판매수량 입력\n");
		scanf_s("%s%d", &name, &bought);

		for (i = 0; i < 20; i++) {
			if (strcmp(name, arr_c[i].name) == 0) {
				money = money + arr_c[i].bought*bought;
				restment_quantity = restment_quantity - bought;
				break;
			}
		}
		break;

	case 6:
		printf("현재 판매량:%d\n", restment_quantity);
		printf("현재잔고:%d\n", money);
		break;
	}
}
