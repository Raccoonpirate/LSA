#pragma once

#include "Widget.hpp"

class Layout : public Widget {
	public:
		//Layout(const Layout&) = delete;
		//Layout& operator=(const Layout&) = delete;

		Layout(Widget* parent = nullptr);
		virtual ~Layout();

		void SetSpace(float pixels);

	protected:
		friend class Container;

		float _space;
};