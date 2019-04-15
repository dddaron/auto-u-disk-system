#include "usbtest.h"
#include "link.h"

int main(int argc,char *argv[])
{
	jpeg_linklist *jpg = NULL;
	jpg = create_list("NULL");

	if(jpg == NULL)
	{
		printf("create jpeg list fail\n");
		return -1;
	}


	if(argc == 1)
		dir_order(".",jpg);
	else
		dir_order(argv[1],jpg);


	show_list(jpg);
				
	return 0;
}
