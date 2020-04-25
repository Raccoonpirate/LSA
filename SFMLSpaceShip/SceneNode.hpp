#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

class SceneNode : public sf::Transformable, public sf::Drawable {
	public:
		using Ptr = std::unique_ptr<SceneNode>;
	
		SceneNode(const SceneNode&) = delete;
		SceneNode& operator=(const SceneNode&) = delete;

		SceneNode();

		void AttachChild(Ptr child);
		Ptr	DetachChild(const SceneNode& node);

		void Update(sf::Time dt);

		sf::Vector2f GetWorldPosition() const;
		sf::Transform GetWorldTransform() const;

	private:
		virtual void UpdateCurrent(sf::Time dt);
		void UpdateChildren(sf::Time dt);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	
		std::vector<Ptr> _children;
		SceneNode* _parent;
};

