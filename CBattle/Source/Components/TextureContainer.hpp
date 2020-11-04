#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureContainer
{
public:
	TextureContainer();
	~TextureContainer();

	static sf::Texture& GetTexture(std::string const& fileName);

private:
	std::map<std::string, sf::Texture> textures_;

	static TextureContainer* instance_;
};
