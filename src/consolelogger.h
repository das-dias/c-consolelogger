/*
* ******************************************************************************
* *[author] Diogo André (git-hub : das-dias)
* *[date] 27-02-2022
* *[filename] consolelogger.h
* *[summary] Provides some console logging utilities including text colour formatting 
* *             depending on the message's nature (error - red , message - green);
MIT License

Copyright (c) 2022 Diogo André Silvares Dias

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
* ******************************************************************************
*/
#ifndef __CONSOLELOGGER_H__
#define __CONSOLELOGGER_H__

#pragma once

#include "lib/c-sformat/src/sformat.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void print_func_t(const char* data);

/**
* *[name] console
* *[description] Object structure holding the main colouring schemes
* *                 for the different types of messages to display
* *                 on console
* [variables]
* @par ERR_LOG (char*) : red colour escape code to print errors to console
* @par WARN_LOG (char*) : yellow colour escape code to print warnings to console
* @par MSG_LOG (char*) : green colour escape code to print messages to console
* @par DEFAULT_LOG (char*) : default terminal colour escape code to print to console
* @par _ESCAPE (char*) : escape code to print messages in another colour in console
* @par print_daga (print_func_t*) : main printing function to console
*/
typedef struct console
{
    char* ERR_LOG;
    char* WARN_LOG;
    char* MSG_LOG;
    char* DEFAULT_LOG;
    print_func_t* change_terminal_colour;
    print_func_t* print_string;
} console;

/**
* *[name] change terminal colour
* *[description] changes terminal text colour through escape strings
* ?[input]
* @par colour_code (char*) : code of the colour
* ![output]
* @par none (void)
*/
void change_terminal_colour(const char* colour_code);

/**
* *[name] print_string
* *[description] Printf wrapper to ignore variable number of possible arguments
* ?[input]
* @par string (char*) : string to output to console
* ![output]
* @par none (void)
*/
void print_string(const char* string);

/**
* *[name] console_log
* *[description] Logs out to console the string
* *                 painted in another colour
* ?[input]
* @par string (char*) : string of characters to output to console
* @par colour_code (char*) : escape code to colour the string
* @par default_code (char*) : escape code to return colour to default value
* ![output]
* @par none (void)
*/
void console_log(const char *string, const char* colour_code, const char* default_code);

/**
* *[name] console_alloc
* *[description] Console structure constructor
* ?[input]
* @par none (void)
* ![output]
* @par self (console*) : console object pointer
*/
console* console_alloc(void);

/**
* *[name] console_free
* *[description] Console object destructor
* ?[input]
* @par self (console*) : console object pointer
* ![output]
* @par none (void)
*/
void console_free(console* self);



/**
* *[name] console_error
* *[description] Logs a red error message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_error(console* self, const char* string);

/**
* *[name] console_warning
* *[description] Logs a yellow warning message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_warning(console* self, const char* string);

/**
* *[name] console_msg
* *[description] Logs a white default message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_msg(console* self, const char* string);

#endif //!__CONSOLELOGGER_H__