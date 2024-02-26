/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2014 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../pinc.h"

PCL void OnInfoRequest(pluginInfo_t *info) {
    // =====  MANDATORY FIELDS  =====
    info->handlerVersion.major = PLUGIN_HANDLER_VERSION_MAJOR;
    info->handlerVersion.minor = PLUGIN_HANDLER_VERSION_MINOR;
}

void PlayerCmd_GetIP() {
    char adrstr[128];
    client_t* cl = Plugin_SV_Cmd_GetPlayerClByHandle(Plugin_Scr_GetString(0));

    if (cl == NULL) {
        return;
    }

    Plugin_NET_AdrToStringMT(&cl->netchan.remoteAddress, adrstr, sizeof(adrstr));
    Plugin_Scr_AddString(adrstr);
}

PCL int OnInit() {
    Plugin_ScrAddFunction("getIP", &PlayerCmd_GetIP);
    return 0;
}
