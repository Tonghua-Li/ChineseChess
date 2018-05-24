#include "Shuai.h"
#include<math.h>

Shuai::Shuai(QObject *parent, Player player,int x,int y)
    : ChessPiece(parent, player, player==Player::Black? "將":"帥", x, y,7)
{}

bool Shuai::canMoveTo(const IBoard *board, int x, int y) const
{
    auto destplayer=board->getPlayer(x,y);
    int destid=board->getPieceId(x,y);
    auto currentx=_position.x();
    auto currenty=_position.y();
    if(currentx!=x && currenty!=y){return false;}
    if(currentx==x){
        int starty=std::min(currenty,y);
        int endy=std::max(currenty,y);
        if(endy>starty+1 && destid==7){
            int count=0;
            for(int i=starty+1;i<endy;++i){
                if(board->getPlayer(x,i)!=Player::None){++count;}
            }
            if(count==0){return true;}
        }
    }
    if(!board->isInsidePalace(_player,x,y)){return false;}
    int dist=abs(x-currentx)+abs(y-currenty);
    if(dist==1 && destplayer!=_player){return true;}
    return false;
}
