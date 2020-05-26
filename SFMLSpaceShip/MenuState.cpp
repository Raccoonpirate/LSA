#include "MenuState.hpp"

MenuState::MenuState(StateMachine& stateMachine, StateData& stateData)
	: State {stateMachine, stateData}
	, _mainMenu {_stateData.window} {

	sf::Vector2f windSize = stateData.window.getView().getSize();

	_background.setTexture(Configuration::textures.Get(Textures::MenuBackground));
	_background.setScale(windSize.x / _background.getLocalBounds().width,
						 windSize.y / _background.getLocalBounds().height);

	_planet.setTexture(Configuration::textures.Get(Textures::MenuPlanet));
	_planet.setOrigin(_planet.getLocalBounds().width / 2.f, _planet.getLocalBounds().height / 2.f);
	_planet.setPosition(windSize.x * 0.8f, windSize.y * 0.2f);

	//_background.setTexture(Configuration::textures.Get(Textures::Desert));
	VLayout* layout = new VLayout;
	layout->SetSpace(25);

	TextButton* newGame = new TextButton("New Game");
	newGame->onClick = [this] (const sf::Event&, Button& button) {
		_FSM.PopState();
		_FSM.PushState(StateType::Game);
	};
	layout->add(newGame);

	TextButton* configuration = new TextButton("Configuration");
	configuration->onClick = [this] (const sf::Event&, Button& button) {

	};
	layout->add(configuration);

	TextButton* exit = new TextButton("Exit");
	exit->onClick = [this] (const sf::Event&, Button& button) {
		_FSM.ClearStates();
		_stateData.window.close();
	};
	layout->add(exit);

	_mainMenu.SetLayout(layout);

	_mainMenu.bind(Configuration::GuiInputs::Escape, [this] (const sf::Event& event) {
		_FSM.ClearStates();
		this->_stateData.window.close();
	});
}

void MenuState::Draw() {
	sf::RenderWindow& window = _stateData.window;

	window.setView(window.getDefaultView());
	window.draw(_background);
	window.draw(_planet);
	window.draw(_mainMenu);
}

void MenuState::Update(sf::Time dt) {
}

void MenuState::HandleEvent(const sf::Event& event) {
	_mainMenu.ProcessEvent(event);
	_mainMenu.ProcessEvents();
}