#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h> 
#include "main.h"

MODBUS* modbus;

int READY_Write_Single_Register = 0;
int READY_Read_Holding_Register = 0;


int main(int argc, char **argv)
{
    modbus = (MODBUS*)malloc(sizeof(MODBUS));

    modbus_serial_open(modbus,"/dev/ttyS2");
    modbus->slave_num = 0;
    

    Write_Single_Register(modbus,0x0000,0x3333);
    uint16_t temp = Read_Holding_Register_Single(modbus,0x0000);

    printf("temp : 0x%04X \r\n",temp);

    Write_Single_Coil(modbus,0x0000,0);
    bool bit = Read_Coils_Single(modbus,0x0000);

    printf("bit : 0x%04X \r\n",bit);

    modbus_close(modbus);


    return 0;
}

//Read_Holding_Register(modbus,0x0000,0x0001);
//Write_Single_Register(modbus,0x0002,0x1112);