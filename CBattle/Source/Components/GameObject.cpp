#include "GameObject.hpp"

GameObject::GameObject(std::string identifier) : identifier(identifier)
{
	
}

GameObject::GameObject(const GameObject& other) : identifier(other.GetIdentifier())
{
	
}

GameObject::~GameObject()
{
	
}

std::string GameObject::GetIdentifier() const
{
	return this->identifier;
}
