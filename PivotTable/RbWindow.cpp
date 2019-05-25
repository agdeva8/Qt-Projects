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
 * RbWindow.cpp
 *  Created on: 2016. 6. 14.
 */

#include "RbWindow.h"
#include <QtWidgets>
#include "RbTableHeaderView.h"

RbWindow::RbWindow(QWidget* parent):QWidget(parent)
{
		RbTableHeaderView* hHead = new RbTableHeaderView(Qt::Horizontal,3,4);
		RbTableHeaderView* vHead = new RbTableHeaderView(Qt::Vertical,4,3);
		QAbstractItemModel* hModel = hHead->model();
		QAbstractItemModel* vModel = vHead->model();
		QStandardItemModel* dataModel = new QStandardItemModel;

		hHead->setSpan(0,0,3,0);
		hHead->setSpan(0,1,2,2);
		hHead->setSpan(1,3,2,0);
		hModel->setData(hModel->index(0,0),QString("cell0"),Qt::DisplayRole);
		hModel->setData(hModel->index(0,1),QString("cell2"),Qt::DisplayRole);
		hModel->setData(hModel->index(2,1),QString("cell3"),Qt::DisplayRole);
		hModel->setData(hModel->index(2,2),QString("cell4"),Qt::DisplayRole);
		hModel->setData(hModel->index(0,3),QString("cell5"),Qt::DisplayRole);
		hModel->setData(hModel->index(1,3),QString("cell6"),Qt::DisplayRole);

		vHead->setSpan(0,0,0,3);
		vHead->setSpan(1,0,3,0);
		vHead->setSpan(1,1,2,0);
		vModel->setData(vModel->index(0,0),QString("cell1"),Qt::DisplayRole);
		vModel->setData(vModel->index(1,0),QString("cell2"),Qt::DisplayRole);
		vModel->setData(vModel->index(1,1),QString("cell3"),Qt::DisplayRole);
		vModel->setData(vModel->index(3,1),QString("cell4"),Qt::DisplayRole);
		vModel->setData(vModel->index(1,2),QString("cell5"),Qt::DisplayRole);
		vModel->setData(vModel->index(2,2),QString("cell6"),Qt::DisplayRole);
		vModel->setData(vModel->index(3,2),QString("cell7"),Qt::DisplayRole);

		hHead->setRowHeight(0,30);
		hHead->setRowHeight(1,30);
		hHead->setRowHeight(2,30);

		vHead->setRowHeight(0,30);
		vHead->setRowHeight(1,30);
		vHead->setRowHeight(2,30);
		vHead->setColumnWidth(0,50);
		vHead->setColumnWidth(1,50);
		vHead->setColumnWidth(2,50);

		hHead->setSectionsClickable(true);
		vHead->setSectionsClickable(true);

		hHead->setCellBackgroundColor(hModel->index(0,0),0xcfcfcf);
		hHead->setCellBackgroundColor(hModel->index(0,1),0xcfcfcf);
		vHead->setCellBackgroundColor(vModel->index(0,0),Qt::cyan);
		vHead->setCellBackgroundColor(vModel->index(1,0),0xcfcfcf);
		for (int i=0;i<4;i++)
		{
			QList<QStandardItem*> items;
			for (int j=0;j<4;j++)
			{
				items.append(new QStandardItem(QString("item(%1,%2)").arg(i).arg(j)));
			}
			dataModel->appendRow(items);
		}

		view = new QTableView(this);
		view->setModel(dataModel);
		view->setHorizontalHeader(hHead);
		view->setVerticalHeader(vHead);
		QVBoxLayout* layoutt = new QVBoxLayout;
		layoutt->addWidget(view);
		setLayout(layoutt);
		view->show();

		connect(hHead,SIGNAL(sectionPressed(int,int)),this,SLOT(horizontalHeaderSection_Pressed(int,int)));
		connect(vHead,SIGNAL(sectionPressed(int,int)),this,SLOT(verticalHeaderSection_Pressed(int,int)));
}

void RbWindow::horizontalHeaderSection_Pressed(int beginSection, int endSection)
{
	view->clearSelection();
	QAbstractItemView::SelectionMode oldSelectionMode = view->selectionMode();
	view->setSelectionMode(QAbstractItemView::MultiSelection);
	for (int i=beginSection;i<endSection+1;++i)
		view->selectColumn(i);
	view->setSelectionMode(oldSelectionMode);
}

void RbWindow::verticalHeaderSection_Pressed(int beginSection, int endSection)
{
	view->clearSelection();
	QAbstractItemView::SelectionMode oldSelectionMode = view->selectionMode();
	view->setSelectionMode(QAbstractItemView::MultiSelection);
	for (int i=beginSection;i<endSection+1;++i)
		view->selectRow(i);
	view->setSelectionMode(oldSelectionMode);
}

