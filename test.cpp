#include "TXLib.h"

struct Otvet
{
    int x;
    int y;
    const char* text;
    COLORREF color;
};

void drawVopros(const char* textVoprosa, Otvet* otvet1, Otvet* otvet2);
void drawFormulirovkaVoprosa(const char* text);
void drawOtvet(Otvet* otvet);

int main()
{
    txCreateWindow(600, 400);
    Otvet otvet11 = {100, 250, "Ответ11!", TX_YELLOW};
    Otvet otvet12 = {350, 250, "Ответ12!", TX_GREEN};
    drawVopros("Вопрос1!", &otvet11, &otvet12);
    txSleep(10000);

    Otvet otvet21 = {100, 250, "Ответ21!", TX_YELLOW};
    Otvet otvet22 = {350, 250, "Ответ22!", TX_GREEN};
    drawVopros("Вопрос2!", &otvet21, &otvet22);
    txSleep(10000);

    Otvet otvet31 = {100, 250, "Ответ31!", TX_YELLOW};
    Otvet otvet32 = {350, 250, "Ответ32!", TX_GREEN};
    drawVopros("Вопрос3!", &otvet31, &otvet32);

    return 0;
}

void drawVopros(const char* textVoprosa, Otvet* otvet1, Otvet* otvet2)
{
    txSetFillColor(TX_WHITE);
    txClear();
    drawFormulirovkaVoprosa(textVoprosa);
    drawOtvet(otvet1);
    drawOtvet(otvet2);
}

void drawOtvet(Otvet* otvet)
{
    txSetFillColor(otvet->color);
    txRectangle(otvet->x, otvet->y, otvet->x + 150, otvet->y + 100);
    txDrawText (otvet->x, otvet->y, otvet->x + 150, otvet->y + 100, otvet->text);
}

void drawFormulirovkaVoprosa(const char* text)
{
    txSetFillColor(TX_GRAY);
    txRectangle(100, 100, 500, 200);
    txDrawText (100, 100, 500, 200, text);
}
