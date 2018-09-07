#ifndef SFML_GUI_ELEMENT
#define SFML_GUI_ELEMENT

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

namespace sf::GUI
{

class Element : public sf::Drawable {
/* VARIABLES */
public:
	
protected:
	static int		id_counter;
	int				id;

	sf::Vector2f	v2_size;
	sf::Vector2f	v2_position;

	unsigned		u_outline_thickness;

	sf::Font		f_text;
	unsigned		u_text;

	struct {
		sf::Color	c_background;
		sf::Color	c_outline;
		
		std::string s_text;
		sf::Color	c_text;

		
	} o_default, o_focused, o_clicked;

	bool is_focused;

private:

/* METHODS */
public:
	Element() = default;
	~Element() = default;

	const int getId();
	virtual sf::Vector2f getSize() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
	virtual sf::Color getBackgroundColor() const = 0;
	virtual std::string getText() const = 0;
	virtual sf::Color getTextColor() const = 0;
	virtual sf::Font getTextFont() const = 0;
	virtual unsigned getCharacterSize() const = 0;
	virtual unsigned getOutlineThickness() const = 0;
	virtual sf::Color getOutlineColor() const = 0;

	void setId();
	virtual void setSize(const sf::Vector2f &) = 0;
	virtual void setPosition(const sf::Vector2f &) = 0;
	virtual void setBackgroundColor(const sf::Color &) = 0;
	virtual void setText(const std::string &) = 0;
	virtual void setTextColor(const sf::Color &) = 0;
	virtual void setTextFont(const sf::Font &) = 0;
	virtual void setCharacterSize(const unsigned) = 0;
	virtual void setOutlineThickness(const unsigned) = 0;
	virtual void setOutlineColor(const sf::Color &) = 0;

	virtual void onFocus(const std::function<void()> f_arg);
	virtual void onClick(const std::function<void()> f_arg);

private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const = 0;
};

}

#endif // SFML_GUI_ELEMENT