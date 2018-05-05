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

    void drawBackground(QPainter &painter);

signals:

public slots:
    void onPieceSelected(PieceView *pieceView);
    void onWayPointClicked(WayPoint *wayPoint);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private:

    void createWayPoints();
    void createPieceViews(ChessBoard* board);

    const int HEIGHT = 11 * (PieceView::SIZE);
    const int WIDTH = 10* (PieceView::SIZE);
    const int V_LINE_COUNT = 9;
    const int H_LINE_COUNT = 10;
    QList<WayPoint*> _wayPoints;
    QList<PieceView*> _pieceViews;

    ChessBoard* _board;

};

#endif // BOARDVIEW_H
