/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2015 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _FILESETTINGS_H_
#define _FILESETTINGS_H_

#include <QString>

class QSettings;
class MediaSettings;

class FileSettings
{
public:
    FileSettings(QString directory);
	virtual ~FileSettings();

    virtual bool existSettingsFor(QString filename, int type);

    virtual void loadSettingsFor(QString filename, int type, MediaSettings & mset, int player);

    virtual void saveSettingsFor(QString filename, int type, MediaSettings & mset, int player);

    static QString filenameToGroupname(const QString & filename, int type);


protected:
    QString output_directory;

private:
	QSettings * my_settings;
};

#endif

