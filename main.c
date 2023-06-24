#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "nfc/nfc.h"

NFC* nfc_instance;

int main(int argc, char **argv)
{
    nfc_instance = (NFC*)malloc(sizeof(NFC));
    nfc_instance->data_ready = 0;

    printf("hellow\r\n");

    nfc_serial_open(nfc_instance,"/dev/ttyUSB0");
    while(1)
    {
        Read_NFC(nfc_instance);
        if(nfc_instance->data_ready==1)
        {
            printf("NFC ID : ");
            for(int i=0;i<8;i++)
                printf("%c",nfc_instance->recived_array[i+1]);
            printf("\r\n");
            nfc_instance->data_ready=0;
        }
        sleep(1);
    }
    nfc_close(nfc_instance);

    return 0;
}


