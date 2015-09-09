#include <windows.h>
#include <iostream>
#include "serial_port.h"
using namespace std;


void* open_commport()
 {
         cout << "Prepare for connection" << endl;

      HANDLE hSerial;
      DCB dcbSerialParams ={0};

        hSerial = CreateFile("COM7",
                             GENERIC_READ | GENERIC_WRITE,
                             0,
                             0,
                             OPEN_EXISTING,
                             FILE_ATTRIBUTE_NORMAL,
                             0
                             );
        if(hSerial==INVALID_HANDLE_VALUE) {
          if(GetLastError()==ERROR_FILE_NOT_FOUND){
          //serial port does not exist. Inform user.
           cout << "No serial port connected." << endl;
          }
          //some other error occurred.
        }
        else {
        cout << "COM port connected." << endl;
        }



        dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

        if (!GetCommState(hSerial, &dcbSerialParams)) {
        //error getting stetes
        cout << "no dcb state acquired." << endl;
        }

        dcbSerialParams.BaudRate=CBR_9600;
        dcbSerialParams.ByteSize=8;
        dcbSerialParams.StopBits=ONESTOPBIT;
        dcbSerialParams.Parity=NOPARITY;

        if(!SetCommState(hSerial, &dcbSerialParams)){
        //error setting serial port stete.
         cout << "cant' get serial port stete" << endl;
        }

        cout << "Statue of this commport:" << endl;
        cout << "length=" << dcbSerialParams.DCBlength << endl;
        cout << "BaudRate=" << dcbSerialParams.BaudRate << endl;
        cout << "StopBits=" << dcbSerialParams.StopBits << endl;
        cout << "Parity=" << dcbSerialParams.Parity << endl;

        COMMTIMEOUTS timeouts={1000};

        timeouts.ReadIntervalTimeout=10;
        timeouts.ReadTotalTimeoutConstant=20;
        timeouts.ReadTotalTimeoutMultiplier=20;
        timeouts.WriteTotalTimeoutConstant=100;
        timeouts.WriteTotalTimeoutMultiplier=20;

        if(!SetCommTimeouts(hSerial, &timeouts)){
        //error occureed. Inform user

         cout << "timeout setting error plz check." << endl;
        }
        else {
        cout << "Read IntervalTimeout=" << timeouts.ReadIntervalTimeout << endl;
        cout << "Read TotalTimeoutConstant=" << timeouts.ReadTotalTimeoutConstant << endl;
        cout << "Read ReadtotalTimeoutconstant=" << timeouts.ReadTotalTimeoutMultiplier << endl;
        cout << "Write TotalTimeoutCounstant=" << timeouts.WriteTotalTimeoutConstant << endl;
        cout << "Write TotalTimeoutMultiplier=" << timeouts.WriteTotalTimeoutMultiplier << endl;
        }

    cout << "port=" << hSerial << endl;

    return hSerial;
 }
