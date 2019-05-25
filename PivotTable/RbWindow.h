/* Copyright 2016 Lee Cho Kang.
* email: pzesseto@gmail.com
* This file is part of the RbTableHeaderView.
*
* The RbTableHeaderView is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* The RbTableHeaderView is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with the RbTableHeaderView. If not, see http://www.gnu.org/licenses/.
*/
/*
 * RbWindow.h
 *  Created on: 2016. 6. 14.
 */

#ifndef RBWINDOW_H_
#define RBWINDOW_H_

#include <QWidget>
class QTableView;
class RbWindow : public QWidget
{
	Q_OBJECT
public:
	RbWindow(QWidget* parent=0);
	virtual ~RbWindow() { };

	// slot for sectionPressed(int from, int to) signal from RbTableHeaderView, this allow multiple sections to be selected by a span section
	protected Q_SLOTS:
	void horizontalHeaderSection_Pressed(int beginSection, int endSection);
	void verticalHeaderSection_Pressed(int beginSection, int endSection);

	private:
	QTableView* view;
};

#endif /* RBWINDOW_H_ */
