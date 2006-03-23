/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

	$Id: qwsvdef.h,v 1.11 2006/03/23 14:10:35 disconn3ct Exp $
*/
// qwsvdef.h -- primary header for server

#ifndef __QWSVDEF_H__
#define __QWSVDEF_H__

//define PARANOID // speed sapping error checking

#ifdef _WIN32
#pragma warning( disable : 4244 4127 4201 4214 4514 4305 4115 4018)
#endif

#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <ctype.h>
#include <assert.h>

//#include "bothdefs.h" - included in common.h

#include "common.h"
#include "bspfile.h"
#include "sys.h"
#include "zone.h"
#include "mathlib.h"

#include "cvar.h"
#include "net.h"
#include "protocol.h"
#include "cmd.h"

#include "model.h"

#include "crc.h"
#include "sha1.h"

#include "server.h"
#include "world.h"
#include "pmove.h"
#include "log.h"

#include "pcre/pcre.h"

#ifdef USE_PR2
// Angel -->
#include "pr2_vm.h"
#include "pr2.h"
// <-- Angel
#endif

//=============================================================================

// the host system specifies the base of the directory tree, the
// command line parms passed to the program, and the amount of memory
// available for the program to use

typedef struct
{
	int	argc;
	char	**argv;
	void	*membase;
	int	memsize;
} quakeparms_t;


//=============================================================================

typedef struct
{
	int sec;
	int min;
	int hour;
	int day;
	int mon;
	int year;
	char str[128];
} date_t;
void SV_TimeOfDay(date_t *date);

extern	quakeparms_t host_parms;

extern	cvar_t	sys_nostdout;
extern	cvar_t	developer;

extern	qboolean host_initialized; // true if into command execution
extern	double	realtime; // not bounded in any way, changed at start of every frame, never reset

void SV_Error (char *error, ...);
void SV_Init (quakeparms_t *parms);

void Con_Printf (char *fmt, ...);
void Con_DPrintf (char *fmt, ...);

#endif //__QWSVDEF_H__
