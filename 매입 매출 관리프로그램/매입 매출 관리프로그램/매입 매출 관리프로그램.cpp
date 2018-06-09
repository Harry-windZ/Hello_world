// 매입 매출 관리프로그램.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>


int money = 10000;
int sellprice = 500;
int restment_quantity = 0;

int main()
{
	struct customer {
		char name[20];
		int age;
		int birthday;
		int phonenumber;
		int bought;
		int perchased;
	}arr_c[10];

	struct factory {
		char name[20];
		int price;
	}arr_f[3];

	int temp;
	printf("관리항목 입력(고객관리:1,매입처관리:2,매입관리:3,재고관리:4,매출관리:5,수익관리:6)");
	scanf_s("%d", &temp);
	switch (temp) {
	case 1:
		int a;
		printf("관리 항목 입력(고객정보입력:1,고객정보 조회:2)");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			int i;
			customer *ptr_c;
			ptr_c = new customer;
			ptr_c = arr_c;
			for (i = 0; i < 10; i++) {
				printf("고객의 이름,나이,생일,전화번호,구입수,결제가격 입력\n");
				scanf_s("%s%d%d%d%d%d", ptr_c->name, ptr_c->age, ptr_c->birthday, ptr_c->phonenumber, ptr_c->bought, ptr_c->perchased);
				ptr_c++;
			}
			delete ptr_c;
		case 2:
			int i_4;
			char temp[20];
			ptr_c = arr_c;
			printf("조회하려는 고객이름 입력==>\n");
			scanf_s("%s", &temp);
			for (i_4 = 0; i_4 < 20; i_4++) {
				if (strcmp(temp, ptr_c->name) == 0) {
					printf("%s님의 나이:%d\n",ptr_c->name,ptr_c->age);
					printf("%s님의 생일:%d\n", ptr_c->name, ptr_c->birthday);
					printf("%s님의 전화번호:%d\n", ptr_c->name, ptr_c->phonenumber);
					printf("%s님의 구입수:%d\n", ptr_c->name, ptr_c->bought);
					printf("%s님의 결제가격:%d\n", ptr_c->name, ptr_c->perchased);
					ptr_c++;
				}
				else {
					ptr_c++;
				}
			}
			delete ptr_c;
			
		}
		
	case 2:
		int i_2;
		factory *ptr_f;
		ptr_f = new factory;
		ptr_f = arr_f;
		for (i_2 = 0; i_2 < 3; i_2++) {
			printf("매입처명과 상품 개수별 가격 입력\n");
			scanf_s("%s%d", ptr_f->name, ptr_f->price);
			ptr_f++;
		}
		delete ptr_f;
	case 3:
		int i_3;
		char name[20];
		int bought;
		ptr_f = arr_f;
		printf("매입처명 및 구입수량 입력\n");
		scanf_s("%s%d", &name, &bought);
		for (i_3 = 0; i_3 < 3; i_3++) {
			if (strcmp(name, ptr_f->name)==0) {
				money = money - ptr_f->price*bought;
				restment_quantity = restment_quantity + bought;
				ptr_f++;
			}
			else {
				ptr_f++;
			}
		}
		delete ptr_f;
	case 4:
		printf("현재 재고:%d\n", restment_quantity);
	case 5:
		int i_4;
		char temp_n[20];
		int bought_c;
		customer *ptr_c;
		ptr_c = new customer;
		ptr_c = arr_c;
		printf("구매자명 및 판매수량 입력\n");
		scanf_s("%s%d", &name, &bought_c);
		for (i_4 = 0; i_4 < 20; i_4++) {
			if (strcmp(name, ptr_c->name) == 0) {
				money = money + ptr_c->bought*bought_c;
				restment_quantity = restment_quantity - bought_c;
				ptr_c++;
			}
			else {
				ptr_c++;
			}
		}
		delete ptr_c;
	case 6:
		printf("현재 판매량:%d\n",restment_quantity );
		printf("현재잔고:%d\n", money);
	}
}


