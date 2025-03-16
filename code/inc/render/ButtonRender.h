#ifndef __BUTTONRENDER_H__
#define __BUTTONRENDER_H__

#include "BaseRender.h"

namespace BDrive
{
namespace Render
{
	/// Класс, представляющий рендер объекта Button
	class ButtonRender : public BaseRender
	{
		public:
			~ButtonRender() = default;
			ButtonRender();
			explicit ButtonRender(const ButtonRender &render);
			ButtonRender(ButtonRender &&render);

			/// \details Является переопределением метода BaseRender::render
			virtual void render(const std::shared_ptr<Canvas> &canvas, uint32_t index, const ScreenLayer &layer) override;

			const ButtonRender& operator =(const ButtonRender &render);
	};
}
}

#endif
