#ifndef PRINTLN_H
#define PRINTLN_H

void println(const char *format, ...) {
	printf(format);
	printf("\n");
}

#endif