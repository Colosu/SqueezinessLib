/*=============================================================================*\
 * File: gfsmError.c
 * Author: Bryan Jurish <moocow.bovine@gmail.com>
 * Description: finite state machine library
 *
 * Copyright (c) 2004 Bryan Jurish.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *=============================================================================*/

#include <gfsmError.h>
#include <stdlib.h>

/*======================================================================
 * Error Utilties
 */
/*--------------------------------------------------------------
 * carp_named()
 */
void gfsm_carp_named(gfsmError *error, const gchar *myname)
{
  if (!error) return;
  g_printerr("%s: %s\n", (myname ? myname : "gfsm"), error->message);
}

/*--------------------------------------------------------------
 * die_named()
 */
void gfsm_die_named(gfsmError *error, const gchar *myname)
{
  if (!error) return;
  g_printerr("%s: %s\n", (myname ? myname : "gfsm"), error->message);
  exit(error->code);
}
