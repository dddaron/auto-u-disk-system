#include "link.h"

jpeg_linklist *create_list(char *namepath)
{
	jpeg_linklist *head = (jpeg_linklist*)malloc(sizeof(jpeg_linklist));
	if(head == NULL)
	{
		printf("create fail\n");
		return NULL;
	}

	//head->namepath = namepath;
	strcpy(head->namepath,namepath);
	head->next = head;

	return head;
}


bool insert_list(jpeg_linklist *head,char *namepath)
{
	jpeg_linklist *new = create_list(namepath);
	if(new == NULL)
	{
		printf("insert jpeg fail\n");
		return false;
	}

	new->next = head->next;
	head->next = new;

	return true;
}



void show_list(jpeg_linklist *head)
{
	char newname[256];

	if(head == NULL)
		return;

	jpeg_linklist *p = head->next;
	
	while(1)
	{
		printf("list:%s\t",p->namepath);
		sprintf(newname,"%s %s","xdg-open",p->namepath);
		system(newname);
		sleep(2);
		p = p->next;
	}
	printf("\n");
}

