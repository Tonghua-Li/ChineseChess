#include "PieceView.h"

#include <QPainter>
#include <QTime>

PieceView::PieceView(QWidget *parent) : QWidget(parent),
    _currentBrush(QBrush(Qt::darkYellow))
{
    this->resize(SIZE, SIZE);
}

void PieceView::movePosition(const QPoint &pos)
{
    this->movePosition(pos.x(), pos.y());
}

void PieceView::movePosition(int x, int y)
{
    this->move(x*SIZE+SIZE/2, y*SIZE+SIZE/2);
}

void PieceView::select()
{
    _currentBrush = QBrush(Qt::blue);
    _isSelected = true;
    repaint();
}

void PieceView::unselect()
{
    _currentBrush = QBrush(Qt::darkYellow);
    _isSelected = false;
    repaint();
}

void PieceView::paintEvent(QPaintEvent *event) {

  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing);
  int borderThickness = 1;
  QPen pen(Qt::black, borderThickness);
  painter.setPen(pen);
  painter.setBrush(_currentBrush);

  painter.drawEllipse(0, 0, SIZE-borderThickness, SIZE-borderThickness);

  QWidget::paintEvent(event);
}

void PieceView::mousePressEvent(QMouseEvent *event)
{
    emit selected(this);
}
