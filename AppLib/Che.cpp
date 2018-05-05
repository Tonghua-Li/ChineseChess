#include "Che.h"

Che::Che(QObject *parent, Player player):
    ChessPiece(parent, player, "撤")
{
}

bool Che::canMoveTo(const IBoard *board, int x, int y) const
{
    auto destPlayer=board->getPieceOn(x,y);
    auto currentX = _position.x();
    auto currentY = _position.y();
    if(board->getPieceOn(x,y)==_player){return false;}

    if(currentX==x){
        if(currentY==y){return false;}
        int they=currentY;
        if(currentY>y){
            while(they>y){
                they--;
                if(they>y && board->getPieceOn(x,they)!=Player::None){return false;}
            }
        }
        else{
            while(they<y){
                they++;
                if(they<y && board->getPieceOn(x,they)!=Player::None){return false;}
            }
        }
    }
    else if(currentY==y){
        int thex=currentX;
        if(currentX>x){
            while(thex>x){
                thex--;
                if(thex>x && board->getPieceOn(thex,y)!=Player::None){return false;}
            }
        }
        else{
            while(thex<x){
                thex++;
                if(thex<x && board->getPieceOn(thex,y)!=Player::None){return false;}
            }
        }
    }
    else{return false;}
    return true;
}
