#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePoints()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    static QVector<QPoint> originalPoints;
    static QVector<QPoint> currentPoints;
  
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(50,height()-1/2);

    QPen pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);

  
    if (originalPoints.empty())
    {
        QPoint point(0,0);
        for (int i = 0; i < 100; i++) {
            if (i % 2 == 0) {
                point += QPoint(1,-15);
            } else {
                point += QPoint(15,0);
            }
            originalPoints.append(point);
        }
        currentPoints = originalPoints;
    }

    
    static QTimer timer;
    timer.setInterval(3000);
    connect(&timer, &QTimer::timeout, this, [=]()
    {
        if (currentPoints.size() > 0)
        {
            currentPoints.removeFirst();
            update();
        } else {
            timer.stop();
        }
    });
    if (!timer.isActive())
    {
        timer.start();
    }

   
    painter.drawPolyline(currentPoints);
    painter.end();
}
