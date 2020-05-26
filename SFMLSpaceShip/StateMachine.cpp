#include "StateMachine.hpp"

StateMachine::StateMachine(StateData& stateData)
	: _stateStack {}
	, _stateActions{}
	, _stateData {stateData}
	, _stateFactory {} {
}

void StateMachine::Update(sf::Time dt) {
	if (!_stateStack.empty()) {
		if (_stateStack.back().second->IsDependent() && _stateStack.size() > 1) {
			auto itr = std::end(_stateStack);

			for (; itr != std::begin(_stateStack); --itr) {
				if (itr != std::end(_stateStack) && !(*itr).second->IsDependent()) {
					break;
				}
			}

			for (; itr != std::end(_stateStack); ++itr) {
				(*itr).second->Update(dt);
			}
		} else {
			_stateStack.back().second->Update(dt);
		}
	}

	RunStateActions();
}

void StateMachine::Draw() {
	if (!_stateStack.empty()) {
		if (_stateStack.back().second->IsTransparent() && _stateStack.size() > 1) {
			auto itr = std::end(_stateStack);

			for (; itr != std::begin(_stateStack); --itr) {
				if (itr != std::end(_stateStack) && !(*itr).second->IsTransparent()) {
					break;
				}
			}

			for (; itr != std::end(_stateStack); ++itr) {
				(*itr).second->Draw();
			}
		} else {
			_stateStack.back().second->Draw();
		}
	}
}

void StateMachine::HandleEvent(const sf::Event& event) {
	if (!_stateStack.empty()) {
		_stateStack.back().second->HandleEvent(event);
	}

	RunStateActions();
}

void StateMachine::ChangeState(StateType stateType) {
	PopState();
	PushState(stateType);
}

void StateMachine::PushState(StateType stateType) {
	_stateActions.push_back([this, stateType] {
		_stateStack.push_back({stateType, this->GetState(stateType)}); 
	});
}

void StateMachine::PopState() {
	_stateActions.push_back([this] { 
		_stateStack.pop_back(); 
	});
}

void StateMachine::ClearStates() {
	_stateActions.push_back([this] { 
		_stateStack.clear(); 
	});
}

StateMachine::StatePtr StateMachine::GetState(StateType stateType) {
	return _stateFactory.find(stateType)->second();
}

void StateMachine::RunStateActions() {
	for (const auto& action : _stateActions) {
		action();
	}
	_stateActions.clear();
}