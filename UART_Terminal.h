#ifndef __UART_TERMINAL_H__
#define __UART_TERMINAL_H__

/* Dependencies */
#include <avr/pgmspace.h>
#include <UART.h>

/* Macros */
#define UART_TERMINAL_NEW_LINE_CAHR (const char)'\n'
#ifndef BIN
#define BIN (const uint8_t)2
#endif
#ifndef OCT
#define OCT (const uint8_t)8
#endif
#ifndef DEC
#define DEC (const uint8_t)10
#endif
#ifndef HEX
#define HEX (const uint8_t)16
#endif
#define HEX_DIGIT(digit) ((digit) < 10 ? (const char)((digit) + '0') : (const char)((digit) - 10 + 'A'))

class UART_Terminal
{
    public:
        UART_Terminal(__UART__* uart);
        ~UART_Terminal();
        const uint8_t begin    (const uint32_t baudrate);
        const uint8_t available(void);
        void          flush    (void);
        const uint8_t isTransmitting(void);
        const char    read     (void);
        void          println  (void);
        void          print    (const char c);
        void          println  (const char c);
        void          print    (const char* s);
        void          println  (const char* s);
        void          printP   (const char* s);
        void          printPln (const char* s);
        void          print    (const uint8_t n, const uint8_t base = DEC);
        void          println  (const uint8_t n, const uint8_t base = DEC);
        void          print    (const uint16_t n, const uint8_t base = DEC);
        void          println  (const uint16_t n, const uint8_t base = DEC);
        void          print    (const uint32_t n, const uint8_t base = DEC);
        void          println  (const uint32_t n, const uint8_t base = DEC);
        const uint8_t end      (void);  
    private:
        __UART__* uart;
};

#endif
