#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <unistd.h>


#include <stdio.h>
#include <stdlib.h>
using namespace std;


class Piece
{
    public :char type;
    public :int row;
    public :int col;
    public :Piece(char t, int r, int c) 
    {
        type=t;
        row=r-1;
        col=c-1;
    }
    public :void dump()
    {
        cout << "Piece of type'"<<this->type<<"' in position ["<<this->row<<","<<this->col<<"]\n";
    }
    public :string toString()
    {
        std::stringstream sstm;
        sstm << "Piece of type'"<<this->type<<"' in position ["<<this->row<<","<<this->col<<"]";
        string result = sstm.str();
        return result;
    }
    
};

class Position
{

    vector <vector <char> > board;

    
    vector<Piece*> pieces;
    int rows;
    int cols;

    public :Position(int rows, int cols)
    {
        this->rows=rows;
        this->cols=cols;
        this->board.resize(rows);
        int i;
        for(i=0;i<this->board.size();i++)
        {
            this->board[i].resize(cols);
        }
    }
    
    
    public :void computeThreatenedSquares()
    {
        int i,j;
        //empty board
        for(i=0;i< this->board.size();i++)
        {
            for(j=0;j< this->board[i].size();j++)
            {
               this->board[i][j]=' ';
            }
        }
        //fill with pieces
        for(i=0;i<this->pieces.size();i++)
        {
            Piece * p=pieces[i];
            this->board[p->row][p->col]=p->type;
        }
        //treathened by the knight
        for(i=0;i<this->pieces.size();i++)
        {
           Piece * p=pieces[i];
           if(p->type=='K')
           {
                int  kps [8][2];
                kps[0][0]=p->row+1; kps[0][1]=p->col+2;
                kps[1][0]=p->row+2; kps[1][1]=p->col+1;
                kps[2][0]=p->row+2; kps[2][1]=p->col-1;
                kps[3][0]=p->row+1; kps[3][1]=p->col-2;   
                kps[4][0]=p->row-1; kps[4][1]=p->col-2;
                kps[5][0]=p->row-2; kps[5][1]=p->col-1;
                kps[6][0]=p->row-2; kps[6][1]=p->col+1;
                kps[7][0]=p->row-1; kps[7][1]=p->col+2;
            
                for(j=0;j<8;j++)
                {
                    
                    if(kps[j][0]<0 || kps[j][1]<0  || kps[j][0]>=this->rows || kps[j][1]>=this->cols)
                    {
                        continue;
                    }
                    else
                    {
                        if(this->board[kps[j][0]][kps[j][1]]==' ')
                        {
                            this->board[kps[j][0]][kps[j][1]]='*';
                        }
                    }
                }                
           }
           if(p->type=='Q')
           {
                //rows, and diags at the same time by means of direction vectors;
                int  dirs [8][2];
                //ranks
                dirs[0][0]=0;  dirs[0][1]=1;
                dirs[1][0]=0;  dirs[1][1]=-1;
                //cols
                dirs[2][0]=1;  dirs[2][1]=0;
                dirs[3][0]=-1; dirs[3][1]=0;
                //diagonals
                dirs[4][0]=1;  dirs[4][1]=1; 
                dirs[5][0]=-1; dirs[5][1]=1;
                dirs[6][0]=-1; dirs[6][1]=-1;
                dirs[7][0]=1;  dirs[7][1]=-1;
                
                for(j=0;j<8;j++)
                {
                    int dir_x=dirs[j][0];
                    int dir_y=dirs[j][1];
                    int pos_x=p->row;
                    int pos_y=p->col;
                    while(1)
                    {
                        pos_x=pos_x+dir_x;
                        pos_y=pos_y+dir_y;
                        if(pos_x <0 || pos_y<0 || pos_x >= this->rows || pos_y >= this->cols)
                        {
                            break;
                        }
                        if(this->board[pos_x][pos_y]!=' ' && this->board[pos_x][pos_y]!='*')
                        {
                            break;
                        }
                        this->board[pos_x][pos_y]='*';
                        

                        
                    }
                }
               
           }
            
        }
        
        
        
        
        
    }
    
    public :void addPiece(Piece * p)
    {
        this->pieces.push_back(p);
    }
    public :int totalSafeSquares()
    {
        int ret=0, i ,j;
        for(i=0;i< this->board.size();i++)
        {
            for(j=0;j< this->board[i].size();j++)
            {
                if(this->board[i][j]==' ')
                {
                    ret++;
                }
            }
        }
        return ret;
    }
    
    public :void dump()
    {
        int i,j;
        cout << "pieces:\n";
        for(i=0;i<this->pieces.size();i++)
        {
            cout << this->pieces[i]->toString()<<"\n";
        }
        cout << "board:\n"; 
        for(i=0;i< this->board.size();i++)
        {
            for(j=0;j< this->board[i].size();j++){   cout << "___"; }
            cout << "_\n";
            for(j=0;j< this->board[i].size();j++)
            {
                cout << "|" <<this->board[i][j]<<" ";
            }
        cout << "|\n";
        }
        for(j=0;j< this->board[0].size();j++){   cout << "___"; }
       cout << "_\n";
        
    }
};


int main()
{
    /*
    Position * ppp=new Position(4,4);
    Piece * p1 = new Piece('Q',1,4);
    ppp->addPiece(p1);
    Piece * p2 = new Piece('Q',2,4);
    ppp->addPiece(p2);
    Piece * p3 = new Piece('K',1,2);
    ppp->addPiece(p3);
    Piece * p4 = new Piece('P',2,3);
    ppp->addPiece(p4);
    ppp->computeThreatenedSquares();
    ppp->dump();
    */
    int count =0;
    while(1)
    {
        ++count;
        int r, c, n, i;
        scanf("%d %d",&r, &c);
        if(r==0 && c==0)
        {
            break;
        }
        Position * ppp=new Position(r,c);
        //queen
        scanf("%d",&n);
        for(i=0; i<n;i++)
        {
            int x, y;
            scanf("%d %d",&r, &c);
            Piece * p = new Piece('Q',r,c);
            ppp->addPiece(p);
        }
        //knight
        scanf("%d",&n);
        for(i=0; i<n;i++)
        {
            int x, y;
            scanf("%d %d",&r, &c);
            Piece * p = new Piece('K',r,c);
            ppp->addPiece(p);
        }
        //pawn
        scanf("%d",&n);
        for(i=0; i<n;i++)
        {
            int x, y;
            scanf("%d %d",&r, &c);
            Piece * p = new Piece('P',r,c);
            ppp->addPiece(p);
        }        
        
        
        
        ppp->computeThreatenedSquares();
        //ppp->dump();
        cout << "Board "<<  count << " has " << ppp->totalSafeSquares() << " safe squares.\n";
 
    }
 
    exit(0);   
}
