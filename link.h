#ifndef __LINK_H
#define __LINK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Jpeg_linklist
{
	char namepath[256];
	struct Jpeg_linklist *next;
}jpeg_linklist;



jpeg_linklist *create_list(char *namepath);
bool insert_list(jpeg_linklist *head,char *namepath);
void show_list(jpeg_linklist *head);
//void jpeg_list(jpeg_linklist *head,char *pathname); 

#endif
