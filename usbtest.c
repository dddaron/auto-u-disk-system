#include "usbtest.h"


void copy_file(char *pathname,char *path)
{
	char buf[1024] = {0};
	char *name,newname[MAX_PATH];
	FILE *fp,*fp1;
	int cnt;

	fp = fopen(pathname,"a+");
	if(fp == NULL)
	{
		printf("open test fail\n");
		return;
	}

	sprintf(newname,"%s/%s","/vim",path);	//自己定义要把文件复制到哪个路径，这里是/vim/jpeg
	name = strrchr(pathname,'/')+1;			//原来的文件名（不包括路径）
	sprintf(newname,"%s/%s",newname,name);	//复制过去的文件路径
	printf("newname:%s\n",newname);

	fp1 = fopen(newname,"w+");
	if(fp1 == NULL)
	{
		printf("open test1 fail\n");
		return;
	}

	while((cnt = fread(buf,sizeof(char),sizeof(buf),fp)) > 0)
	{
		fwrite(buf,sizeof(char),cnt,fp1);
		printf("cnt:%d\n",cnt);
	}	

	fclose(fp);
	fclose(fp1);
}



bool path_exit(char *pathname,char last[],jpeg_linklist *jpg)
{
	char *ptr,*fileExit;

	ptr = strrchr(pathname,'.');

	if(strcmp(ptr,last) == 0)
	{
		printf("%s exit:%s\n",last,pathname);

		copy_file(pathname,last+1);

		insert_list(jpg,pathname);

		return true;
	}
	else
		return false;
}



void print_file_info(char *pathname,jpeg_linklist *jpg)
{
	struct stat filestat;
	if(stat(pathname,&filestat) == -1)
	{
		printf("cannot access file %s\n",pathname);
		return;
	}
	printf("%s %8ld\n",pathname,filestat.st_size);

	path_exit(pathname,".jpeg",jpg);
	//path_exit(pathname,".mp3");

	if((filestat.st_mode & S_IFMT) == S_IFDIR)
		dir_order(pathname,jpg);
}


void dir_order(char *pathname,jpeg_linklist *jpg)
{
	DIR *dfd;
	char name[MAX_PATH];
	struct dirent *dp;

	if((dfd = opendir(pathname)) == NULL)
	{
		printf("dir_order:cannot open %s\n %s",pathname,strerror(errno));
		return;
	}

	while((dp = readdir(dfd)) != NULL)
	{
		if(strncmp(dp->d_name,".",1) == 0)
			continue;

		if(strlen(pathname)+strlen(dp->d_name)+2 > sizeof(name))
			printf("dir_order:name %s %s too long\n",pathname,dp->d_name);
		else
		{
			memset(name,0,sizeof(name));
			sprintf(name,"%s/%s",pathname,dp->d_name);
			print_file_info(name,jpg);
		}
	}
	closedir(dfd);
}
