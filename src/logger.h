#ifndef LOGGER_H
#define LOGGER_H

void logger_init(void);
void log(const char* msg);
void log(String msg);
void log(const char* msg, const char* arg);
void log(const char* msg, int arg);

#endif
