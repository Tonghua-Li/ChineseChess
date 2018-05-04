#include "WayPoint.h"
#include "PieceView.h"

#include <QPainter>
#include <QStyleOption>
WayPoint::WayPoint(QWidget *parent) : QWidget(parent)
{
    auto size = PieceView::SIZE/2;
    this->resize(size,size);
    this->setStyleSheet("background-color: transparent");
}

void WayPoint::setPosition(int x, int y)
{
    auto size = PieceView::SIZE/2;
    this->move((x+1)*PieceView::SIZE-size/2, (y+1)*PieceView::SIZE-size/2);
    _pos = QPoint(x, y);
}

QPoint WayPoint::position() const
{
    return _pos;
}


void WayPoint::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void WayPoint::mousePressEvent(QMouseEvent *event)
{
    this->setStyleSheet("background-color: green");
    emit clicked(this);
}

void WayPoint::mouseReleaseEvent(QMouseEvent *event)
{
    this->setStyleSheet("background-color: transparent");
}
