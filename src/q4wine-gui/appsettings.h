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

#include "memory"

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <ui_AppSettings.h>

#include "config.h"

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSettings>
#include <QCheckBox>
#include <QDebug>
#include <QDir>

#include <q4wine-lib/main.h>

class AppSettings : public QDialog, public Ui::AppSettings
{
	Q_OBJECT
	public:
		AppSettings(QWidget * parent = 0, Qt::WFlags f = 0);

	private slots:
		void cmdCancel_Click();
		void cmdOk_Click();
		void comboProxyType_indexChanged(QString text);
		//! \brief cmdHelo click slot.
		void cmdHelp_Click();
		void radioDefault_toggled(bool state);
		void radioDefaultGui_toggled(bool state);
		void radioFuse_toggled(bool state);
		void radioEmbedded_toggled(bool state);

	private:
		bool eventFilter (QObject *object, QEvent *event);
		void getThemes(QString selTheme, QString themeDir);
		void getLangs();
		bool checkEntry(QString fileName, QString info, bool isFile = TRUE);
		void loadThemeIcons(QString themePath);
		QIcon loadIcon(QString iconName, QString themePath);

		//! This is need for libq4wine-core.so import.
		QLibrary libq4wine;
		typedef void *CoreLibPrototype (bool);
		CoreLibPrototype *CoreLibClassPointer;
		std::auto_ptr<corelib> CoreLib;

};

#endif

