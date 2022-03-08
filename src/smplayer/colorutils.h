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

#ifndef _COLORUTILS_H_
#define _COLORUTILS_H_

#include <QString>

class QWidget;
class QColor;

class ColorUtils {

public:

	//! Returns a string suitable to be used for -ass-color
//	static QString colorToRRGGBBAA(unsigned int color);
//	static QString colorToRRGGBB(unsigned int color);

	//! Returns a string suitable to be used for -colorkey
//	static QString colorToRGB(unsigned int color);

//	static QString colorToAABBGGRR(unsigned int color);

	//! Changes the foreground color of the specified widget
	static void setForegroundColor(QWidget * w, const QColor & color);

	//! Changes the background color of the specified widget
	static void setBackgroundColor(QWidget * w, const QColor & color);

    /**
     ** \brief Strip colors and tags from MPlayer output lines
     **
     ** Some MPlayer configurations (configured with --enable-color-console)
     ** use colored/tagged console output. This function removes those colors
     ** and tags.
     **
     ** \param s The string to strip colors and tags from
     ** \return Returns a clean string (no colors, no tags)
     */
    static QString stripColorsTags(QString s);

    static QString colorToRGB(QColor c);
    static QString colorToRRGGBBAA(QColor c);
    static QString colorToRRGGBB(QColor c);
    static QString colorToAABBGGRR(QColor c);
    static QString colorToAARRGGBB(QColor c);
    static QColor AARRGGBBToColor(const QString & s);
};

#endif
