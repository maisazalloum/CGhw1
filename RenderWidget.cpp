//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//


#include "RenderWidget.h"
#include <QPainter>
#include <PPUViewer.cpp>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  

  myDrawCircel(500,300,60);
  myDrawParts(300, 300, 60);
  myDrawAcc(150, 150, 250, 250,180);
  myDrawLine(150, 150, 100, 100);

}


void RenderWidget::myDrawCircel(float x, float y, float r)
{
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(255, 0, 0);
    painter.setPen(color);

    float theta = 0;
    float PI = 180;
    while (theta < 2 * PI)
    {
        float x = x + r * cos(theta);
        float y = y + r * sin(theta);
        painter.drawPoint(round(x), round(y));
        theta = theta + (1 / r);
    }
    for (int x = 100; x < 300; x++) {
        painter.drawPoint(x, x);}
    }

void RenderWidget::myDrawParts(float x, float y, float r) {
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(255, 0, 0);
    painter.setPen(color);
    float Xc, Yc, r;
    float PI = 3.14159;
    for (int m = 0; m < 60; ++m) {
        float theta = m * 6 * PI / 180;

        float x1 = Xc + r * cos(theta);
        float y1 = Yc + r * sin(theta);

        if (m % 5)

            float x2 = Xc + r * 0.95 * cos(theta);
        float y2 = Yc + r * 0.95 * sin(theta);

        painter.drawLine(round(x1), round(y1), round(x2), round(y2));
    }

    //painter.drawPoint(x, y);
}

void RenderWidget::myDrawAcc(float a, float b, float theta1, float theta2, float r) {

    float theta = 0;
    float PI = 180;
   if ( theta1 <= 150 && theta2 <= 150)
    {
        float a = a + r * cos (theta1);
        float b = b + r * sin(theta2);
      
        painter.drawLine(round(a), round(b), round(theta1), round(theta2), round(r));
    }
   //painter.drawPoint(x, y);

}


void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(255, 0, 0);
    painter.setPen(color);

    float m = (y2 - y1) / (x2 - x1);
    //  SetPixel(x1, y1, color);   // first point
    painter.drawPoint(x1, y1);

    if (m < 1)
    {
        float y = y1;
        for (int i = x1 + 1; i < x2; ++i)
        {
            y = y + m;
            //      SetPixel(i, round(y), color);
            painter.drawPoint(i, round(y));
        }
    }
    else     // i.e., m > 1
    {
        float mm = 1 / m;
        float x = x1;
        for (int i = y1 + 1; i < y2; ++i)
        {
            x = x + mm;
            //      SetPixel(round(x), i, color);
            painter.drawPoint(round(x), i);
        }
    }

    //  SetPixel(x2, y2, color);   // last point
    painter.drawPoint(x2, y2);
}
