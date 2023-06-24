
typedef struct _nfc
{
int fd;
int data_ready;
uint8_t recived_array[30];
} NFC;

void nfc_serial_open(NFC *nf , char * device_name);
void nfc_close(NFC *nf);
void Read_NFC(NFC *nf);