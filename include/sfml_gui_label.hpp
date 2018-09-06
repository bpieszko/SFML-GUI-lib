#ifndef SFML_GUI_LABEL
#define SFML_GUI_LABEL

#include <SFML/Graphics.hpp>
#include <string>

namespace sf::GUI
{

class Label : public sf::Drawable {
/* VARIABLES */
public:
	
private:
	sf::Vector2f	v2_size;
	sf::Vector2f	v2_position;

	std::string		s_text;
	sf::Color		c_text;
	sf::Font		f_text;
	unsigned 		u_text;

	sf::Color		c_background;

/* METHODS */
public:
	Label() = default;
	~Label() = default;

	/* GETTERS */
	std::string getText() const;
	sf::Color getTextColor() const;
	sf::Font getTextFont() const;
	sf::Color getBackgroundColor() const;
	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	unsigned getCharacterSize() const;

	/* SETTERS */
	void setText(const std::string & s_text_arg);
	void setTextColor(const sf::Color & c_text_arg);
	void setTextFont(const sf::Font & f_text_arg);
	void setBackgroundColor(const sf::Color & c_background_arg);
	void setSize(const sf::Vector2f & v2_size_arg);
	void setPosition(const sf::Vector2f & v2_position_arg);
	void setCharacterSize(const unsigned u_text_arg);

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

}

#endif // SFML_GUI_LABEL