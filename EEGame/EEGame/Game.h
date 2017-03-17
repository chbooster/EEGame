#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>


class Game{

public:

	Game();
	void init();
	void ioEvents();
	void run();
	void update();
	void render();
	void clean();
	~Game();


private:

	sf::RenderWindow* window;
	sf::ContextSettings contextSettings;

	const int screenWidth = 1280;
	const int screenHeight = 720;
	const std::string programName = "EEGame";

	bool mainLoop = true; //Main loop flag

	sf::Clock sfClock; //Timmings 
	sf::Time currentTime;
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	bool c_down = false; //KB Control flags
	bool c_up = false;
	bool c_left = false;
	bool c_right = false;

	//SFML Graphics elements
	//Array with pointers of drawable elements
	std::vector<sf::Drawable*> drawableArray;

	sf::RectangleShape* rectangle;
	
};

