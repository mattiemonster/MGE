#include "Window.h"

#include <iostream>

#if       _WIN32_WINNT < 0x0500
#undef  _WIN32_WINNT
#define _WIN32_WINNT   0x0500
#endif
#include <windows.h>

namespace monster {
	namespace mgegraphics {

		using namespace std;

		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height, int shape) 
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			m_Shape = shape;
			if (!init()) 
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			
			if (!glfwInit())
			{
				std::cout << "ENGINE:	GLFW Init Failure! FATAL ERROR." << std::endl;
				return false;
			}
				
			

			//else
			std::cout << "ENGINE: GLFW Init Success!" << std::endl;

			

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window) 
			{
				std::cout << "ENGINE:	GLFW Window Init Failure! FATAL ERROR." << std::endl;
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			std::cout << "Information: OPENGL VERSION IS " << glGetString(GL_VERSION) << std::endl;
			glfwSetWindowSizeCallback(m_Window, windowResize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "ENGINE: GLEW INIT FAILED." << std::endl;
				return false;
			}

			std::cout << "ENGINE: GLEW Init Success!" << std::endl;
			

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::hideConsole()
		{
			std::cout << "ENGINE: Hiding console" << std::endl;
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		}

		void Window::setTitle(const char *gamename)
		{
			m_GameName = gamename;
			m_GameNameDebugging = gamename, " - DEBUG MODE";
			m_GameNameBeta = gamename, " - BETA BUILD";
			m_GameNameDev = gamename, " - DEVELOPMENT BUILD";
		}

		void Window::setTitleGameName()
		{
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowTitle(m_Window, m_GameName);
		}

		void Window::setTitleGameNameDebugging()
		{
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowTitle(m_Window, m_GameNameDebugging);
		}

		void Window::setTitleGameNameBeta()
		{
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowTitle(m_Window, m_GameNameBeta);
		}

		GLFWwindow* Window::getWindow() {
			return m_Window;
		}

		void Window::setTitleGameNameDev()
		{
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowTitle(m_Window, m_GameNameDev);
		}

		void Window::showConsole()
		{
			std::cout << "ENGINE: Showing console" << std::endl;
			ShowWindow(GetConsoleWindow(), SW_RESTORE);
		}

		void Window::update()
		{
			if (m_Shape == 1) 
			{
				// Triangle
				glBegin(GL_TRIANGLES);
				glVertex2f(-0.5f, -0.5f);
				glVertex2f(0.f, 0.5f);
				glVertex2f(0.5f, -0.5f);
				glEnd();
			}
			if (m_Shape == 2) 
			{
				glBegin(GL_QUADS);
				glVertex2f(-0.15f, -0.3f);
				glVertex2f(-0.15f, 0.3f);
				glVertex2f(0.2f, 0.3f);
				glVertex2f(0.2f, -0.3f);
				glEnd();
			}
			if (m_Shape == 3) 
			{
				glBegin(GL_QUADS);
				glVertex2f(-0.5f, -0.5f);
				glVertex2f(-0.5f, 0.5f);
				glVertex2f(0.5f, 0.5f);
				glVertex2f(0.5f, -0.5f);
				glEnd();
			}
			if (m_Shape == 4)
			{
				glBegin(GL_QUADS);
				glVertex2f(-0.25f, 0.25f); 
				glVertex2f(-0.5f, -0.25f);
				glVertex2f(0.5f, -0.25f); 
				glVertex2f(0.25f, 0.25f);
				glEnd();
			}
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		void Window::updateMin() {
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void windowResize(GLFWwindow *window, int width, int height) 
		{
			glViewport(0, 0, width, height);
		}

	}
}