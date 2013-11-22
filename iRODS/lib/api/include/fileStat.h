/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* fileStat.h - This file may be generated by a program or script
 */

#ifndef FILE_STAT_H
#define FILE_STAT_H

/* This is a low level file type API call */

#include "rods.h"
#include "rcMisc.h"
#include "procApiRequest.h"
#include "apiNumber.h"
#include "initServer.h"

#include "fileDriver.h"

typedef struct {
    rodsHostAddr_t addr;
    char fileName[MAX_NAME_LEN];
    char rescHier[MAX_NAME_LEN];
    char objPath[MAX_NAME_LEN];
} fileStatInp_t;
    
#define fileStatInp_PI "struct RHostAddr_PI; str fileName[MAX_NAME_LEN]; str rescHier[MAX_NAME_LEN]; str objPath[MAX_NAME_LEN];"

#if defined(RODS_SERVER)
#define RS_FILE_STAT rsFileStat
/* prototype for the server handler */
int
rsFileStat (rsComm_t *rsComm, fileStatInp_t *fileStatInp, 
            rodsStat_t **fileStatOut);
int
_rsFileStat (rsComm_t *rsComm, fileStatInp_t *fileStatInp,
             rodsStat_t **fileStatOut);
int
rsFileStatByHost (rsComm_t *rsComm, fileStatInp_t *fileStatInp,
                  rodsStat_t **fileStatOut, rodsServerHost_t *rodsServerHost);
int
remoteFileStat (rsComm_t *rsComm, fileStatInp_t *fileStatInp,
                rodsStat_t **fileStatOut, rodsServerHost_t *rodsServerHost);
#else
#define RS_FILE_STAT NULL
#endif

/* prototype for the client call */
int
rcFileStat (rcComm_t *conn, fileStatInp_t *fileStatInp, 
            rodsStat_t **fileStatOut);

#endif  /* FILE_STAT_H */
