/********************************************************************************************
 ** $File: debuglogger.h
 ** $Version: #1.0
 ** $DateTime: 22/09/2022
 ** $Description: Debug Logger to Set the Debug Logs
 ** $Author: Ibrahim Koicha
********************************************************************************************/
#include <iostream>

/***********************************************************************************
 ** $Macro Name:   DEBUG_LOG
 ** $Description:   displays debug log messages  with 4 levels
 ** $Parameters:   LOG_VAL, MSG
**********************************************************************************/
#define DEBUG_LOG(LOG_VAL, MSG)             \
    if (LOG_VAL == 1)                       \
    {                                       \
        cout << "INFO: " << MSG << endl;    \
    }                                       \
    if (LOG_VAL == 2)                       \
    {                                       \
        cout << "WARNING: " << MSG << endl; \
    }                                       \
    if (LOG_VAL == 3)                       \
    {                                       \
        cout << "FATAL: " << MSG << endl;   \
    }                                       \
    if (LOG_VAL == 4)                       \
    {                                       \
        cout << "DEBUG: " << MSG << endl;   \
    }

