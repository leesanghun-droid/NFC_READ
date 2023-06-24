#include <sys/poll.h>
#include <stdint.h>

struct pollfd uart_poll_events;
int    poll_state;

void uart_poll_init(int fd)
{
   // poll 사용을 위한 준비   
   uart_poll_events.fd        = fd;
   uart_poll_events.events    = POLLIN | POLLERR;          // 수신된 자료가 있는지, 에러가 있는지
   uart_poll_events.revents   = 0;

}

int recived_poll_run(int fd)
{
      poll_state = poll(                                // poll()을 호출하여 event 발생 여부 확인     
                         (struct pollfd*)&uart_poll_events,  // event 등록 변수
                                                    1,  // 체크할 pollfd 개수
                                                    30  // time out // -1 : inpinity stay
                       );
      if (poll_state > 0)                             // 발생한 event 가 있음
      {     
         if ( uart_poll_events.revents & POLLIN)            // uart1 base 보드 통신
         {
            uint8_t data;
            read( fd, &data, 1);
            return (int)data;
         }

         if ( uart_poll_events.revents & POLLERR)      // event 가 에러?
         {
            printf( "uart2 에 에러가 발생, 프로그램 종료");
            return -1;
         }
      }
      else if(poll_state < 0)
      {
          printf("Critial Error!\n");
          return -2;
      }
      else if(poll_state == 0)
      {
          //printf("wait...\n");
          return -3;
      }
      return -4;
}