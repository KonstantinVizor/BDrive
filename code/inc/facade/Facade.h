#ifndef __FACADE_H__
#define __FACADE_H__

#include "../visPrimitives/Canvas.h"
#include "../screenLayer/ScreenLayer.h"
#include "../render/BaseRender.h"
#include <memory>
#include <map>

namespace BDrive
{
	/// \todo
	class Facade
	{
		private:
			std::shared_ptr<Canvas> _canvas;
			std::vector<std::shared_ptr<ScreenLayer>> _layers;
			std::map<VisualControls::ControlType, std::shared_ptr<Render::BaseRender>> _renders;
			std::vector<std::shared_ptr<ScreenLayer>> _curLayeres;
		
		public:
			~Facade() = default;
			Facade() = default;
			explicit Facade(const Facade &facade);
			Facade(Facade &&facade);

			Facade& setCanvas(const std::shared_ptr<Canvas> &canvas);
			Facade& addLayer(const std::shared_ptr<ScreenLayer> &layer);
			Facade& addRender(VisualControls::ControlType type, const std::shared_ptr<Render::BaseRender> &render);

			void leftMouseClick();
			void RightMouseClick();
			void keyClick(uint8_t key);

			const Facade& operator =(const Facade &facade);
	};
}

#endif
