/***********************************************************************
*
* Copyright (c) 2021-2022 Barbara Geller and Ansel Sermersheim
*
* This example is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <QtCore>
#include <QtGui>


int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   auto my_colour = Qt::yellow;
  
   const int size_1 = 0;

   QWidget *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);

   QPushButton *pb_1 = new QPushButton();
   pb_1->setText("Show Colors");

   QPushButton *pb_2 = new QPushButton();
   pb_2->setText("Close");

   QSlider *s_1 = new QSlider();
   s_1->singleStep();

   QProgressBar *pgb_1 = new QProgressBar();
   pgb_1->setMaximum(95);
   pgb_1->setMinimum(5);
   pgb_1->setValue(5);

   QLineEdit *l_1 = new QLineEdit();
   l_1->setSelection(50, 50);
   
   QCheckBox *cb_1 = new QCheckBox();  

   QSpinBox *sb_1 = new QSpinBox();
   sb_1->setValue(20); 

   QHBoxLayout *layout = new QHBoxLayout(mainWindow);
   layout->addStretch();
  // layout->addWidget(pb_1);
  // layout->addSpacing(10);
   layout->addWidget(pb_2);
   layout->addSpacing(10);
   layout->addWidget(pgb_1);
  /* layout->addSpacing(10);
   layout->addWidget(l_1);
   layout->addSpacing(10);
   layout->addWidget(cb_1);
   layout->addSpacing(10);
   layout->addWidget(sb_1);*/
   layout->addSpacing(10);
   layout->addWidget(s_1);
   layout->addStretch();

   //QObject::connect(pb_1, &QPushButton::clicked, pb_1, [my_colour] () { QColorDialog::getColor(my_colour);  } );
   QObject::connect(pb_2, &QPushButton::clicked, mainWindow, &QWidget::close);
   QObject::connect(s_1, &QSlider::valueChanged, pgb_1, &QProgressBar::setValue);   
   //QObject::connect(cb_1, &QCheckBox::clicked, pgb_1, &QProgressBar::showMaximized);

   mainWindow->show();

   return app.exec();
}

