#include "sfml_gui_textfield.hpp"
#include <iostream>

using namespace sf::GUI;

/* DRAW */
void TextField::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	sf::RectangleShape rs_textfield;
	rs_textfield.setSize(v2_size);
	rs_textfield.setPosition(v2_position);
	rs_textfield.setFillColor(c_background);
	rs_textfield.setOutlineThickness(u_outline_thickness);
	rs_textfield.setOutlineColor(c_outline);

	sf::Text t_text;
	t_text.setCharacterSize(u_text);
	t_text.setFont(f_text);
	if (this->isChosen()) {
		t_text.setColor(c_text);
		t_text.setString(s_text);
	}
	else if (this->getText().empty()) {
		t_text.setColor(c_text_default);
		t_text.setString(s_text_default);
	}

	double x_text = rs_textfield.getPosition().x + rs_textfield.getSize().x / 2.0f;
	double y_text = rs_textfield.getPosition().y + rs_textfield.getSize().y / 2.0f;

	sf::FloatRect r_text = t_text.getLocalBounds();
	t_text.setOrigin(r_text.left + r_text.width / 2.0f, r_text.top + r_text.height / 2.0f);
	t_text.setPosition(sf::Vector2f(x_text, y_text));
	
	target.draw(rs_textfield, states);
	target.draw(t_text, states);
}

/* GETTERS */
sf::Vector2f TextField::getSize() const {
	return v2_size;
}

sf::Vector2f TextField::getPosition() const {
	return v2_position;
}

sf::Font TextField::getTextFont() const {
	return f_text;
}
unsigned TextField::getCharacterSize() const {
	return u_text;
}

std::string TextField::getText() const {
	return s_text;
}

sf::Color TextField::getTextColor() const {
	return c_text;
}

std::string TextField::getTextDefault() const {
	return s_text_default;
}

sf::Color TextField::getTextDefaultColor() const {
	return c_text_default;
}

sf::Color TextField::getBackgroundColor() const {
	return c_background;
}

unsigned TextField::getOutlineThickness() const {
	return u_outline_thickness;
}

sf::Color TextField::getOutlineColor() const {
	return c_outline;
}

unsigned TextField::getMaxCharacters() const {
	return u_max_characters;
}

/* SETTERS */
void TextField::setSize(const sf::Vector2f & v2_size_arg) {
	v2_size = v2_size_arg;
}

void TextField::setPosition(const sf::Vector2f & v2_position_arg) {
	v2_position = v2_position_arg;
}

void TextField::setTextFont(const sf::Font & f_text_arg) {
	f_text = f_text_arg;
}

void TextField::setCharacterSize(const unsigned u_text_arg) {
	u_text = u_text_arg;
}

void TextField::setText(const std::string & s_text_arg) {
	s_text = s_text_arg;
}

void TextField::setTextColor(const sf::Color & c_text_arg) {
	c_text = c_text_arg;
}

void TextField::setDefaultText(const std::string & s_text_default_arg) {
	s_text_default = s_text_default_arg;
}

void TextField::setDefaultTextColor(const sf::Color & c_text_default_arg) {
	c_text_default = c_text_default_arg;
}

void TextField::setBackgroundColor(const sf::Color & c_background_arg) {
	c_background = c_background_arg;
}

void TextField::setOutlineThickness(const unsigned u_outline_thickness_arg) {
	u_outline_thickness = u_outline_thickness_arg;
}

void TextField::setOutlineColor(const sf::Color & c_outline_arg) {
	c_outline = c_outline_arg;
}

void TextField::setMaxCharacters(const unsigned u_max_characters_arg) {
	u_max_characters = u_max_characters_arg;
}

/* OTHER */

void TextField::onChosen(const int x_mouse, const int y_mouse) {
	if (x_mouse >= this->getPosition().x &&
		x_mouse <= this->getPosition().x + this->getSize().x &&
		y_mouse >= this->getPosition().y &&
		y_mouse <= this->getPosition().y + this->getSize().y)
		is_chosen = true;
	else
		is_chosen = false;
}

bool TextField::isChosen() const {
	return is_chosen;
}

void TextField::addTextBack(const char append_char) {
	if (s_text.size() < this->getMaxCharacters())
		s_text += append_char;
}

void TextField::setChosen(const int x_mouse, const int y_mouse) {
	if (!(x_mouse >= this->getPosition().x &&
		x_mouse <= this->getPosition().x + this->getSize().x &&
		y_mouse >= this->getPosition().y &&
		y_mouse <= this->getPosition().y + this->getSize().y))
		is_chosen = false;
}

void TextField::eraseTextBack() {
	if (!s_text.empty())
		s_text.pop_back();
}