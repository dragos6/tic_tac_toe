#ifndef JOC_H
#define JOC_H

class joc
{
private:
    char board[3][3];
    int turn;
    int win;
public:
    joc();
    void drawBoard();
    void startgame();
    void player();
    bool winner();
    void reset();
    void displaywinner();
    bool invalidmove(int mutare);
    };
#endif // JOC_H
