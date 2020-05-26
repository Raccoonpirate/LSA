#include "PauseState.hpp"

PauseState::PauseState(StateMachine& stateMachine, StateData& stateData)
	: State {stateMachine, stateData}
	, _background {}
	, _pausedText {}
	, _instructionText {} {

	sf::Font& font = Configuration::fonts.Get(Fonts::Gui);
	sf::Vector2f viewSize = _stateData.window.getView().getSize();

	_pausedText.setFont(font);
	_pausedText.setString("Game Paused");
	_pausedText.setCharacterSize(70);
	_pausedText.setOrigin(_pausedText.getLocalBounds().width / 2.f, _pausedText.getLocalBounds().height / 2.f);
	_pausedText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);

	_instructionText.setFont(font);
	_instructionText.setString("(Press Backspace to return to the main menu)");
	_instructionText.setOrigin(_instructionText.getLocalBounds().width  / 2.f, 
							   _instructionText.getLocalBounds().height / 2.f);
	_instructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
}

void PauseState::Draw() {
	sf::RenderWindow& window = _stateData.window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(163, 73, 164, 150));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(_pausedText);
	window.draw(_instructionText);
}

void PauseState::Update(sf::Time) {
}

void PauseState::HandleEvent(const sf::Event& event) {
	if (event.type != sf::Event::KeyPressed) {
		return;
	}

	if (event.key.code == sf::Keyboard::Escape) {
		_FSM.PopState();
	}

	if (event.key.code == sf::Keyboard::BackSpace) {
		_FSM.ClearStates();
		_FSM.PushState(StateType::Menu);
	}
}