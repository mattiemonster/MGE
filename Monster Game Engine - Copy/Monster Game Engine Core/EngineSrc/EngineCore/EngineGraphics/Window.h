#ifndef _H_WINDOW_
#define _H_WINDOW_

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#define MGE_DEFAULT_WIDTH 1024
#define MGE_DEFAULT_HEIGHT 512

#define MGE_DEFAULT_TITLE "MGE"

#define MGE_GAME_TITLE "Game"
#define MGE_WINDOW_TITLE "Game Window"
#define MGE_DEBUG_TITLE "Game | DEBUG MODE"

#define MGE_SHAPE_NONE 0
#define MGE_SHAPE_NULL 0
#define MGE_NULL 0
#define MGE_NONE 0
#define MGE_SHAPE_TRIANGLE 1
#define MGE_SHAPE_SQUARE 2
#define MGE_SHAPE_RECTANGLE 3
#define MGE_SHAPE_TRAPEZOID 4

#define  LOG(X) std::cout << X << std::endl;

namespace monster {
	namespace mgegraphics {

	class Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		bool m_Triangle;
		
		bool m_Closed;
		int m_Shape;
		const char *m_GameName;
		const char *m_GameNameDebugging;
		const char *m_GameNameBeta;
		const char *m_GameNameDev;
	public:
		Window(const char *title, int width, int height, int m_Shape);
		~Window();
		bool closed() const;
		void clear() const;
		void update();
		void updateMin();
		GLFWwindow *m_Window;

		GLFWwindow* getWindow();

		void showConsole();
		void hideConsole();

		void setTitle(const char *gamename);
		void setTitleGameName();
		void setTitleGameNameDebugging();
		void setTitleGameNameBeta();
		void setTitleGameNameDev();

		//void windowResize(GLFWwindow *window, int width, int height);
		

		//static int const MGE_SHAPE_NONE = 0;
		//static int const MGE_SHAPE_TRIANGLE = 1;
		//static int const MGE_SHAPE_SQUARE = 2;
		//static int const MGE_SHAPE_RECTANGLE = 3;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
	private:
		bool init();
	};

	} 
}

#endif