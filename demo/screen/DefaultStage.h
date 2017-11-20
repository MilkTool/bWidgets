#pragma once

#include "bwRadioButton.h"

#include "Stage.h"

namespace bWidgetsDemo {

class DefaultStage : public Stage
{
public:
	DefaultStage(unsigned int mask_width, unsigned int mask_height);

private:
	void addStyleSelector(class LayoutItem& parent_layout);
	void addFakeSpacer(class LayoutItem& layout);

	static void StyleApplyButtonCb(
	        bWidgets::bwWidget& widget);
	static bool StyleButtonsUpdateCb(
	        bWidgets::bwWidget& widget_iter,
	        void* custom_data);
	static void applyUIScaleValueButtonCb(
	        bWidgets::bwWidget& widget);

	const unsigned int padding = 10;
};

} // namespace bWidgetsDemo
