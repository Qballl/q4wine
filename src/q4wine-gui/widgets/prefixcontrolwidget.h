/***************************************************************************
 *   Copyright (C) 2008, 2009, 2010 by Malakhov Alexey                            *
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

#ifndef PREFIXCONTROLWIDGET_H
#define PREFIXCONTROLWIDGET_H

#include "config.h"
#include "memory"

#include "src/core/database/prefix.h"
#include "src/core/database/dir.h"
#include "src/core/database/icon.h"

#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <QTableView>
#include <QSqlQueryModel>

#include <QIcon>
#ifdef DEBUG
#include <QDebug>
#endif

#include "wizard.h"
#include "prefixsettings.h"
#include "process.h"

#include <q4wine-lib/main.h>

class PrefixControlWidget : public QWidget
{
Q_OBJECT
public:
	explicit PrefixControlWidget(QString themeName, QWidget *parent = 0);

signals:

public slots:

private:
	QString themeName;

	//! This is need for libq4wine-core.so import.
	QLibrary libq4wine;
	typedef void *CoreLibPrototype (bool);
	CoreLibPrototype *CoreLibClassPointer;
	std::auto_ptr<corelib> CoreLib;

	void createActions();
	QIcon loadIcon(QString iconName);

	std::auto_ptr<QSqlQueryModel> model;

	std::auto_ptr<QTableView> prefixTable;
	std::auto_ptr<QMenu> menu;
	std::auto_ptr<QAction> prefixAdd;
	std::auto_ptr<QAction> prefixDelete;
	std::auto_ptr<QAction> prefixSettings;
	std::auto_ptr<QAction> prefixImport;
	std::auto_ptr<QAction> prefixExport;

	void updateTableModel(void);

	// Database classes
	Prefix db_prefix;
	Dir db_dir;
	Icon db_icon;

private slots:
	void customContextMenuRequested(const QPoint &pos);
	void itemClicked(const QModelIndex &);

	void prefixAdd_Click(void);
	void prefixDelete_Click(void);
	void prefixExport_Click(void);
	void prefixImport_Click(void);
	void prefixSettings_Click(void);

signals:
	void updateDatabaseConnections();
};

#endif // PREFIXCONTROLWIDGET_H