CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(time_stamp STATIC time_stamp/time_stamp.c)
add_library(poll STATIC poll/poll.c)
add_library(uart STATIC com/uart.c)
add_library(crc STATIC crc/crc.c)
add_library(nfc STATIC nfc.c)

target_link_libraries(nfc uart crc poll time_stamp)