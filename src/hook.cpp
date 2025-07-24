/**************************************************************************/
/*  hook.cpp                                                              */
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

#include "hook.h"

void hook_jmp(int from, int to)
{
    int relative = to - (from + 5);          // +5 is the position of next opcode
    memset((void*)from, 0xE9, 1);            // JMP-OPCODE
    memcpy((void*)(from + 1), &relative, 4); // set relative address with endian
}

void hook_call(int from, int to)
{
    int relative = to - (from + 5);          // +5 is the position of next opcode
    memcpy((void*)(from + 1), &relative, 4); // set relative address with endian
}

void hook_nop(int from, int to)
{
    // See
    // https://github.com/xtnded/codextended/blob/855df4fb01d20f19091d18d46980b5fdfa95a712/src/util.h#L111
    int len;
    if (to < from)
        len = to;
    else
        len = to - from;
    memset((void*)from, 0x90, len);
}

cHook::cHook(int from, int to)
{
    this->from = from;
    this->to = to;
}

void cHook::hook()
{
    memcpy((void*)oldCode, (void*)from, 5);
    hook_jmp(from, to);
}

void cHook::unhook()
{
    memcpy((void*)from, (void*)oldCode, 5);
}
