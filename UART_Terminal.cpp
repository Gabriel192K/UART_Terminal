/* Dependencies */
#include "UART_Terminal.h"

UART_Terminal::UART_Terminal(__UART__* uart)
{
    this->uart = uart;
}

UART_Terminal::~UART_Terminal()
{
    this->uart = NULL;
}

const uint8_t UART_Terminal::begin(const uint32_t baudrate)
{
    return (this->uart->begin(baudrate));
}

const uint8_t UART_Terminal::available(void)
{
    return (this->uart->available());
}

void UART_Terminal::flush(void)
{
    this->flush();
}

const uint8_t UART_Terminal::isTransmitting(void)
{
    return (this->uart->isTransmitting());
}

const char UART_Terminal::read(void)
{
    return (this->uart->read());
}

void UART_Terminal::println(void)
{
    this->print('\n');
}

void UART_Terminal::print(const char c)
{
    this->uart->write((const uint8_t)c);
}

void UART_Terminal::println(const char c)
{
    this->print(c);
    this->println();
}

void UART_Terminal::print(const char* s)
{
    while (*s)
        this->print(*s++);
}

void UART_Terminal::println(const char* s)
{
    this->print(s);
    this->println();
}

void UART_Terminal::printP(const char* s)
{
    while (pgm_read_byte(s))
        this->print((const char)pgm_read_byte(s++));
}

void UART_Terminal::printPln(const char* s)
{
    this->printP(s);
    this->println();
}

void UART_Terminal::print(const uint8_t n, const uint8_t base)
{
    switch (base)
    {
        case BIN:
            for (int i = 7; i >= 0; i--)
                this->print((const char)(((n >> i) & 1) + '0'));
            break;
        case OCT:
            if (n > 63) this->print((const char)(((n >> 6) & 7) + '0'));
            if (n > 7)  this->print((const char)(((n >> 3) & 7) + '0'));
            this->print((const char)((n & 7) + '0'));
            break;
        case DEC:
            if (n > 99) this->print((const char)(((n / 100) % 10) + '0'));
            if (n > 9)  this->print((const char)(((n / 10) % 10) + '0'));
            this->print((const char)((n % 10) + '0'));
            break;
        case HEX:
            this->print(HEX_DIGIT((n >> 4) & 0x0F));
            this->print(HEX_DIGIT(n & 0x0F));
            break;
        default:
            break;
    }
}

void UART_Terminal::println(const uint8_t n, const uint8_t base)
{
    this->print(n, base);
    this->println();
}

void UART_Terminal::print(const uint16_t n, const uint8_t base)
{
    switch (base)
    {
        case BIN:
            for (int i = 15; i >= 0; i--)
                this->print((const char)(((n >> i) & 1) + '0'));
            break;
        case OCT:
            if (n > 07777) this->print((const char)(((n >> 12) & 7) + '0'));
            if (n > 0777)  this->print((const char)(((n >> 9) & 7) + '0'));
            if (n > 077)   this->print((const char)(((n >> 6) & 7) + '0'));
            if (n > 07)    this->print((const char)(((n >> 3) & 7) + '0'));
            this->print((const char)((n & 7) + '0'));
            break;
        case DEC:
            if (n > 9999) this->print((const char)(((n / 10000) % 10) + '0'));
            if (n > 999)  this->print((const char)(((n / 1000) % 10) + '0'));
            if (n > 99)   this->print((const char)(((n / 100) % 10) + '0'));
            if (n > 9)    this->print((const char)(((n / 10) % 10) + '0'));
            this->print((const char)((n % 10) + '0'));
            break;
        case HEX:
            for (int i = 12; i >= 0; i -= 4)
                this->print(HEX_DIGIT((n >> i) & 0x0F));
            break;
        default:
            break;
    }
}

void UART_Terminal::println(const uint16_t n, const uint8_t base)
{
    this->print(n, base);
    this->println();
}

void UART_Terminal::print(const uint32_t n, const uint8_t base)
{
    switch (base)
    {
        case BIN:
            for (int i = 31; i >= 0; i--)
                this->print((const char)(((n >> i) & 1) + '0'));
            break;
        case OCT:
            if (n > 07777777777) this->print((const char)(((n >> 30) & 7) + '0'));
            if (n > 0777777777)  this->print((const char)(((n >> 27) & 7) + '0'));
            if (n > 077777777)   this->print((const char)(((n >> 24) & 7) + '0'));
            if (n > 07777777)    this->print((const char)(((n >> 21) & 7) + '0'));
            if (n > 0777777)     this->print((const char)(((n >> 18) & 7) + '0'));
            if (n > 077777)      this->print((const char)(((n >> 15) & 7) + '0'));
            if (n > 07777)       this->print((const char)(((n >> 12) & 7) + '0'));
            if (n > 0777)        this->print((const char)(((n >> 9) & 7) + '0'));
            if (n > 077)         this->print((const char)(((n >> 6) & 7) + '0'));
            if (n > 07)          this->print((const char)(((n >> 3) & 7) + '0'));
            this->print((const char)((n & 7) + '0'));
            break;
        case DEC:
            if (n > 999999999) this->print((const char)(((n / 1000000000) % 10) + '0'));
            if (n > 99999999)  this->print((const char)(((n / 100000000) % 10) + '0'));
            if (n > 9999999)   this->print((const char)(((n / 10000000) % 10) + '0'));
            if (n > 999999)    this->print((const char)(((n / 1000000) % 10) + '0'));
            if (n > 99999)     this->print((const char)(((n / 100000) % 10) + '0'));
            if (n > 9999)      this->print((const char)(((n / 10000) % 10) + '0'));
            if (n > 999)       this->print((const char)(((n / 1000) % 10) + '0'));
            if (n > 99)        this->print((const char)(((n / 100) % 10) + '0'));
            if (n > 9)         this->print((const char)(((n / 10) % 10) + '0'));
            this->print((const char)((n % 10) + '0'));
            break;
        case HEX:
            for (int i = 28; i >= 0; i -= 4)
                this->print(HEX_DIGIT((n >> i) & 0x0F));
            break;
        default:
            break;
    }
}

void UART_Terminal::println(const uint32_t n, const uint8_t base)
{
    this->print(n, base);
    this->println();
}

void UART_Terminal::print(const char c, printType type)
{
    switch (type)
    {
        case INFO:
            this->print("\e[92m");
            break;
        case WARNING:
            this->print("\e[93m");
            break;
        case ERROR:
            this->print("\e[91m");
            break;
        default:
            break;
    }

    this->print(c);

    switch (type)
    {
        case INFO:
        case WARNING:
        case ERROR:
            this->print("\e[0m");
            break;
        default:
            break;
    }
}

void UART_Terminal::println(const char c, printType type)
{
    this->print(c, type);
    this->println();
}

void UART_Terminal::print(const char* s, printType type)
{
    while(*s)
        this->print(*s++, type);
}

void UART_Terminal::println(const char* s, printType type)
{
    this->print(s, type);
    this->println();
}

const uint8_t UART_Terminal::end(void)
{
    return (this->uart->end());
}
