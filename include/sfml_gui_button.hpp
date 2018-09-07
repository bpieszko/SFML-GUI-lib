#ifndef SFML_GUI_BUTTON
#define SFML_GUI_BUTTON

#include <SFML/Graphics.hpp>
#include "sfml_gui_element.hpp"
#include <string>

namespace sf::GUI 
{

class Button : public Element {
/* VARIABLES */
public:

private:
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
	virtual sf::Vector2f getSize() const;
	virtual sf::Vector2f getPosition() const;
	virtual std::string getText() const;
	virtual sf::Color getBackgroundColor() const;
	virtual sf::Color getTextColor() const;
	virtual sf::Font getTextFont() const;
	virtual unsigned getOutlineThickness() const;
	virtual sf::Color getOutlineColor() const;
	virtual unsigned getCharacterSize() const;
	sf::Color getBackgroundColorHover() const;
	sf::Color getTextColorHover() const;
	sf::Color getOutlineColorHover() const;
	sf::Color getBackgroundColorClicked() const;

	/* SETTERS */
	virtual void setSize(const sf::Vector2f & v2_size_arg);
	virtual void setPosition(const sf::Vector2f & v2_position_arg);
	virtual void setText(const std::string & s_text_arg);
	virtual void setBackgroundColor(const sf::Color & c_background_arg);
	virtual void setTextColor(const sf::Color & c_text_arg);
	virtual void setTextFont(const sf::Font & f_text_arg);
	virtual void setOutlineThickness(const unsigned u_outline_thickness_arg);
	virtual void setOutlineColor(const sf::Color & c_outline_arg);
	virtual void setCharacterSize(const unsigned u_text_arg);
	void setBackgroundColorHover(const sf::Color & c_background_hover_arg);
	void setTextColorHover(const sf::Color & c_text_hover_arg);
	void setOutlineColorHover(const sf::Color & c_outline_hover_arg);
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