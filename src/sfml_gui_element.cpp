#include "sfml_gui_element.hpp"

using namespace sf::GUI;

int Element::id_counter = 0;

void Element::onFocus(const std::function<void()> f_arg) {
	f_arg();
}

void Element::onClick(const std::function<void()> f_arg) {
	f_arg();
}

void Element::setId() {
	id = ++id_counter;
}

const int Element::getId() {
	return id;
}