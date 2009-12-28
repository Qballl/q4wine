/***************************************************************************
 *   Copyright (C) 2008, 2009, 2010 by Malakhov Alexey                                 *
 *   brezerk@gmail.com                                                     *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 ***************************************************************************/

/*
 * NOTE: DO NOT EDIT THIS FILE!
 *
 * It will be rplaced by cmake
 *
 * Edit config.h.cmake instead
 */

#ifndef CONFIG_H
#define CONFIG_H

#define APP_NAME "Q4Wine"
#define APP_SHORT_NAME "q4wine"
#define APP_WEBSITTE "q4wine.brezblock.org.ua"
#define APP_BUG_EMAIL "brezerk@gmail.com"

#define APPDB_EXPORT_VERSION "0.1"
#define APPDB_HOSTNAME "appdb.winehq.org"
#define APPDB_PORT 80

#cmakedefine _OS_LINUX_
#cmakedefine _OS_FREEBSD_
#cmakedefine _OS_DARWIN_

#cmakedefine WITH_ICOUTILS
#cmakedefine WITH_DEVELOP_STUFF
#cmakedefine WITH_WINETRIKS
#cmakedefine WITH_EMBEDDED_FUSEISO
#cmakedefine WITH_WINEAPPDB

#cmakedefine DEBUG

/*
 * Note APP_VERS and APP_PREF automatycaly generates by cmake
 *
 * APP_VERS -- Application version
 * APP_PREF -- Application install prefix (Used for trak translations, help and thems files)
 */

