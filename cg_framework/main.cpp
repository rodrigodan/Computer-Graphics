#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//simple point(100,800);
	//putPixel(100,100,255,0,0,255);

	// for(int i = 0; i < IMAGE_WIDTH/2; i++){
	// 	for(int j = 0; j < IMAGE_HEIGHT/2; j++){
	// 		if(j%8 == 0 && i%8 == 0){
	// 			putPixel(i,j,0,255,0,255);
	// 		}
	// 	}
		
	// }

	// for(int i = IMAGE_WIDTH/2; i < IMAGE_WIDTH; i++){
	// 	for(int j = 0; j < IMAGE_HEIGHT/2; j++){
			
	// 		if(j%8 == 0 && i%8 == 0){
	// 			putPixel(i,j,255,0,0,255);
	// 		}
	// 	}
		
	// }

	// for(int i = 0; i < IMAGE_WIDTH/2; i++){
	// 	for(int j = IMAGE_HEIGHT/2; j < glutGet(GLUT_WINDOW_HEIGHT); j++){
	// 		if(j%8 == 0 && i%8 == 0){
				
	// 			putPixel(i,j,0,0,255,255);

	// 		}
	// 	}
		
	// }

	// for(int i = IMAGE_WIDTH/2; i < IMAGE_WIDTH; i++){
	// 	for(int j = IMAGE_HEIGHT/2; j < IMAGE_HEIGHT; j++){
	// 		if(j%8 == 0 && i%8 == 0){
	// 			putPixel(i,j,0,255,255,255);
	// 		}
			
	// 	}
		
	// }

	//draw line from (0,500) untill (500,0)
	// drawLine();

	// ddaAlgorithm(0,500,500,0,255,0,0,255);

	triangle();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

