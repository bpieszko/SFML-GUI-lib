#ifndef SFML_GUI_TEXTFIELD
#define SFML_GUI_TEXTFIELD

#include <SFML/Graphics.hpp>
#include "sfml_gui_element.hpp"
#include <string>

namespace sf::GUI
{

class TextField : public Element {
/* VARIABLES */
public:
	
private:
	std::string		s_text_default;
	sf::Color		c_text_default;

	unsigned 		u_max_characters;

	bool 			is_chosen = false;

/* METHODS */
public:
	TextField() = default;
	~TextField() = default;

	/* GETTERS */
	virtual sf::Vector2f getSize() const;
	virtual sf::Vector2f getPosition() const;
	virtual sf::Font getTextFont() const;
	virtual std::string getText() const;
	virtual sf::Color getTextColor() const;
	virtual unsigned getCharacterSize() const;
	virtual sf::Color getBackgroundColor() const;
	virtual unsigned getOutlineThickness() const;
	virtual sf::Color getOutlineColor() const;
	unsigned getMaxCharacters() const;
	std::string getTextDefault() const;
	sf::Color getTextDefaultColor() const;

	/* SETTERS */
	virtual void setSize(const sf::Vector2f & v2_size_arg);
	virtual void setPosition(const sf::Vector2f & v2_position_arg);
	virtual void setTextFont(const sf::Font & f_text_arg);
	virtual void setCharacterSize(const unsigned u_text_arg);
	virtual void setText(const std::string & s_text_arg);
	virtual void setBackgroundColor(const sf::Color & c_background_arg);
	virtual void setOutlineThickness(const unsigned u_outline_thickness_arg);
	virtual void setOutlineColor(const sf::Color & c_outline_arg);
	virtual void setTextColor(const sf::Color & c_text_arg);
	void setDefaultText(const std::string & s_text_default_arg);
	void setDefaultTextColor(const sf::Color & c_text_default_arg);
	void setMaxCharacters(const unsigned u_max_characters_arg);

	/* OTHER */
	void setChosen(const int x_mouse, const int y_mouse);
	void onChosen(const int x_mouse, const int y_mouse);
	bool isChosen() const;
	void addTextBack(const char append_char);
	void eraseTextBack();

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

}

#endif // SFML_GUI_TEXTFIELD