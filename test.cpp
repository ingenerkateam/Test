#include "D:\c++\Project1\project1\TXLib.h"

struct Otvet
{
    int x;
    int y;
    const char* text;
    COLORREF color;
};

struct Vopros
{
    const char* text;
    HDC* fon;
    Otvet otvet1;
    Otvet otvet2;
    Otvet otvet3;
};

void drawVopros2(Vopros* vopros);
void drawVopros(const char* textVoprosa,
                 HDC* fon,
                 Otvet* otvet1,
                 Otvet* otvet2,
                 Otvet* otvet3
                 );

void drawFormulirovkaVoprosa(const char* text);
void drawOtvet(Otvet* otvet);
void drawNextQuestionButton();
void drawPrevQuestionButton();

int main()
{
    txCreateWindow(600, 400);

    const char* textVoprosa;// = "Вопрос1!";
    HDC  fon;
    Otvet otvet11;
    Otvet otvet12;
    Vopros vopros;

    Vopros voprosy[20];
    fon = txLoadImage ("fon1.bmp");
    voprosy[1] = {"Люся - это?!", &fon, {100, 250, "Леня!", TX_RED},{350, 250, "Костя!", TX_GREEN},{200, 0, "Даня!", TX_PINK}}; //BRUTAL COLOUR
    fon = txLoadImage ("fon2.bmp");
    voprosy[2] = {"Вася - это?!", &fon, {100, 250, "Пупкин!", TX_RED},{350, 250, "Пупок!", TX_ORANGE},{200, 10, "ВОРОНИН!!!!", TX_ORANGE}};
    fon = txLoadImage ("fon3.bmp");
    voprosy[3] = {"Винни - это?!", &fon, {100, 250, "Пух!", TX_ORANGE},{350, 250, "Медведь!", TX_GREEN}};
    fon = txLoadImage ("fon2.bmp");
    voprosy[4] = {"Пеппа - это?!", &fon, {100, 250, "Свинка!", TX_ORANGE},{350, 250, "Хрюшка!", TX_GREEN}};
    fon = txLoadImage ("fon3.bmp");
    voprosy[5] = {"Учителъ - это?!", &fon, {100, 250, "Гитлер!", TX_ORANGE},{350, 250, "Абрамов!", TX_GREEN}};

    int nomerVoprosa = 1;


    while (!GetAsyncKeyState(VK_ESCAPE)) {

        if (nomerVoprosa >= 1 and
            nomerVoprosa <= 5) {
            vopros = voprosy[nomerVoprosa];
        }

        drawVopros2(&vopros);
        drawNextQuestionButton();
        drawPrevQuestionButton();

        //Предыдущий вопрос
        if (txMouseButtons() & 1) {
            if (txMouseX() >= 50 and txMouseX() <= 100 and
                txMouseY() >= 50 and txMouseY() <= 100) {
                nomerVoprosa = nomerVoprosa - 1;
                txSleep(1000);
            }
        }
        //Следующий вопрос
        if (txMouseButtons() & 1) {
            if (txMouseX() >=500 and txMouseX() <= 550 and
                txMouseY() >= 50 and txMouseY() <= 100) {
                nomerVoprosa = nomerVoprosa + 1;
                txSleep(1000);
            }
        }

        txSleep(10);
    }

    txDeleteDC(fon);
    return 0;
}

void drawVopros(const char* textVoprosa, HDC* fon, Otvet* otvet1, Otvet* otvet2, Otvet* otvet3 )
{
    txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), *fon, 0, 0);

    drawFormulirovkaVoprosa(textVoprosa);
    drawOtvet(otvet1);
    drawOtvet(otvet2);
    drawOtvet(otvet3);
}


void drawVopros2(Vopros* vopros)
{
    txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), *vopros->fon, 0, 0);

    drawFormulirovkaVoprosa(vopros->text);
    drawOtvet(&vopros->otvet1);
    drawOtvet(&vopros->otvet2);
    drawOtvet(&vopros->otvet3);
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

void drawNextQuestionButton()
{
    txSetFillColor(TX_BLACK);
    txRectangle(500, 50, 550, 100);
    txDrawText (500, 50, 550, 100, ">>>>");
}

void drawPrevQuestionButton()
{
    txSetFillColor(TX_BLACK);
    txRectangle(50, 50, 100, 100);
    txDrawText (50, 50, 100, 100, "<<<<");
}
