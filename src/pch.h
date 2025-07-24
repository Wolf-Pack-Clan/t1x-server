/**************************************************************************/
/*  pch.h                                                                 */
/**************************************************************************/
/*                         This file is part of:                          */
/*                               T1X-Server                               */
/*             https://github.com/Wolf-Pack-Clan/t1x-server               */
/**************************************************************************/
/* Copyright (c) 2025 Wolf Pack                                           */
/*                                                                        */
/* This program is free software: you can redistribute it and/or modify   */
/* it under the terms of the GNU General Public License as published by   */
/* the Free Software Foundation, either version 3 of the License, or      */
/* (at your option) any later version.                                    */
/*                                                                        */
/* This program is distributed in the hope that it will be useful,        */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/* GNU General Public License for more details.                           */
/*                                                                        */
/* You should have received a copy of the GNU General Public License      */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/**************************************************************************/

#ifndef PCH_H
#define PCH_H

#include <arpa/inet.h> // sockaddr_in, inet_pton
#include <array>
#include <cmath>      // fabs, sqrt
#include <cstdio>     // printf, snprintf
#include <cstring>    // strcasecmp, strlen, strcmp, strerror, strncpy...
#include <dlfcn.h>    // dlsym
#include <execinfo.h> // backtrace
#include <map>        // make_tuple, get, array
#include <signal.h>   // signal
#include <sstream>    // ostringstream
#include <stdarg.h>   // va
#include <stdint.h>   // uint16_t
#include <stdlib.h>   // atoi
#include <string>
#include <sys/time.h> // gettimeofday
#include <unistd.h>   // access
#include <vector>

#endif
