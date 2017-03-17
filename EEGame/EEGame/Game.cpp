#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(){



}

void Game::init(){

	
	//SFML windowedConfig
	contextSettings.depthBits = 24;
	contextSettings.stencilBits = 8;
	contextSettings.antialiasingLevel = 0;
	contextSettings.minorVersion = 4;
	contextSettings.majorVersion = 4;
	contextSettings.sRgbCapable = false;

	//Create SFML Window
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), programName,
		sf::Style::Titlebar | sf::Style::Close, contextSettings); //depth, stencil buffer, major, minor, attribFlags, srgb

	cout << "EEGame initialized." << endl << endl;

	//SFML Elements

	//Rectangle test
	rectangle = new sf::RectangleShape();
	rectangle->setPosition(sf::Vector2f(10.f, 10.f));
	rectangle->setSize(sf::Vector2f(500.f, 100.f));
	rectangle->setFillColor(sf::Color::Black);


	drawableArray.push_back(rectangle);

}

void Game::ioEvents(){

	sf::Event event;

	while (window->pollEvent(event)) {

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W && !c_up) c_up = true;
			if (event.key.code == sf::Keyboard::S && !c_down) c_down = true;
			if (event.key.code == sf::Keyboard::A && !c_left) c_left = true;
			if (event.key.code == sf::Keyboard::D && !c_right) c_right = true;
		}

		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::W && c_up) c_up = false;
			if (event.key.code == sf::Keyboard::S && c_down) c_down = false;
			if (event.key.code == sf::Keyboard::A && c_left) c_left = false;
			if (event.key.code == sf::Keyboard::D && c_right) c_right = false;
	
		}

		if (event.type == sf::Event::Closed) {
			// end the program
			mainLoop = false;
		}

	}

}

void Game::run(){

	while (mainLoop) {

		update();
		render();

	}

}

void Game::update(){


	//Manage deltaTime	
	currentTime = sfClock.getElapsedTime();
	float currentFrame = currentTime.asSeconds();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	//cout << deltaTime << endl;
	//Call to check input events
	ioEvents();

	//Velocity
	float v = 500.f * deltaTime;

	if (c_up) { 
		rectangle->move(sf::Vector2f(0.0f, -v));
	
	}
	
	if (c_down) { 
		rectangle->move(sf::Vector2f(0.0f, v));

	}

	if (c_left) {
		rectangle->move(sf::Vector2f(-v, 0.0f));

	}

	if (c_right) {
		rectangle->move(sf::Vector2f(v, 0.0f));
	
	}

}

void Game::render(){

	window->clear(sf::Color::White);


	////Stop OpenGL state
	window->pushGLStates();

	////SFML Drawing space
	
	for (size_t i = 0; i < drawableArray.size(); i++) {
		window->draw(*drawableArray.at(i));
		
	}


	//window->draw(rectangle);
	////Continue OpenGL state
	window->popGLStates();

	

	window->display();

}

void Game::clean(){

	for (size_t i = 0; i < drawableArray.size(); i++) {

		delete drawableArray.at(i);
		
	}

}




Game::~Game(){


}
