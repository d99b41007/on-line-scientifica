#include "serial_port.h"
#include "commands.h"


#ifndef OPERATION_H
#define OPERATION_H

int Repeat_indentation(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_00(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_25(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_50(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_75(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_100(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_100_slow(HANDLE serialport,Patchstar patch, int i);
int Repeat_indentation_125(HANDLE serialport,Patchstar patch, int i);

int Repeat_indentation_100_nodelay(HANDLE serialport,Patchstar patch, int i);


int Position_Zero(HANDLE serialport,Patchstar patch);
int Position_report(HANDLE serialport,Patchstar patch);
int Indentation_200(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout);
int Indentation_200_slow(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout);
int Indentation_200_online(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout);
int Indentation_200_nodelay(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout);

int On_line_monitoring (HANDLE serialport,Patchstar patch,long n);
int Repeat_indentation_100_online(HANDLE serialport,Patchstar patch, int i);

#endif
