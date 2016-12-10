#include <iostream>

#include "EngineSrc\EngineCore\EngineGraphics\Window.h"
#include "EngineSrc\EngineCore\EngineGraphics\Predrawn\DrawHouse.h"

int main()
{
	using namespace monster;
	using namespace mgegraphics;

	Window window(MGE_DEBUG_TITLE, MGE_DEFAULT_WIDTH, MGE_DEFAULT_HEIGHT, MGE_SHAPE_TRIANGLE);
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	
	//drawHouseBlack(0.5f, 0.5f, 0.5f, 0.5f);

	//DrawHouse dh;
	//dh.drawHouseBlack(0.5f, 0.5f, 0.5f, 0.5f, window.m_Window);

	window.hideConsole();
	window.showConsole();

	LOG("Game Start - Basic Sandbox");

	//LOG("LOL");

	while (!window.closed()) 
	{
		window.clear();
		//window.updateMin();
		window.update();
	}

	

	window.showConsole();


	return 0;
}