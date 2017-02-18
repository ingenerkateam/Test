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
};

void drawVopros2(Vopros* vopros);
void drawVopros(const char* textVoprosa,
                 HDC* fon,
                 Otvet* otvet1,
                 Otvet* otvet2);
void drawFormulirovkaVoprosa(const char* text);
void drawOtvet(Otvet* otvet);
void drawNextQuestionButton();
void drawPrevQuestionButton();

int main()
{
    txCreateWindow(600, 400);

    const char* textVoprosa;// = "Вопрос1!";
    Otvet otvet11;
    Otvet otvet12;
    //Vopros vopros;
    int nomerVoprosa = 1;
    HDC  fon;


    while (!GetAsyncKeyState(VK_ESCAPE)) {

        if (nomerVoprosa == 1) {
            textVoprosa = "Вопрос1!";
            fon = txLoadImage ("fon1.bmp");
            otvet11 = {100, 250, "Ответ11!", TX_RED};
            otvet12 = {350, 250, "Ответ12!", TX_GREEN};
            Vopros vopros = {"Вопрос1!", &fon, {100, 250, "Ответ11!", TX_RED},{350, 250, "Ответ12!", TX_GREEN}};

        } else if (nomerVoprosa == 2) {
            textVoprosa = "Вопрос2!";
            fon = txLoadImage ("fon2.bmp");
            otvet11 = {100, 250, "Ответ21!", TX_BLUE};
            otvet12 = {350, 250, "Ответ22!", TX_BLACK};
        } else if (nomerVoprosa == 3) {
            textVoprosa = "Вопрос3!";
            fon = txLoadImage ("fon3.bmp");
            otvet11 = {100, 250, "Ответ31!", TX_ORANGE};
            otvet12 = {350, 250, "Ответ32!", TX_YELLOW};
        }

        drawVopros(textVoprosa, &fon, &otvet11, &otvet12);
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

void drawVopros(const char* textVoprosa, HDC* fon, Otvet* otvet1, Otvet* otvet2)
{
    txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), *fon, 0, 0);

    drawFormulirovkaVoprosa(textVoprosa);
    drawOtvet(otvet1);
    drawOtvet(otvet2);
}


void drawVopros2(Vopros* vopros)
{
    txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), *vopros->fon, 0, 0);

    drawFormulirovkaVoprosa(vopros->text);
    drawOtvet(&vopros->otvet1);
    drawOtvet(&vopros->otvet2);
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
