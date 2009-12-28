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

#include "db.h"

DataBase::DataBase(){
   return;
}

bool DataBase::checkDb(const QStringList tables) const{
   /*
	* Checking database tables.
	* If not exists, we try to create them.
	*/

   QSqlDatabase db = QSqlDatabase::database();
   QSqlQuery query;
   QString table="";

   for (int i=0; i<tables.size(); ++i){
	table=tables.at(i).toLocal8Bit().constData();

	if (db.record(table).isEmpty()){
	   if (table == "prefix"){
		if(!query.exec("CREATE TABLE prefix (wine_dllpath TEXT, wine_loader TEXT, wine_server TEXT, wine_exec TEXT, cdrom_mount TEXT, cdrom_drive TEXT, id INTEGER PRIMARY KEY, name TEXT, path TEXT, version TEXT);"))
		   return FALSE;

		   // Creating default prefix reccord
		   query.prepare("INSERT INTO prefix(id, name) VALUES(NULL, :name);");
		   query.bindValue(":name", "Default");
		   if (!query.exec())
			return FALSE;
		   query.clear();
	   }
	   if (table == "dir"){
		if(!query.exec("CREATE TABLE dir (id INTEGER PRIMARY KEY, name TEXT, prefix_id NUMERIC);"))
		   return FALSE;
	   }
	   if (table == "icon"){
		if(!query.exec("CREATE TABLE icon (wrkdir TEXT, override TEXT, winedebug TEXT, useconsole NUMERIC, display TEXT, cmdargs TEXT, exec TEXT, icon_path TEXT, desc TEXT, desktop TEXT, nice TEXT, dir_id NUMERIC, id INTEGER PRIMARY KEY, name TEXT, prefix_id NUMERIC);"))
		   return FALSE;
	   }
	   if (table == "images"){
		if(!query.exec("CREATE TABLE images (id INTEGER PRIMARY KEY, name TEXT, path TEXT);"))
		   return FALSE;
	   }
	   if (table == "last_run_icon"){
		if(!query.exec("CREATE TABLE last_run_icon (wrkdir TEXT, override TEXT, winedebug TEXT, useconsole NUMERIC, display TEXT, cmdargs TEXT, exec TEXT, desktop TEXT, nice TEXT, id INTEGER PRIMARY KEY);"))
		   return FALSE;
	   }
	}
   }

   return TRUE;
}

void DataBase::close(){
   QSqlDatabase db = QSqlDatabase::database();
   db.close();
   return;
}
