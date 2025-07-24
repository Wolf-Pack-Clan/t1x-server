/**************************************************************************/
/*  gsc_player.cpp                                                        */
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

#include "gsc.h"
#ifdef DEBUG
// #include <fmt/format.h>
#endif

void gsc_player_processclientcommand(scr_entref_t ref)
{
    int id = ref.entnum;

    if (id >= MAX_CLIENTS) {
        stackError("gsc_player_processclientcommand() entity %i is not a player", id);
        Scr_AddUndefined();
        return;
    }

    ClientCommand(id);

    Scr_AddBool(qtrue);
}

void gsc_player_connectionlesspackettoclient(scr_entref_t ref)
{
    printf("########## gsc_player_connectionlesspackettoclient: I have been summoned\n");
    int id = ref.entnum;
    char* cmd;

    if (!stackGetParams("s", &cmd)) {
        stackError("gsc_player_connectionlesspackettoclient() argument is undefined or has a "
                   "wrong type");
        Scr_AddUndefined();
        return;
    }
    printf("########## gsc_player_connectionlesspackettoclient: after getting params\n");

    if (id >= MAX_CLIENTS) {
        stackError("gsc_player_connectionlesspackettoclient() entity %i is not a player", id);
        Scr_AddUndefined();
        return;
    }

    client_t* client = &svs.clients[id];
#ifdef DEBUG
    // printf("id: %d, player: %s\n, netchan: %d\n", id, client->name,
    // client->netchan.remoteAddress.type);
#endif
    NET_OutOfBandPrint(NS_SERVER, client->netchan.remoteAddress, cmd);

    Scr_AddBool(qtrue);
}
