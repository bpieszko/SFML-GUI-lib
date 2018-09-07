#ifndef SFML_GUI_TEXTFIELD
#define SFML_GUI_TEXTFIELD

#include <SFML/Graphics.hpp>
#include <string>

namespace sf::GUI
{

class TextField : public sf::Drawable {
/* VARIABLES */
public:
	
private:
	sf::Vector2f	v2_size;
	sf::Vector2f	v2_position;

	sf::Font		f_text;
	unsigned 		u_text;

	std::string		s_text;
	sf::Color		c_text;
	
	std::string		s_text_default;
	sf::Color		c_text_default;

	sf::Color		c_background;

	unsigned		u_outline_thickness;
	sf::Color		c_outline;

	unsigned 		u_max_characters;

	bool 			is_chosen = false;

/* METHODS */
public:
	TextField() = default;
	~TextField() = default;

	/* GETTERS */
	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	sf::Font getTextFont() const;
	unsigned getCharacterSize() const;
	std::string getText() const;
	sf::Color getTextColor() const;
	std::string getTextDefault() const;
	sf::Color getTextDefaultColor() const;
	sf::Color getBackgroundColor() const;
	unsigned getOutlineThickness() const;
	sf::Color getOutlineColor() const;
	unsigned getMaxCharacters() const;

	/* SETTERS */
	void setSize(const sf::Vector2f & v2_size_arg);
	void setPosition(const sf::Vector2f & v2_position_arg);
	void setTextFont(const sf::Font & f_text_arg);
	void setCharacterSize(const unsigned u_text_arg);
	void setText(const std::string & s_text_arg);
	void setTextColor(const sf::Color & c_text_arg);
	void setDefaultText(const std::string & s_text_default_arg);
	void setDefaultTextColor(const sf::Color & c_text_default_arg);
	void setBackgroundColor(const sf::Color & c_background_arg);
	void setOutlineThickness(const unsigned u_outline_thickness_arg);
	void setOutlineColor(const sf::Color & c_outline_arg);
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