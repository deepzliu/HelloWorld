#include<stdlib.h>
#include<string.h>
#include<libaio.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define FILEPATH "./test.txt"

int main()
{
    io_context_t context;
    struct iocb io[2], *p[2]={&io[0], &io[1]};
    struct io_event e[2];
    unsigned nr_events = 10;

    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 10000000;

    char *wbuf = 0, *rbuf = 0;
    int wbuflen = 512*1024*1024;
    int rbuflen = wbuflen+1;
    posix_memalign((void**)&wbuf, 512, wbuflen);
    posix_memalign((void**)&rbuf, 512, rbuflen);
    memset(wbuf, 'a', wbuflen);
    memset(rbuf, 0, rbuflen);
    memset(&context, 0, sizeof(io_context_t));

    int ret = 0, comp_num = 0, i = 0;

    int fd = open(FILEPATH, O_CREAT|O_RDWR|O_DIRECT, 0644);
    if(fd < 0)
	{ 
        printf("open file failed ！\n");
        return 0;
    }   

    if( 0 != io_setup(nr_events, &context) ){

        printf("io_setup error:%d\n", errno);
    }   

    io_prep_pwrite(&io[0], fd, wbuf, wbuflen, 0); 
    io_prep_pread(&io[1], fd, rbuf, rbuflen-1, 0); 

    if((ret = io_submit(context,2,p)) != 2)
    {
        printf("io_submit error:%d\n", ret);
        io_destroy(context);
        return -1;
    }

    while(true)
	{
        ret = io_getevents(context,2,2,e,&timeout);

        if(ret < 0)
        {   
            printf("io_getevents error:%d\n", ret);
            break;
        }   

        if(ret > 0)
        {   
            comp_num += ret;
            for( i = 0;i < ret; ++i)
			{
                printf("result,res2:%d, res:%d\n", e[i].res2, e[i].res);
            }
        }

        if(comp_num >= 2)
		{
            printf("done !\n");
            break;
        }
        printf("have not done !\n");
    }

    return 0;
}
