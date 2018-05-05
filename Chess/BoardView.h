#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include "PieceView.h"
#include "WayPoint.h"
#include "ChessBoard.h"
class BoardView : public QWidget
{
    Q_OBJECT
public:
    explicit BoardView(QWidget *parent = nullptr);



signals:

public slots:
    void onPieceViewClicked(PieceView *pieceView);
    void onWayPointClicked(WayPoint *wayPoint);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private:
    void drawBackground(QPainter &painter);
    void createWayPoints();
    void refreshBoard();

    const int HEIGHT = 11 * (PieceView::SIZE);
    const int WIDTH = 10* (PieceView::SIZE);
    const int V_LINE_COUNT = 9;
    const int H_LINE_COUNT = 10;
    QList<WayPoint*> _wayPoints;
    QList<PieceView*> _pieceViews;

    ChessBoard* _board;

};

#endif // BOARDVIEW_H
