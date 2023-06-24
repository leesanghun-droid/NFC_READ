#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "nfc.h"
#include "com/uart.h"
#include "poll/poll.h"
#include "time_stamp/time_stamp.h"

void nfc_serial_open(NFC *nf , char * device_name)
{
    nf->fd = uart_init(device_name);
    uart_poll_init(nf->fd);
}

void nfc_close(NFC *nf)
{
    close(nf->fd); 
}

void Read_NFC(NFC *nf)
{
    int data_cnt=0;
    uint8_t array[30];
    for(int i=0;i<100;i++)
    {
        int temp=recived_poll_run(nf->fd);
        if(temp>0)
        {
            uint8_t temp_8=(uint8_t)temp;
            nf->recived_array[data_cnt]=temp_8;
            //printf("%d : %d \r\n",data_cnt,temp_8);
            data_cnt++;
            if(data_cnt==12)
            {
                nf->data_ready=1;
                break;
            }
        }
    }

}
