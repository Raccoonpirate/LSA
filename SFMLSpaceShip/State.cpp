#include "State.hpp"
#include "StateMachine.hpp"

State::State(StateMachine& FSM, StateData& stateData)
	: _FSM {FSM}
	, _stateData {stateData} {
}

State::~State() {
}

bool State::IsTransparent() const {
	return false;
}

bool State::IsDependent() const {
	return false;
}