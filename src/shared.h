/**************************************************************************/
/*  shared.h                                                              */
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

#ifndef SHARED_H
#define SHARED_H

#include "pch.h"
#include "types.h"
#include "functions.h"

xfunction_t Scr_GetCustomFunction(const char** fname, qboolean* fdev);
xmethod_t Scr_GetCustomMethod(const char** fname, qboolean* fdev);

void Scr_CodeCallback_Error(qboolean terminal, qboolean emit, const char* internal_function, char* message);

void sendMessageToClient_orServerConsole(client_t* cl, std::string message);

// void free_sqlite_db_stores_and_tasks();

#endif
