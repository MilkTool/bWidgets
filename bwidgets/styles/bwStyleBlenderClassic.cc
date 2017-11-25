#include <assert.h>

#include "bwAbstractButton.h"
#include "bwPainter.h"
#include "bwStyleManager.h"
#include "bwTextBox.h"

#include "bwStyleBlenderClassic.h"

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
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 0.0f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 1.0f,
				.highlighted = 1.0f,
				.sunken = 1.0f,
			},
		},
		.shade_top = 15,
		.shade_bottom = -15,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 4.0f,
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
				.normal = 0.098f,
				.highlighted = 0.098f,
				.sunken = 0.098f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 0.353f,
				.highlighted = 0.353f,
				.sunken = 0.353f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 25,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 10.0f,
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
				.normal = 0.098f,
				.highlighted = 0.098f,
				.sunken = 0.098f,
			},
		},
		.shade_top = 15,
		.shade_bottom = -15,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 5.0f,
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
				.normal = 0.0f,
				.highlighted = 0.0f,
				.sunken = 0.0f,
			},
		},
		.shade_top = 15,
		.shade_bottom = -15,
		.invert_shade_on_sunken = true,
		.text_alignment = TEXT_ALIGN_CENTER,
		.roundbox_radius = 4.0f,
	},

	[bwWidget::WIDGET_TYPE_SCROLL_BAR] = {
		.state_colors = {
			[bwWidgetStyle::WIDGET_STYLE_COLOR_BACKGROUND] = {
				.normal = bwColor(80u, 180u),
				.highlighted = bwColor(80u, 180u).shade(0.06f),
				.sunken = bwColor(100u, 180u),
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_TEXT] = {
				.normal = 0u,
				.highlighted = 0u,
				.sunken = 255u
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_OUTLINE] = {
				.normal = bwColor(50u, 180u),
				.highlighted = 50u,
				.sunken = bwColor(50u, 180u),
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 128u,
				.highlighted = 128u,
				.sunken = bwColor(128u).shade(0.06f),
			},
		},
		.shade_top = 5,
		.shade_bottom = -5,
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
				.normal = 0.098f,
				.highlighted = 0.098f,
				.sunken = 0.098f,
			},
			[bwWidgetStyle::WIDGET_STYLE_COLOR_DECORATION] = {
				.normal = 0.353f,
				.highlighted = 0.353f,
				.sunken = 0.353f,
			},
		},
		.shade_top = 0,
		.shade_bottom = 25,
		.invert_shade_on_sunken = false,
		.text_alignment = TEXT_ALIGN_LEFT,
		.roundbox_radius = 4.0f,
	},
};

bwStyleBlenderClassic::bwStyleBlenderClassic() :
    bwStyle(STYLE_BLENDER_CLASSIC, static_widget_styles)
{
	
}

void bwStyleBlenderClassic::setWidgetStyle(const bwWidget& widget)
{
	const bwAbstractButton* button = widget_cast<const bwAbstractButton*>(&widget);

	if (button) {
		widget_styles[widget.type].roundbox_corners = button->rounded_corners;
	}
	else {
		widget_styles[widget.type].roundbox_corners = RoundboxCorner::ALL;
	}
}