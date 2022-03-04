/*
* ******************************************************************************
* *[author] Diogo André (git-hub : das-dias)
* *[date] 27-02-2022
* *[filename] libconsolelogger.c
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
#include "consolelogger.h"
/**
* *[name] change terminal colour
* *[description] changes terminal text colour through escape strings
* ?[input]
* @par colour_code (char*) : code of the colour
* ![output]
* @par none (void)
*/
void change_terminal_colour(const char* colour_code)
{
    printf("\033%s",colour_code);
}

/**
* *[name] print_string
* *[description] Printf wrapper to ignore variable number of possible arguments
* ?[input]
* @par string (char*) : string to output to console
* ![output]
* @par none (void)
*/
void print_string(const char* string)
{
    printf("%s",string);
}

/**
* *[name] console_log
* *[description] Logs out to console the string
* *                 painted in another colour
* ?[input]
* @par string (char*) : string of characters to output to console
* @par escape_colour_code (char*) : escape code to colour the string
* @par escape_default_code (char*) : escape code to return colour to default value
* ![output]
* @par none (void)
*/
void console_log(const char *string, const char* colour_code, const char* default_code){
    change_terminal_colour(colour_code);
    print_string(string);
    change_terminal_colour(default_code);
}

/**
* *[name] console_alloc
* *[description] Console structure constructor
* ?[input]
* @par none (void)
* ![output]
* @par self (console*) : console object pointer
*/
console* console_alloc(void)
{
    console* self = malloc(sizeof *self);
    self->DEFAULT_LOG = (char *) malloc(sizeof(char)*4);
    strcpy(self->DEFAULT_LOG,"[0m");
    self->ERR_LOG = (char*) malloc(sizeof(char)*7);
    strcpy(self->ERR_LOG, "[0;31m");
    self->WARN_LOG = (char*) malloc(sizeof(char)*7);
    strcpy(self->WARN_LOG, "[0;33m");
    self->MSG_LOG = (char*) malloc(sizeof(char)*7);
    strcpy(self->MSG_LOG, "[0;37m");
    self->print_string = malloc(sizeof self->print_string);
    self->print_string = print_string;
    self->print_string = malloc(sizeof self->change_terminal_colour);
    self->change_terminal_colour = change_terminal_colour;
    return self;
}

/**
* *[name] console_free
* *[description] Console object destructor
* ?[input]
* @par self (console*) : console object pointer
* ![output]
* @par success (int) : 1 if successful, 0 if not
*/
void console_free(console* self)
{
    if(self != NULL) free(self);
}

/**
* *[name] console_error
* *[description] Logs a red error message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_error(console* self, const char* string)
{
    console_log( string , self->ERR_LOG, self->DEFAULT_LOG);
}

/**
* *[name] console_warning
* *[description] Logs a yellow warning message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_warning(console* self, const char* string)
{
    console_log( string , self->WARN_LOG, self->DEFAULT_LOG);
}

/**
* *[name] console_msg
* *[description] Logs a white default message to console
* ?[input]
* @par self (console*) : console object pointer
* @par string (const char*) : message to write to console
* ![output]
* @par none (void)
*/
void console_msg(console* self, const char* string)
{
    console_log( sformat(string) , self->MSG_LOG, self->DEFAULT_LOG);
}