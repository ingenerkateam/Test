#include "D:\c++\Project1\project1\TXLib.h"
//ХЫХЫХЫХЫХХЫ
//АЗААЗАЗ
//
//
void drawVopros(                            const char* textVoprosa,
                int xOtveta1, int yOtveta1, const char* textOtveta1,
                int xOtveta2, int yOtveta2, const char* textOtveta2);
void drawFormulirovkaVoprosa(const char* text);
void drawOtvet(int x, int y, const char* text);

int main()
{
    txCreateWindow(600, 400);
    drawVopros("Вопрос1!", 100, 250, "Ответ11!", 350, 250, "Ответ12!");
    txSleep(10000);

    drawVopros("Вопрос2!", 100, 250, "Ответ21!", 350, 250, "Ответ22!");
    txSleep(10000);

    drawVopros("Вопрос3!", 100, 250, "Ответ31!", 350, 250, "Ответ32!");

    return 0;
}

void drawVopros(                            const char* textVoprosa,
                int xOtveta1, int yOtveta1, const char* textOtveta1,
                int xOtveta2, int yOtveta2, const char* textOtveta2)
{
    txSetFillColor(TX_WHITE);
    txClear();
    drawFormulirovkaVoprosa(textVoprosa);
    drawOtvet(xOtveta1, yOtveta1, textOtveta1);
    drawOtvet(xOtveta2, yOtveta2, textOtveta2);
}

void drawOtvet(int x, int y, const char* text)
{
    txSetFillColor(TX_GRAY);
    txRectangle(x, y, x + 150, y + 100);
    txDrawText (x, y, x + 150, y + 100, text);
}

void drawFormulirovkaVoprosa(const char* text)
{
    txSetFillColor(TX_GRAY);
    txRectangle(100, 100, 500, 200);
    txDrawText (100, 100, 500, 200, text);
}
