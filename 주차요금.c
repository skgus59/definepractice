#include<stdio.h>
#include<stdlib.h>
typedef struct park{  
	int car;
	int std_id;
	int indate[3];
	int intime[2];
	int outdate[3];
	int outtime[2];
}park;
void search_car(park p[], int car_num);
void search_std_id(park p[], int std_id);
int N;
int main(void){
	FILE *fp;
	fp=fopen("park.txt","r");
	if(fp==NULL){
		printf("input file open error!\n");
		return 1;
	}
	fscanf(fp,"%d",&N);
	struct park p[N];
	for (int i=0;i<N;i++){
		fscanf(fp,"%d %d %d-%d-%d %d:%d %d-%d-%d %d:%d", &p[i].car, &p[i].std_id, &p[i].indate[0], &p[i].indate[1], &p[i].indate[2], &p[i].intime[0], &p[i].intime[1], &p[i].outdate[0], &p[i].outdate[1], &p[i].outdate[2], &p[i].outtime[0], &p[i].outtime[1]);
	}
	while(1){
		printf("차량 번호로 검색 (1)번, 학번으로 검색 (2)번, 종료 (3)번\n");
		int n,A,B;
		scanf("%d", &n);
		if (n==1){
			printf("차량 번호를 입력하세요 : ");
			scanf("%d", &A);
			search_car(p,A);
		}
		else if (n==2){
			printf("학생 번호를 입력하세요 : ");
			scanf("%d", &B);
			search_std_id(p,B);
		}
		else if (n==3) exit(1);
		else printf("wrong number");
	}
	fclose(fp);
	return 0;
}
void search_car(park p[], int car_num){
	int a=0, b=0;
	for (int i=0;i<N;i++){
		if (p[i].car==car_num){
			if (p[i].indate[2]==p[i].outdate[2]){
				if (p[i].intime[0]<9){
					p[i].intime[0]=9;
					p[i].intime[1]=0;
				}
				a=p[i].outtime[0]*60+p[i].outtime[1]-p[i].intime[0]*60-p[i].intime[1];
				if (a>60){
					b=((a-60)+9)/10;
					b=b*1000+3000;
					if (b>=30000) b=30000;
				}
				else b=3000;
			}
			else if (p[i].indate[2]+1==p[i].outdate[2]){
				if (p[i].intime[0]<9){
					p[i].intime[0]=9;
					p[i].intime[1]=0;
				}
				if (p[i].outtime[0]<9){
					a=24*60-p[i].intime[0]*60-p[i].intime[1];
					if (a>60){
						b=((a-60)+9)/10;
						b=b*1000+3000;
						if (b>=30000) b=30000;
					}
					else b=3000;
				}
				else{
					a=24*60-p[i].intime[0]*60-p[i].intime[1];
					a+=p[i].outtime[0]*60+p[i].outtime[1]-9*60;
					if (a>60){
						b=((a-60)+9)/10;
						b=b*1000+3000;
						if (b>=30000) b=30000;
					}
					else b=3000;
				}
			}
			else b=30000;
		}
	}
	if (b==0) printf("등록되지 않은 차량번호 입니다.\n");
	else printf("주차요금은 %d원 입니다.\n", b);
}
void search_std_id(park p[], int std_id){
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		if (p[i].std_id == std_id) {
			if (p[i].indate[2] == p[i].outdate[2]) {
				if (p[i].intime[0] < 9) {
					p[i].intime[0] = 9;
					p[i].intime[1] = 0;
				}
				a = p[i].outtime[0] * 60 + p[i].outtime[1] - p[i].intime[0] * 60 - p[i].intime[1];
				if (a > 60) {
					b = ((a - 60) + 9) / 10;
					b = b * 1000 + 3000;
					if (b >= 30000) b = 30000;
				}
				else b = 3000;
			}
			else if (p[i].indate[2] + 1 == p[i].outdate[2]) {
				if (p[i].intime[0] < 9) {
					p[i].intime[0] = 9;
					p[i].intime[1] = 0;
				}
				if (p[i].outtime[0] < 9) {
					a = 24 * 60 - p[i].intime[0] * 60 - p[i].intime[1];
					if (a > 60) {
						b = ((a - 60) + 9) / 10;
						b = b * 1000 + 3000;
						if (b >= 30000) b = 30000;
					}
					else b = 3000;
				}
				else {
					a = 24 * 60 - p[i].intime[0] * 60 - p[i].intime[1];
					a += p[i].outtime[0] * 60 + p[i].outtime[1] - 9 * 60;
					if (a > 60) {
						b = ((a - 60) + 9) / 10;
						b = b * 1000 + 3000;
						if (b >= 30000) b = 30000;
					}
					else b = 3000;
				}
			}
			else b = 30000;
		}
	}
	if (b == 0) printf("등록되지 않은 학번 입니다.\n");
	else printf("주차요금은 %d원 입니다.\n", b);
}
