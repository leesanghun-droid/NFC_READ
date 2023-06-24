#include "uart.h"
#include <termios.h>                   // B115200, CS8 등 상수 정의
#include <fcntl.h>                     // O_RDWR , O_NOCTTY 등의 상수 정의


int uart_init(const char* device)
{
   int fd;

   struct termios    newtio;

   fd = open(device, O_RDWR | O_NOCTTY );        // 디바이스를 open 한다.
   if ( 0 > fd)
   {        
      printf("%s  open error\n",device);
   }else{
   printf("%s  open\n",device);
   }

       //printf("open_fd : %d\r\n",fd);

   // 시리얼 포트 통신 환경 설정
   memset(&newtio, 0, sizeof(newtio) );
   newtio.c_cflag       = B9600 | CS8 | CLOCAL | CREAD;
   newtio.c_oflag       = 0;
   newtio.c_lflag       = 0;
   newtio.c_cc[VTIME]   = 0;
   newtio.c_cc[VMIN]    = 1;

   tcflush(fd, TCIFLUSH);
   tcsetattr(fd, TCSANOW, &newtio);
   fcntl(fd, F_SETFL, FNDELAY); 

   return fd;
}
