#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "nfc.h"
#include "com/uart.h"
#include "crc/crc.h"
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
        uint8_t temp=recived_poll_run(md->fd);
        printf("%c",temp);
}
