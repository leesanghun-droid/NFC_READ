
typedef struct _modbus
{
int fd;
int slave_num;
} MODBUS;

void modbus_serial_open(MODBUS *md , char * device_name);
void modbus_close(MODBUS *md);

bool Write_Single_Register(MODBUS *md,uint16_t address,uint16_t data);
uint16_t Read_Holding_Register_Single(MODBUS *md,uint16_t address);
bool Write_Single_Coil(MODBUS *md,uint16_t address,bool bit);
bool Read_Coils_Single(MODBUS *md,uint16_t address);