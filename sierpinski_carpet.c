//*****************************************************
//
// Universidade de S�o Paulo - USP
// Disciplina: Computa��o Gr�fica
// Prof�.: Maria Cristina
// Autor: Vin�cius Marques Stocco 6427233 - jimmystocco@gmail.com
//
// Trabalho 1 - Fractais - Sierpinski Carpet
//
//*****************************************************

#include <glut.h>

void divideQuadrado4vf(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by, GLfloat cx, GLfloat cy, GLfloat dx, GLfloat dy, int counter) {

     //Condi��o de parada
     if (counter < 8) {

        counter++;
        //tamanho do lado do quadrado novo � 3 vezes menor
        GLfloat novolado = (ay - by)/3;

        //Calculando os pontos
        GLfloat axnovo = ax + novolado;
        GLfloat aynovo = (ay + by + novolado)/2;

        GLfloat bxnovo = bx + novolado;
        GLfloat bynovo = aynovo - novolado;

        GLfloat cxnovo = cx - novolado;
        GLfloat cynovo = bynovo;

        GLfloat dxnovo = cxnovo;
        GLfloat dynovo = aynovo;

        //Gerando o quadrado interno
       	glBegin(GL_QUADS);
            glColor3f(0, 0, 0);//Fa�a novas combina��es de cores
    		glVertex2f( axnovo, aynovo);
    		glColor3f(2, 255, 18);//Fa�a novas combina��es de cores
    		glVertex2f( bxnovo, bynovo);
    		glColor3f(0, 0, 0);//Fa�a novas combina��es de cores
    		glVertex2f( cxnovo, cynovo);
    		glColor3f(255, 255, 0);
    		glVertex2f( dxnovo, dynovo);
	    glEnd();

	    //Chamada recursiva
	    //cima
	    divideQuadrado4vf(axnovo, aynovo+novolado, bxnovo, bynovo+novolado, cxnovo, cynovo+novolado, dxnovo, dynovo+novolado, counter);
	    //baixo
	    divideQuadrado4vf(axnovo, aynovo-novolado, bxnovo, bynovo-novolado, cxnovo, cynovo-novolado, dxnovo, dynovo-novolado, counter);
	    //direita
	    divideQuadrado4vf(axnovo+novolado, aynovo, bxnovo+novolado, bynovo, cxnovo+novolado, cynovo, dxnovo+novolado, dynovo, counter);
	    //esquerda
	    divideQuadrado4vf(axnovo-novolado, aynovo, bxnovo-novolado, bynovo, cxnovo-novolado, cynovo, dxnovo-novolado, dynovo, counter);
	    //superior esquerda
	    divideQuadrado4vf(axnovo-novolado, aynovo+novolado, bxnovo-novolado, bynovo+novolado, cxnovo-novolado, cynovo+novolado, dxnovo-novolado, dynovo+novolado, counter);
	    //inferior esquerda
	    divideQuadrado4vf(axnovo-novolado, aynovo-novolado, bxnovo-novolado, bynovo-novolado, cxnovo-novolado, cynovo-novolado, dxnovo-novolado, dynovo-novolado, counter);
	    //superior direita
	    divideQuadrado4vf(axnovo+novolado, aynovo+novolado, bxnovo+novolado, bynovo+novolado, cxnovo+novolado, cynovo+novolado, dxnovo+novolado, dynovo+novolado, counter);
	    //inferior direita
	    divideQuadrado4vf(axnovo+novolado, aynovo-novolado, bxnovo+novolado, bynovo-novolado, cxnovo+novolado, cynovo-novolado, dxnovo+novolado, dynovo-novolado, counter);
     }
}

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualiza��o com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente � preta
     //         R     G     B
     glColor3f(0.0f, 0.0f, 0.0f);

     // Desenha um quadrado no centro da janela
     GLfloat A [2] = { 000.0, 300.0};
	 GLfloat B [2] = { 000.0, 000.0};
	 GLfloat C [2] = { 300.0, 000.0};
	 GLfloat D [2] = { 300.0, 300.0};

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2f( A[0], A[1]);
               glVertex2f( B[0], B[1]);
               glVertex2f( C[0], C[1]);
               glVertex2f( D[0], D[1]);
     glEnd();

     //passa as coordenadas do quadrado central e uma vari�vel para contar o n�vel da recurs�o
     divideQuadrado4vf(A[0], A[1], B[0], B[1], C[0], C[1], D[0], D[1], 0);

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa par�metros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimens�es da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de sele��o (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D (0.0f, 300.0f, 0.0f, 300.0f*h/w);
    else
        gluOrtho2D (0.0f, 300.0f*w/h, 0.0f, 300.0f);
}

// Programa Principal
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(600,600);
     glutInitWindowPosition(500,250);
     glutCreateWindow("Sierpinski Carpet");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();
}

