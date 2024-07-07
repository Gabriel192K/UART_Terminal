#include <UART_Terminal.h>

UART_Terminal terminal(&UART);

void setup(void)
{
    terminal.begin(115200);
}

void loop(void)
{
    terminal.println('A');
    terminal.println("Hello from RAM");
    terminal.printPln(PSTR("Hello from Flash"));
    terminal.println((const uint8_t)255, BIN);
    terminal.println((const uint8_t)255, OCT);
    terminal.println((const uint8_t)255);
    terminal.println((const uint8_t)255, HEX);
    terminal.println((const uint16_t)65535, BIN);
    terminal.println((const uint16_t)65535, OCT);
    terminal.println((const uint16_t)65535);
    terminal.println((const uint16_t)65535, HEX);
    terminal.println((const uint32_t)4294967295, BIN);
    terminal.println((const uint32_t)4294967295, OCT);
    terminal.println((const uint32_t)4294967295);
    terminal.println((const uint32_t)4294967295, HEX);
    delay(1000);
}
