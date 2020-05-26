#include "TitleState.hpp"

TitleState::TitleState(StateMachine& stateMachine, StateData& stateData)
	: State {stateMachine, stateData}
	, _pressToContinueText {}
	, _showText {true}
	, _textEffectTime {sf::Time::Zero} {
	
	sf::Vector2f windSize = stateData.window.getView().getSize();

	_background.setTexture(Configuration::textures.Get(Textures::MenuBackground));
	_background.setScale(windSize.x / _background.getLocalBounds().width,
							   windSize.y / _background.getLocalBounds().height);
	
	_planet.setTexture(Configuration::textures.Get(Textures::MenuPlanet));
	_planet.setOrigin(_planet.getLocalBounds().width / 2.f, _planet.getLocalBounds().height / 2.f);
	_planet.setPosition(windSize.x * 0.8f, windSize.y * 0.2f);

	_gameTitle.setFont(Configuration::fonts.Get(Fonts::Gui));
	_gameTitle.setCharacterSize(120);
	_gameTitle.setFillColor(sf::Color::Yellow);
	_gameTitle.setOutlineColor(sf::Color::Magenta);
	_gameTitle.setOutlineThickness(0.9f);
	_gameTitle.setString("Little\nSpaceship\nAdventures");
	//_gameTitle.setStyle(sf::Text::Bold);
	_gameTitle.setOrigin(_gameTitle.getLocalBounds().width / 2.f, _gameTitle.getLocalBounds().height / 2.f);
	_gameTitle.setPosition(stateData.window.getView().getCenter());

	_pressToContinueText.setCharacterSize(30);
	_pressToContinueText.setFont(Configuration::fonts.Get(Fonts::Gui));
	_pressToContinueText.setString("Press any key to start");
	_pressToContinueText.setOrigin(_pressToContinueText.getLocalBounds().width / 2.f, _pressToContinueText.getLocalBounds().height / 2.f);
	_pressToContinueText.setPosition(windSize.x * 0.5f, windSize.y * 0.9f);
}

void TitleState::Draw() {
	sf::RenderWindow& window = _stateData.window;
	window.draw(_background);
	window.draw(_planet);
	window.draw(_gameTitle);

	if (_showText) {
		window.draw(_pressToContinueText);
	}
}

void TitleState::Update(sf::Time dt) {
	_textEffectTime += dt;

	if (_textEffectTime >= sf::seconds(0.75f)) {
		_showText = !_showText;
		_textEffectTime = sf::Time::Zero;
	}
}

void TitleState::HandleEvent(const sf::Event& event) {
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyPressed) {
		_FSM.PopState();
		_FSM.PushState(StateType::Menu);
	}
}