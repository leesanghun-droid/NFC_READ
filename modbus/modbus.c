#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "modbus.h"
#include "com/uart.h"
#include "crc/crc.h"
#include "poll/poll.h"
#include "time_stamp/time_stamp.h"

void modbus_serial_open(MODBUS *md , char * device_name)
{
    md->fd = uart_init(device_name);
    uart_poll_init(md->fd);
}

void modbus_close(MODBUS *md)
{
    close(md->fd); 
}
static uint8_t recived_array[7]={0};
bool Write_Single_Register(MODBUS *md,uint16_t address,uint16_t data)
{
    uint8_t bytes[8] = {0};
    bytes[0] = md->slave_num;
    bytes[1] = 0x06;
    bytes[2] = (uint8_t)(address >> 8);
    bytes[3] = (uint8_t)address;
    bytes[4] = (uint8_t)(data >> 8);
    bytes[5] = (uint8_t)data;

    uint16_t crc;
    crc = cal_crc(bytes, 6);

    uint8_t CRC_L = (uint8_t)crc;
    uint8_t CRC_H = (uint8_t)(crc >> 8);

    bytes[6] = CRC_L;
    bytes[7] = CRC_H;

/////////////// SEND PRINT /////////////////
    write(md->fd, bytes, 8); 
    Time_printf("[PC->PLC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",bytes[i]);
    printf("(Write_Single_Register)");
    printf("\r\n");
////////////////////////////////////////////
/////////////// RECIVED PRINT //////////////
    int data_cnt=0;
    int temp=0;

    for(int i=0; i<30;i++)
    {
        temp=recived_poll_run(md->fd);
        if(temp>=0)
        {
            recived_array[data_cnt]=temp;
            data_cnt++;
        }
        if(data_cnt>=8)
        {
            break;
        }
    }
    Time_printf("[PLC->PC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",recived_array[i]);
    printf("(RESPONSE)");


    uint16_t CHECK_crc;
    CHECK_crc = cal_crc(recived_array, 6);

    uint8_t CHECK_CRC_L = (uint8_t)CHECK_crc;
    uint8_t CHECK_CRC_H = (uint8_t)(CHECK_crc >> 8);

    if(CHECK_CRC_L==recived_array[6] && CHECK_CRC_H==recived_array[7] )
    {
        printf("(CRC_OK)");
        printf("\r\n");
        return 1;
    }
        printf("(CRC_FAILD)");
        printf("\r\n");
      
      return 0;

////////////////////////////////////////////


////////////////////////////////////////////

}
uint16_t Read_Holding_Register_Single(MODBUS *md,uint16_t address)
{
    uint8_t bytes[8] = {0};//uint8_t* bytes = (uint8_t*)malloc(sizeof(uint8_t)*size);
    bytes[0] = md->slave_num;
    bytes[1] = 0x03;
    bytes[2] = (uint8_t)(address >> 8);
    bytes[3] = (uint8_t)address;
    bytes[4] = (uint8_t)(1 >> 8);
    bytes[5] = (uint8_t)1;

        uint16_t crc;
    crc = cal_crc(bytes, 6);

    uint8_t CRC_L = (uint8_t)crc;
    uint8_t CRC_H = (uint8_t)(crc >> 8);

    bytes[6] = CRC_L;
    bytes[7] = CRC_H;

    write(md->fd, bytes, 8); 
/////////////// SEND PRINT /////////////////
    Time_printf("[PC->PLC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",bytes[i]);
    printf("(Read_Holding_Register)");
    printf("\r\n");
////////////////////////////////////////////
/////////////// RECIVED PRINT //////////////
    int data_cnt=0;
    int temp=0;

    for(int i=0; i<30;i++)
    {
        temp=recived_poll_run(md->fd);
        if(temp>=0)
        {
            recived_array[data_cnt]=temp;
            data_cnt++;
        }
        if(data_cnt>=7)
        {
            break;
        }
    }
    Time_printf("[PLC->PC] ");
    for(int i=0;i<7;i++)
    printf("0x%02X,",recived_array[i]);
    printf("(RESPONSE)");


    uint16_t CHECK_crc;
    CHECK_crc = cal_crc(recived_array, 5);

    uint8_t CHECK_CRC_L = (uint8_t)CHECK_crc;
    uint8_t CHECK_CRC_H = (uint8_t)(CHECK_crc >> 8);

    if(CHECK_CRC_L==recived_array[5] && CHECK_CRC_H==recived_array[6] )
    {
        printf("(CRC_OK)");
        printf("\r\n");
        return (uint16_t)(recived_array[3])*256+(uint16_t)(recived_array[4]);
    }
        printf("(CRC_FAILD)");
        printf("\r\n");
      
      return 0;

////////////////////////////////////////////
}

bool Read_Coils_Single(MODBUS *md,uint16_t address)
{
    uint8_t bytes[8] = {0};//uint8_t* bytes = (uint8_t*)malloc(sizeof(uint8_t)*size);
    bytes[0] = md->slave_num;
    bytes[1] = 0x01;
    bytes[2] = (uint8_t)(address >> 8);
    bytes[3] = (uint8_t)address;
    bytes[4] = (uint8_t)(1 >> 8);
    bytes[5] = (uint8_t)1;

        uint16_t crc;
    crc = cal_crc(bytes, 6);

    uint8_t CRC_L = (uint8_t)crc;
    uint8_t CRC_H = (uint8_t)(crc >> 8);

    bytes[6] = CRC_L;
    bytes[7] = CRC_H;

    write(md->fd, bytes, 8); 
/////////////// SEND PRINT /////////////////
    Time_printf("[PC->PLC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",bytes[i]);
    printf("(Read_Coils)");
    printf("\r\n");
////////////////////////////////////////////
/////////////// RECIVED PRINT //////////////
    int data_cnt=0;
    int temp=0;

    for(int i=0; i<30;i++)
    {
        temp=recived_poll_run(md->fd);
        if(temp>=0)
        {
            recived_array[data_cnt]=temp;
            data_cnt++;
        }
        if(data_cnt>=6)
        {
            break;
        }
    }
    Time_printf("[PLC->PC] ");
    for(int i=0;i<6;i++)
    printf("0x%02X,",recived_array[i]);
    printf("(RESPONSE)");


    uint16_t CHECK_crc;
    CHECK_crc = cal_crc(recived_array, 4);

    uint8_t CHECK_CRC_L = (uint8_t)CHECK_crc;
    uint8_t CHECK_CRC_H = (uint8_t)(CHECK_crc >> 8);

    if(CHECK_CRC_L==recived_array[4] && CHECK_CRC_H==recived_array[5] )
    {
        printf("(CRC_OK)");
        printf("\r\n");
        return (bool)recived_array[3];
    }
        printf("(CRC_FAILD)");
        printf("\r\n");
      
      return 0;

////////////////////////////////////////////
}

bool Write_Single_Coil(MODBUS *md,uint16_t address,bool bit)
{
    uint8_t bytes[8] = {0};//uint8_t* bytes = (uint8_t*)malloc(sizeof(uint8_t)*size);
    bytes[0] = md->slave_num;
    bytes[1] = 0x05;
    bytes[2] = (uint8_t)(address >> 8);
    bytes[3] = (uint8_t)address;
    if(bit)
    {
        bytes[4] = 0xff;
        bytes[5] = 0x00;
    }else
    {
        bytes[4] = 0x00;
        bytes[5] = 0x00;
    }

        uint16_t crc;
    crc = cal_crc(bytes, 6);

    uint8_t CRC_L = (uint8_t)crc;
    uint8_t CRC_H = (uint8_t)(crc >> 8);

    bytes[6] = CRC_L;
    bytes[7] = CRC_H;

    write(md->fd, bytes, 8); 
/////////////// SEND PRINT /////////////////
    Time_printf("[PC->PLC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",bytes[i]);
    printf("(Write_Single_Coils)");
    printf("\r\n");
////////////////////////////////////////////
/////////////// RECIVED PRINT //////////////
    int data_cnt=0;
    int temp=0;

    for(int i=0; i<30;i++)
    {
        temp=recived_poll_run(md->fd);
        if(temp>=0)
        {
            recived_array[data_cnt]=temp;
            data_cnt++;
        }
        if(data_cnt>=8)
        {
            break;
        }
    }
    Time_printf("[PLC->PC] ");
    for(int i=0;i<8;i++)
    printf("0x%02X,",recived_array[i]);
    printf("(RESPONSE)");


    uint16_t CHECK_crc;
    CHECK_crc = cal_crc(recived_array, 6);

    uint8_t CHECK_CRC_L = (uint8_t)CHECK_crc;
    uint8_t CHECK_CRC_H = (uint8_t)(CHECK_crc >> 8);

    if(CHECK_CRC_L==recived_array[6] && CHECK_CRC_H==recived_array[7] )
    {
        printf("(CRC_OK)");
        printf("\r\n");
        return 1;
    }
        printf("(CRC_FAILD)");
        printf("\r\n");
      
      return 0;

////////////////////////////////////////////
}