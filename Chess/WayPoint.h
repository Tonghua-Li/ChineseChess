#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QWidget>

class WayPoint : public QWidget
{
    Q_OBJECT
public:
    explicit WayPoint(QWidget *parent);
    void setPosition(int x, int y);
    QPoint position() const;
signals:
    void clicked(WayPoint *waypoint);
public slots:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QPoint _pos;
};

#endif // WAYPOINT_H
