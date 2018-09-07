#ifndef SFML_GUI_LABEL
#define SFML_GUI_LABEL

#include <SFML/Graphics.hpp>
#include "sfml_gui_element.hpp"
#include <string>

namespace sf::GUI
{

class Label : public Element {
/* VARIABLES */
public:
	
private:

/* METHODS */
public:
	Label() = default;
	~Label() = default;

	/* GETTERS */
	virtual sf::Vector2f getSize() const;
	virtual sf::Vector2f getPosition() const;
	virtual std::string getText() const;
	virtual sf::Color getTextColor() const;
	virtual sf::Font getTextFont() const;
	virtual sf::Color getBackgroundColor() const;
	virtual unsigned getCharacterSize() const;
	virtual unsigned getOutlineThickness() const;
	virtual sf::Color getOutlineColor() const;

	/* SETTERS */
	virtual void setSize(const sf::Vector2f & v2_size_arg);
	virtual void setPosition(const sf::Vector2f & v2_position_arg);
	virtual void setText(const std::string & s_text_arg);
	virtual void setTextColor(const sf::Color & c_text_arg);
	virtual void setTextFont(const sf::Font & f_text_arg);
	virtual void setBackgroundColor(const sf::Color & c_background_arg);
	virtual void setCharacterSize(const unsigned u_text_arg);
	virtual void setOutlineThickness(const unsigned u_outline_thickness_arg);
	virtual void setOutlineColor(const sf::Color & c_outline_arg);

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

}

#endif // SFML_GUI_LABEL