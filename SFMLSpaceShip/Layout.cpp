#include "Layout.hpp"

Layout::Layout(Widget* parent) : Widget(parent), _space(5) {
}

Layout::~Layout() {
}

void Layout::SetSpace(float pixels) {
	if (pixels >= 0) {
		_space = pixels;
		UpdateShape();
	} else {
		throw std::invalid_argument("pixel value must be >= 0");
	}
}