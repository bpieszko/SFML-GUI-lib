#include "sfml_gui_label.hpp"

using namespace sf::GUI;

/* DRAW */
void Label::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	sf::RectangleShape rs_label;
	rs_label.setSize(v2_size);
	rs_label.setPosition(v2_position);
	rs_label.setFillColor(c_background);

	sf::Text t_text;
	t_text.setString(s_text);
	t_text.setCharacterSize(u_text);
	t_text.setFont(f_text);
	t_text.setColor(c_text);

	double x_text = rs_label.getPosition().x + rs_label.getSize().x / 2.0f;
	double y_text = rs_label.getPosition().y + rs_label.getSize().y / 2.0f;

	sf::FloatRect r_text = t_text.getLocalBounds();
	t_text.setOrigin(r_text.left + r_text.width/2.0f, r_text.top + r_text.height/2.0f);
	t_text.setPosition(sf::Vector2f(x_text, y_text));

	target.draw(rs_label, states);
	target.draw(t_text, states);
}

/* GETTERS */
std::string Label::getText() const {
	return s_text;
}

sf::Color Label::getTextColor() const {
	return c_text;
}

sf::Font Label::getTextFont() const {
	return f_text;
}

sf::Color Label::getBackgroundColor() const {
	return c_background;
}

sf::Vector2f Label::getSize() const {
	return v2_size;
}

sf::Vector2f Label::getPosition() const {
	return v2_position;
}

unsigned Label::getCharacterSize() const {
	return u_text;
}

/* SETTERS */
void Label::setText(const std::string & s_text_arg) {
	s_text = s_text_arg;
}

void Label::setTextColor(const sf::Color & c_text_arg) {
	c_text = c_text_arg;
}

void Label::setTextFont(const sf::Font & f_text_arg) {
	f_text = f_text_arg;
}

void Label::setBackgroundColor(const sf::Color & c_background_arg) {
	c_background = c_background_arg;
}

void Label::setSize(const sf::Vector2f & v2_size_arg) {
	v2_size = v2_size_arg;
}

void Label::setPosition(const sf::Vector2f & v2_position_arg) {
	v2_position = v2_position_arg;
}

void Label::setCharacterSize(const unsigned u_text_arg) {
	u_text = u_text_arg;
}