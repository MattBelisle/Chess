#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../Game.hpp"

namespace Chess{
	class PauseState : public State{
	public: 
		PauseState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;
		sf::Sprite _background;
	};
}