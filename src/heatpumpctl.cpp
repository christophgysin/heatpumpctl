#include <iostream>
#include <serial/BufferedAsyncSerial.h>

int main(int, char**)
{
    BufferedAsyncSerial serial("/dev/ttyUSB0", 56700);
    serial.writeString("1800\r\n");

    std::string response = serial.readStringUntil("\r\n");

    std::cout << response << std::endl;

    return EXIT_SUCCESS;
}
