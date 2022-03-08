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

    Note: The ShortcutGetter class is taken from the source code of Edyuk
    (http://www.edyuk.org/), from file 3rdparty/qcumber/qshortcutdialog.cpp

    Copyright (C) 2006 FullMetalCoder
    License: GPL

    I modified it to support multiple shortcuts and some other few changes.
*/


#ifndef SHORTCUTGETTER_H
#define SHORTCUTGETTER_H

#include "../utils.h"

#include <QDialog>
#include <QListWidget>

class QLineEdit;


class ShortcutGetter : public QDialog
{
	Q_OBJECT

public:
    ShortcutGetter(/*bool isbtn = false, */QWidget *parent = 0);

	QString exec(const QString& s);

protected slots:
	void setCaptureKeyboard(bool b);
	void rowChanged(int row);
	void textChanged(const QString & text);

	void addItemClicked();
	void removeItemClicked();

protected:
	bool captureKeyboard() { return capture; };

	bool event(QEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
	void setText();
//    virtual bool eventFilter(QObject *, QEvent *);
//    void moveDialog(QPoint diff);

private:
    bool bStop;
	QLineEdit *leKey;
	QStringList lKeys;
	bool capture;
    QWidget *m_centerWidget;

	QListWidget * list;
	QPushButton * addItem;
	QPushButton * removeItem;
    QPushButton *closeBtn;
    DragState m_dragState;
    QPoint m_startDrag;
};

#endif
