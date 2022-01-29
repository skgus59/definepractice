#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create_NODE(int id, char *name);
typedef struct struct_NODE{
	int st_id;
	char st_name[30];
	struct struct_NODE *link;
} NODE;
NODE *head=NULL;
int main(void){
	printf("[Select Menu]\n");
	printf("1 Insert a new student\n");
	printf("2 Print list\n");
	int a, id;
	char name[30];
	while(1){
		scanf("%d",&a);
		if (a==1){
			printf("Enter a student: ");
			scanf("%d/%s", &id,name);
			create_NODE(id, name);
		}
		else if (a==2){
			NODE *cur=head;
			while (cur!=NULL){
				printf("[%d/%s] -> ", cur->st_id, cur->st_name);
				cur=cur->link;
			}
			printf("NULL\n");
		}
		else break;
	}
	return 0;
}
void create_NODE(int id, char *name){
	NODE *pre;
	pre=head;
	NODE *new;
	new=(NODE*)malloc(sizeof(NODE));
	new->link=NULL;
	for (int i=0;i<30;i++){
		new->st_name[i]=name[i];
	}
	new->st_id=id;
	if (head==NULL){
		head=new;
	}
	else{
		while(pre->link!=NULL){
			pre=pre->link;
		}
		pre->link=new;
	}
}
