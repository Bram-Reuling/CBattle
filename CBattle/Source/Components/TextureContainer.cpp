///
/// Made by: Bram Reuling
/// Description:
/// Class that manages all the textures in this project.
///

#include "TextureContainer.hpp"
#include <cassert>

TextureContainer* TextureContainer::instance_ = nullptr;

TextureContainer::TextureContainer()
{
	assert(instance_ == nullptr);
	instance_ = this;
}

TextureContainer::~TextureContainer()
= default;

sf::Texture& TextureContainer::GetTexture(std::string const& fileName)
{
	auto& texMap = instance_->textures_;
	auto textureFound = texMap.find(fileName);
	if (textureFound != texMap.end())
	{
		return textureFound->second;
	}
	else
	{
		auto& texture = texMap[fileName];
		texture.loadFromFile(fileName);
		return texture;
	}
}