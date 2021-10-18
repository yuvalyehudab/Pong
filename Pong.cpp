// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	// create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// create a Bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 20);

	// Create a ball
	Ball ball(1920 / 2, 0);

	Text hud;

	// Retro style font
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");

	hud.setFont(font);
	hud.setCharacterSize(75);

	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);

	Clock clock;

	while (window.isOpen())
	{
		/* Handle the player input
		**************************
		**************************
		************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit when window is closed
				window.close();
			}
		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle pressing and releasing arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		/*
		 Update the Bat, the Ball and the hud
		 ************************************
		 ************************************
		 ************************************
		 */

		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);

		ball.update(dt);

		// Update the HUD text

		std::stringstream writer;
		writer << "Score:" << score << "  Lives:" << lives;
		hud.setString(writer.str());

		/*
		Draw the bat, the hud and the ball
		*********************************
		*********************************
		*********************************
		*/

		window.clear();

		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball .getShape());

		window.display();
	}

	return 0;
}
