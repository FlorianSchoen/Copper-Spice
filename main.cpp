#include<QtCore>
#include<QtGui>

int main(int argc, char** argv){
	QApplication app(argc, argv);

	QWidget *mainWindow = new QWidget();
	mainWindow->setMinimumSize(700, 350);

	QPushButton *pb = new QPushButton();
	pb->setText("close");

	QPushButton *pb_1 = new QPushButton();
	pb_1->setText("FullSize");

	QPushButton *pb_2 = new QPushButton();
	pb_2->setText("NormalSize");

	QHBoxLayout *layout = new QHBoxLayout(mainWindow);
	layout->addStretch();
	layout->addWidget(pb);
	layout->addSpacing(10);
	layout->addWidget(pb_1);
	layout->addSpacing(10);
	layout->addWidget(pb_2);
	layout->addStretch();

	QObject::connect(pb, &QPushButton::clicked,
		mainWindow, &QWidget::close);
	QObject::connect(pb_1, &QPushButton::clicked, mainWindow, &QWidget::showFullScreen);
	QObject::connect(pb_2, &QPushButton::clicked, mainWindow, &QWidget::showNormal);

	mainWindow->show();
	
	return app.exec();
}
