#ifndef __USBTEST_H
#define __USBTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include <errno.h>

#include "link.h"

#define MAX_PATH 512


void copy_file(char *pathname,char *path);
bool path_exit(char *pathname,char last[],jpeg_linklist *jpg);
void print_file_info(char *pathname,jpeg_linklist *jpg);
void dir_order(char *pathname,jpeg_linklist *jpg);

//void jpeg_list(char *pathname); 


#endif
