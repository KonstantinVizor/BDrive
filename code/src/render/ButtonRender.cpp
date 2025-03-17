#include "../../inc/render/ButtonRender.h"
#include "../../inc/visControls/Button.h"

BDrive::Render::ButtonRender::ButtonRender() :
				BaseRender(RenderType::BUTTONRENDER)
{}

BDrive::Render::ButtonRender::ButtonRender(const ButtonRender &render) :
						BaseRender(render._type)
{}

BDrive::Render::ButtonRender::ButtonRender(ButtonRender &&render) :
						BaseRender(render._type)
{}

void BDrive::Render::ButtonRender::render(Canvas &canvas, uint32_t index, ScreenLayer &layer)
{
	VisualControls::Button &button = layer.getControl(index)->cast<VisualControls::Button>();
	Color color, bcolor;
	double alpha;
	double u, v;
	for (uint16_t i = 0; i < button.getHeight(); i++)
		for (uint16_t j = 0; j < button.getWidth(); j++)
			if (i < canvas.getHeight() && j < canvas.getWidth())
			{
				color = canvas.getPixel(i + button.getY(), j + button.getX());
				if (button.hasBackgroundImage())
				{
					u = (double)button.getHeight() / i;
					v = (double)button.getWidth() / j;
					bcolor = button.getBackgroundImage().getPixel(u, v);
				}
				else if (button.hasBackgroundColor())
					bcolor = button.getBackgroundColor();
				alpha = bcolor.getAlpha() / 255.0;
				color = (color * (1 - alpha)) + (bcolor * alpha);
				canvas.setPixel(i + button.getY(), j + button.getX(), color);
			}
	return;
}

const BDrive::Render::ButtonRender& BDrive::Render::ButtonRender::operator =(const ButtonRender &render)
{
	_type = render._type;
	return *this;
}
