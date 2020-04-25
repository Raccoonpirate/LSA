#include <algorithm>
#include <cassert>

//#include <Book/Foreach.hpp>
#include "SceneNode.hpp"

SceneNode::SceneNode()
	: _children()
	, _parent(nullptr) {
}

void SceneNode::AttachChild(Ptr child) {
	child->_parent = this;
	_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode& node) {
	auto found = std::find_if(_children.begin(), _children.end(), 
		[&] (Ptr& p) { 
			return p.get() == &node; 
		});
	if (found != _children.end()) {
		Ptr result = std::move(*found);
		result->_parent = nullptr;
		_children.erase(found);
		return result;
	}
	return nullptr;
}

void SceneNode::Update(sf::Time dt) {
	UpdateCurrent(dt);
	UpdateChildren(dt);
}

void SceneNode::UpdateCurrent(sf::Time) {
	// Do nothing by default
}

void SceneNode::UpdateChildren(sf::Time dt) {
	for (const auto& child : _children) {
		child->Update(dt);
	}
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget&, sf::RenderStates) const {
	// Do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const auto& child : _children) {
		child->draw(target, states);
	}
}

sf::Vector2f SceneNode::GetWorldPosition() const {
	return GetWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::GetWorldTransform() const {
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->_parent) {
		transform = node->getTransform() * transform;
	}

	return transform;
}

