#ifndef MODEM_HANDLER_H
#define MODEM_HANDLER_H

void modemInit();

bool sendATCommand(const char* command, unsigned long timeout);

#endif