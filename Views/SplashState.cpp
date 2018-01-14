#include <sstream>
#include "SplashState.hpp"
#include "../DEFINITIONS.hpp"
#include <iostream> 
//#include "MainMenuState.hpp"
namespace Chess{
	SplashState::SplashState(GameDataRef data): _data(data) {}

	void SplashState::init(){
		this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture( this->_data->assets.getTexture("Splash State Background"));
	}

	void SplashState::handleInput(){
		sf::Event event;

		while(this->_data->window.pollEvent( event )){
			//only thing we need to handle is early termination on program
			if(sf::Event::Closed == event.type){
				this->_data->window.close();
			}
		}
	}

	void SplashState::update(float dt){
		if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
			//Switch to main menu... not there yet
			std::cout<< "Going to Main Menu"<<std::endl;
		//	this->_data->machine.addState(StateRef(new MainMenuState( _data)), true);
		}
	}

	void SplashState::draw(float dt){
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background);
		this->_data->window.display();
	}
}