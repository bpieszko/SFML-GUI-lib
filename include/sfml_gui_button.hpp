#ifndef SFML_GUI_BUTTON
#define SFML_GUI_BUTTON

#include <SFML/Graphics.hpp>
#include <string>

namespace sf::GUI 
{

class Button : public sf::Drawable {
/* VARIABLES */
public:

private:
	sf::Vector2f 	v2_size;
	sf::Vector2f 	v2_position;

	sf::Color		c_background;

	unsigned		u_outline_thickness;
	sf::Color		c_outline;
	
	std::string 	s_text;
	sf::Color		c_text;
	sf::Font		f_text;
	unsigned		u_text;

	/* Colors on hover */
	sf::Color		c_background_hover;
	sf::Color		c_text_hover;
	sf::Color		c_outline_hover;

	/* Colors on clicked */
	sf::Color		c_background_clicked;

	bool 			is_clicked;
	bool 			is_on_hover;

/* METHODS */
public:
	Button() = default;
	~Button() = default;

	/* GETTERS */
	std::string getText() const;
	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	sf::Color getBackgroundColor() const;
	sf::Color getTextColor() const;
	sf::Font getTextFont() const;
	sf::Color getBackgroundColorHover() const;
	sf::Color getTextColorHover() const;
	unsigned getOutlineThickness() const;
	sf::Color getOutlineColor() const;
	sf::Color getOutlineColorHover() const;
	unsigned getCharacterSize() const;
	sf::Color getBackgroundColorClicked() const;

	/* SETTERS */
	void setText(const std::string & s_text_arg);
	void setSize(const sf::Vector2f & v2_size_arg);
	void setPosition(const sf::Vector2f & v2_position_arg);
	void setBackgroundColor(const sf::Color & c_background_arg);
	void setTextColor(const sf::Color & c_text_arg);
	void setTextFont(const sf::Font & f_text_arg);
	void setBackgroundColorHover(const sf::Color & c_background_hover_arg);
	void setTextColorHover(const sf::Color & c_text_hover_arg);
	void setOutlineThickness(const unsigned u_outline_thickness_arg);
	void setOutlineColor(const sf::Color & c_outline_arg);
	void setOutlineColorHover(const sf::Color & c_outline_hover_arg);
	void setCharacterSize(const unsigned u_text_arg);
	void setBackgroundColorClicked(const sf::Color & c_background_clicked_arg);

	/* OTHER */
	bool isClicked() const;
	void onClick();
	void onHover(const int x_mouse, const int y_mouse);
	bool isOnHover() const;
	void onRelease();

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

}

#endif // SFML_GUI_BUTTON