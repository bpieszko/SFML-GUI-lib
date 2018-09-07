#include "sfml_gui_button.hpp"
using namespace sf::GUI;

/* DRAW */
void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	sf::RectangleShape rs_button;

	rs_button.setSize(v2_size);
	rs_button.setPosition(v2_position);
	rs_button.setOutlineThickness(u_outline_thickness);
	
	sf::Text t_text;
	t_text.setString(s_text);
	t_text.setCharacterSize(u_text);
	t_text.setFont(f_text);

	double x_text = rs_button.getPosition().x + rs_button.getSize().x / 2.0f;
	double y_text = rs_button.getPosition().y + rs_button.getSize().y / 2.0f;

	sf::FloatRect r_text = t_text.getLocalBounds();
	t_text.setOrigin(r_text.left + r_text.width/2.0f, r_text.top + r_text.height/2.0f);
	t_text.setPosition(sf::Vector2f(x_text, y_text));

	if (this->isOnHover()) {
		if (this->isClicked())
			rs_button.setFillColor(c_background_clicked);
		else
			rs_button.setFillColor(c_background_hover);
		rs_button.setOutlineColor(c_outline_hover);
		t_text.setColor(c_text_hover);
	}
	else {
		rs_button.setFillColor(c_background);
		rs_button.setOutlineColor(c_outline);
		t_text.setColor(c_text);
	}

	target.draw(rs_button, states);
	target.draw(t_text, states);
}

/* GETTERS */
std::string Button::getText() const {
	return s_text;
}

sf::Vector2f Button::getSize() const {
	return v2_size;
}

sf::Vector2f Button::getPosition() const {
	return v2_position;
}

sf::Color Button::getBackgroundColor() const {
	return c_background;
}

sf::Color Button::getTextColor() const {
	return c_text;
}

sf::Font Button::getTextFont() const {
	return f_text;
}

sf::Color Button::getBackgroundColorHover() const {
	return c_background_hover;
}

sf::Color Button::getTextColorHover() const {
	return c_text_hover;
}

unsigned Button::getOutlineThickness() const {
	return u_outline_thickness;
}

sf::Color Button::getOutlineColor() const {
	return c_outline;
}

sf::Color Button::getOutlineColorHover() const {
	return c_outline_hover;
}

unsigned Button::getCharacterSize() const {
	return u_text;
}


sf::Color Button::getBackgroundColorClicked() const {
	return c_background_clicked;
}

/* SETTERS */
void Button::setText(const std::string & s_text_arg) {
	s_text = s_text_arg;
}

void Button::setSize(const sf::Vector2f & v2_size_arg) {
	v2_size = v2_size_arg;
}

void Button::setPosition(const sf::Vector2f & v2_position_arg) {
	v2_position = v2_position_arg;
}

void Button::setBackgroundColor(const sf::Color & c_background_arg) {
	c_background = c_background_arg;
}

void Button::setTextColor(const sf::Color & c_text_arg) {
	c_text = c_text_arg;
}

void Button::setTextFont(const sf::Font & f_text_arg) {
	f_text = f_text_arg;
}

void Button::setBackgroundColorHover(const sf::Color & c_background_hover_arg) {
	c_background_hover = c_background_hover_arg;
}

void Button::setTextColorHover(const sf::Color & c_text_hover_arg) {
	c_text_hover = c_text_hover_arg;
}

void Button::setOutlineThickness(const unsigned u_outline_thickness_arg) {
	u_outline_thickness = u_outline_thickness_arg;
}

void Button::setOutlineColor(const sf::Color & c_outline_arg) {
	c_outline = c_outline_arg;
}

void Button::setOutlineColorHover(const sf::Color & c_outline_hover_arg) {
	c_outline_hover = c_outline_hover_arg;
}

void Button::setCharacterSize(const unsigned u_text_arg) {
	u_text = u_text_arg;
}

void Button::setBackgroundColorClicked(const sf::Color & c_background_clicked_arg) {
	c_background_clicked = c_background_clicked_arg;
}

/* OTHER */

bool Button::isClicked() const {
	return is_clicked;
}

void Button::onClick() {
	is_clicked = true;
}

void Button::onRelease() {
	is_clicked = false;
}

void Button::onHover(const int x_mouse, const int y_mouse) {
	if (x_mouse >= this->getPosition().x && 
		x_mouse <= this->getPosition().x + this->getSize().x &&
		y_mouse >= this->getPosition().y &&
		y_mouse <= this->getPosition().y + this->getSize().y)
		is_on_hover = true;
	else
		is_on_hover = false;
}

bool Button::isOnHover() const {
	return is_on_hover;
}