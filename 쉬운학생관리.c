#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
	int std_id;
	char name[20];
	int marks[4];
	int rank;
};
int main(void){
	FILE *fp;
	fp=fopen("Student.txt", "r");
	if (fp==NULL){
		printf("input file open error!\n");
		return 1;
	}
	struct Student s[20];
	double hap[10];
	for (int i=0;i<10;i++){
		fscanf(fp,"%d %s %d %d %d %d",&s[i].std_id, s[i].name, &s[i].marks[0], &s[i].marks[1], &s[i].marks[2], &s[i].marks[3]);
		hap[i]=(double)(s[i].marks[0]+s[i].marks[1]+s[i].marks[2]+s[i].marks[3])/4;
		s[i].rank=0;
	}
	int temp;
	
	for (int i=0;i<10;i++){
		int cnt=0;
	   for (int j=0;j<10;j++){
			if (hap[i]<hap[j]) cnt++;
			s[i].rank=cnt+1;
		}
	}
	while(1){
		printf("1 - search on number\n");
		printf("2 - search on name\n");
		printf("3 -finish\n");
		printf("\n? ");
		int N;
		scanf("%d", &N);
		if (N==1){
			printf("Input student number ");
			int M;
			scanf("%d", &M);
			for (int i=0;i<10;i++){
				if(s[i].std_id==M)
					printf("%d %s %d %d %d %d average %f rank %d\n",s[i].std_id,s[i].name,s[i].marks[0],s[i].marks[1],s[i].marks[2],s[i].marks[3],hap[i],s[i].rank);
			}
		}
		else if (N==2){
			printf("Input student name ");
			char P[100];
			int len;
			scanf("%s",P);
			for (int i=0;i<10;i++){
				len=strlen(s[i].name);
				if(strncmp(P,s[i].name,len)==0)
					printf("%d %s %d %d %d %d average %f rank %d\n",s[i].std_id,s[i].name,s[i].marks[0],s[i].marks[1],s[i].marks[2],s[i].marks[3],hap[i],s[i].rank);
			}
		}
		else if (N==3) exit(1);
		else {
			printf("wrong number");
			break;
		}
	}
	fclose(fp);
	return 0;
}
