#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"
#include <stdlib.h>

void ddaAlgorithm(int x1, int y1, int x2, int y2, int R, int G,int B, int A) {
  float dx = x2-x1;
  float dy = y2-y1;

  float m = dy/dx;
  float b = y1 - (m*x1);

  float ynext = y1;

  int j = 0;
  for (size_t i = 0; i < dx; i++) {
    // putPixel2(x1+i, round(m*(x1+i)+b), R,G,B,A);
    ynext += m;
    putPixel(x1+i, round(ynext), R,G,B,A);
  }
}


struct Color{
    int R;
    int G;
    int B;
    int A;
};


Color cor1 =
    {
        0, 255, 0, 100
};
Color cor =
    {
        255, 0, 0, 100
};
Color cor2 =
    {
        0, 0, 255, 100
};
Color cor3 =
    {
        0, 0, 0, 255
};

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, int R, int G, int B, int A){
    int posicao = (4 * x) + (4 * y * IMAGE_WIDTH);
    FBptr[posicao + 0] = R;
    FBptr[posicao + 1] = G;
    FBptr[posicao + 2] = B;
    FBptr[posicao + 3] = A;
}
// função utilizada para auxiliar na generalização dos octantes mudando os pontos
void Swap(int * x0, int * y0, int * x1, int * y1){

    int aux0, aux1;
    aux0 = * x0;
    * x0=* y0;
    * y0=aux0;

    aux1 = * x1;
    * x1= * y1;
    * y1=aux1;
}
void Drawline(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;  // variaveis de decisão
    int dy = y1 - y0;  // variaveis de decisão
    int inverteEixo = 0;
    int aux = 1;
    int d = 2 * dy - dx; // formula para calcular precisão
    int incrE = 2 * dy; //Se o parametro de decisão for < 0(negativo),
                        //então pegamos o  ValorDeDecisão calculado e jogamos na fórmula
    int incrNe = 2 * (dy - dx); //Se o parâmetro de decisão for > 0(positivo),
                               // então pegamos o ValorDeDecisão calculado e jogamos na fórmula
    //interpolação da cor na reta
    int varR = cor2.R - cor1.R,
    varG = cor2.G - cor1.G,
    varB = cor2.B - cor1.B,
    varA = cor2.A - cor1.A;
    int varX = dx, varY = dy;
    //cores incrementados
    float addR = (float) varR / dx;
    float addG = (float) varG / dx;
    float addB = (float) varB / dx;
    float addA = (float) varA / dx;

    float rIni = cor1.R;
    float gIni = cor1.G;
    float bIni = cor1.B;
    float aIni = cor1.A;

    if (dx == 0) {
        if (y0 < y1) {
            putPixel(x0, y0, cor1.R, cor1.G, cor1.B, cor1.A);
            while (y0++ <= y1) {
                putPixel(x0, y0, round(rIni += addR), round(gIni += addG),
                         round(bIni += addB), round(aIni += addA));

            }
        } else {
            putPixel(x0, y0, cor1.R, cor1.G, cor1.B, cor1.A);
            while (y1++ <= y0) {
                putPixel(x0, y1, round(rIni += addR), round(gIni += addG),
                          round(bIni += addB), round(aIni += addA));

            }

        }
        return;

    }

    if (abs(dy) > abs(dx)) {
        // se os eixos forem trocados setamos com 1 e a inclinação
        // é iniciada com 1
        inverteEixo = 1;
        Swap(& x0,& x1,& y0,& y1);
        dx = x1 - x0;
        dy = y1 - y0;

    }
    if (dx < 0) {
        // a variação de x se torna positiva , utilizo o swap para inverter
        // posição final e inicial
        Swap(& x0,& y0,& x1,& y1);
        dx = x1 - x0;
        dy = y1 - y0;

    }
    if (dy < 0) {
        // caso o delta seja menor que 0 setamos a inclinação para
        // -1
        dy = -dy;
        aux = -1;

    }
    int x = x0;
    int y = y0;
    if (inverteEixo == 1) { // caso eixo esteja invertido
        putPixel(y, x, cor1.R, cor1.G, cor1.B, cor1.A);
    }
    else { //permanece o mesmo
        putPixel(x, y, cor1.R, cor1.G, cor1.B, cor1.A);
    }
    while (x < x1) {
        if (d <= 0) {
            d += incrE;
            x++;
        }
        else {
            d += incrNe;
            x++;
            y += aux;
        }
        if (inverteEixo == 1) {  // verifica se o eixo está invertido
            putPixel(y, x, round(rIni += addR), round(gIni += addG),
                      round(bIni += addB), round(aIni += addA));

        }
        else {  // permanece o mesmo
            putPixel(x, y, round(rIni += addR), round(gIni += addG),
                      round(bIni += addB), round(aIni += addA));
        }
    }


}


void triangle(){

    // Drawline(150, 150, 400, 400);
    // Drawline(149, 149, 399, 149);
    // Drawline(399, 399, 400, 149);

Drawline(150, 150, 400, 400);
    Drawline(149, 149, 399, 149);
    Drawline(399, 399, 400, 149);

    Drawline(75, 75, 200, 200);
    Drawline(74, 74, 199, 74);
    Drawline(199, 199, 200, 74);

    Drawline(300, 300, 500, 500);
    Drawline(299, 299, 499, 299);
    Drawline(499, 499, 500, 299);

    Drawline(0, 300, 200, 200);
    Drawline(1, 299, 199,399 );

    Drawline(1, 199, 198,395 );
    Drawline(1, 199, 198,300 );

}


#endif // _MYGL_H_

