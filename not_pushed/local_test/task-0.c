#include <stdarg.h>
#include <unistd.h>

int my_vprintf(const char *format, va_list arg);

int my_putchar(int c) {
    char a[1];
    a[0] = (char)c;
    return write(0, a, 1);
}

int _printf(const char *format, ...) {
    va_list arg;
    int count;
    va_start(arg, format);
    count = my_vprintf(format, arg);
    va_end(arg);
    return count;
}

int my_vprintf(const char *format, va_list arg) {
    int count = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(arg, int);
                    my_putchar(c);
                    count++;
                    break;
                }
            }
        } else {
            my_putchar(*format);
            count++;
        }
        format++;
    }
    return count;
}

