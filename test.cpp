#include "D:\c++\Project1\project1\TXLib.h"

void drawVopros(const char* text);

int main()
{
    txCreateWindow(600, 400);

    txSetFillColor(TX_WHITE);
    txClear();
    drawVopros("������1!");

    txRectangle(100, 250, 250, 350);
    txDrawText (100, 250, 250, 350, "�����1!");
    txRectangle(350, 250, 500, 350);
    txDrawText (350, 250, 500, 350, "�����2!");

    txSleep(10000);
    txSetFillColor(TX_WHITE);
    txClear();
    drawVopros("������2!");

    txRectangle(100, 250, 250, 350);
    txDrawText (100, 250, 250, 350, "�����11!");
    txRectangle(350, 250, 500, 350);
    txDrawText (350, 250, 500, 350, "�����22!");
    txSleep(10000);

    txSetFillColor(TX_WHITE);
    txClear();
    drawVopros("������3!");

    txRectangle(100, 250, 250, 350);
    txDrawText (100, 250, 250, 350, "�����31!");
    txRectangle(350, 250, 500, 350);
    txDrawText (350, 250, 500, 350, "�����32!");
    return 0;
}


void drawVopros(const char* text)
{
    txSetFillColor(TX_GRAY);
    txRectangle(100, 100, 500, 200);
    txDrawText (100, 100, 500, 200, text);
}
