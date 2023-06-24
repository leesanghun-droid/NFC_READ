    
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 

void Time_printf(char * string)
    {
    struct timeval  tv;

	gettimeofday(&tv, NULL);

    time_t t =tv.tv_sec;

    struct tm *now = localtime(&t);

    printf("(%04d/%02d/%02d) [%02d:%02d:%02d",1900 + now->tm_year,now->tm_mon + 1,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
    printf(".%03d] ",(tv.tv_usec/1000));
    printf("%s",string);

    }
    