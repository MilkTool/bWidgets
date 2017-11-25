#include <cassert>

#include "bwAbstractButton.h"
#include "bwPainter.h"
#include "bwTextBox.h"

#include "bwStyleBlenderFlat.h"

using namespace bWidgets;

const static bwWidgetStyle static_widget_styles[bwWidget::WIDGET_TYPE_TOT] = {
	[bwWidget::WIDGET_TYPE_CHECKBOX] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = 0.27451f,
				.highlighted = bwColor(0.27451f).shade(0.06f),
				.sunken = 0.27451f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 1.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 0.1f,
				.highlighted = 0.1f,
				.sunken = 0.1f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 1.0f,
				.highlighted = 1.0f,
				.sunken = 1.0f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 7.0f,
	},

	[bwWidget::WIDGET_TYPE_LABEL] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
			},
		},
	},

	[bwWidget::WIDGET_TYPE_NUMBER_SLIDER] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = 0.6f,
				.highlighted = bwColor(0.6f).shade(0.06f),
				.sunken = 0.6f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 1.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 0.2f,
				.highlighted = 0.2f,
				.sunken = 0.2f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 0.353f,
				.highlighted = 0.353f,
				.sunken = 0.353f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = false,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 4.0f,
	},

	[bwWidget::WIDGET_TYPE_PUSH_BUTTON] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = 0.6f,
				.highlighted = bwColor(0.6f).shade(0.06f),
				.sunken = 0.353f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 1.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 0.3f,
				.highlighted = 0.3f,
				.sunken = 0.3f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 8.0f,
	},

	[bwWidget::WIDGET_TYPE_RADIO_BUTTON] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = 0.27451f,
				.highlighted = bwColor(0.27451f).shade(0.06f),
				.sunken = bwColor(0.337255f, 0.501961f, 0.760784f),
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 1.0f,
				.highlighted = 1.0f,
				.sunken = 0.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 0.1f,
				.highlighted = 0.1f,
				.sunken = 0.1f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_CENTER,
		.roundbox_radius = 6.0f,
	},

	[bwWidget::WIDGET_TYPE_SCROLL_BAR] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = bwColor(80u, 180u),
				.highlighted = bwColor(80u, 180u).shade(0.06f),
				.sunken = bwColor(100u, 180u),
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 1.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 50u,
				.highlighted = 50u,
				.sunken = 50u,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 128u,
				.highlighted = 128u,
				.sunken = 128u,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = false,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 6.5f,
	},

	[bwWidget::WIDGET_TYPE_TEXT_BOX] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = 0.6f,
				.highlighted = bwColor(0.6f).shade(0.06f),
				.sunken = 0.6f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 1.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = 0.2f,
				.highlighted = 0.2f,
				.sunken = 0.2f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 0.353f,
				.highlighted = 0.353f,
				.sunken = 0.353f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 0,
		.invert_shade_on_sunken = false,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 4.0f,
	},
};

bwStyleBlenderFlat::bwStyleBlenderFlat() :
    bwStyle(STYLE_BLENDER_FLAT, static_widget_styles)
{
	
}

void bwStyleBlenderFlat::setWidgetStyle(const bwWidget& widget)
{
	const bwAbstractButton* button = widget_cast<const bwAbstractButton*>(&widget);

	if (button) {
		widget_styles[widget.type].roundbox_corners = button->rounded_corners;
	}
	else {
		widget_styles[widget.type].roundbox_corners = RoundboxCorner::ALL;
	}
}