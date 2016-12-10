#include "DrawHouse.h";

#include "EngineSrc\EngineCore\EngineGraphics\Window.h"

namespace monster {
	namespace mgegraphics {

			void DrawHouse::drawHouseBlack(GLclampf bgr, GLclampf bgg, GLclampf bgb, GLclampf bga, GLFWwindow *window) {

				glfwMakeContextCurrent(window);
				glClearColor(bgr, bgg, bgb, bga);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glColor3f(0.0f, 0.0f, 0.0f); // sets color to black.
				glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
				glVertex2f(0.0f, 0.75f); // top of the roof
				glVertex2f(-0.5f, 0.25f); // left corner of the roof
				glVertex2f(0.5f, 0.25f); // right corner of the roof
				glVertex2f(-0.5f, -0.5f); // bottom left corner of the house
				glVertex2f(0.5f, -0.5f); //bottom right corner of the house
				glEnd();
			}

			

	}
}