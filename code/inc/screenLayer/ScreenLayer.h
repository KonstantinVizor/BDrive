#ifndef __SCREENLAYER_H__
#define __SCREENLAYER_H__

#include <vector>
#include <memory>
#include "../visControls/BaseControl.h"

namespace BDrive
{
	/// Класс, представляющий слой окна
	/*!
	 * Слой окна - область, выполняющая определенную задачу.
	 * Например окно игры или меню
	 */
	class ScreenLayer
	{
		private:
			std::vector<std::shared_ptr<VisualControls::BaseControl>> _controls;
			bool _isShowed;
			uint16_t _width;
			uint16_t _height;
			uint16_t _xpos;
			uint16_t _ypos;

		public:
			~ScreenLayer() = default;
			ScreenLayer();
			explicit ScreenLayer(const ScreenLayer &layer);
			ScreenLayer(ScreenLayer &&layer);

			/*! \details
			 * Добавляет контрол в список
			 * \rapam control Контрол для добавления
			 * \result Ссылку на себя
			 */
			ScreenLayer& addControl(const std::shared_ptr<VisualControls::BaseControl> &control);

			/*! \details
			 * Удаляет контрол из списка
			 * \param index Индекс кнотрола в списке
			 * \result Ссылку на себя
			 */
			ScreenLayer& removeControl(uint32_t index);

			/*! \details
			 * Возвращает контрол по индексу
			 * \param index Индекс контрола в списке
			 * \result Контрол
			 */
			const std::shared_ptr<VisualControls::BaseControl>& getControl(uint32_t index) const;

			/// \details Возвращает количество контролов в списке
			uint32_t getControlsCount() const;

			/// \details Возвращает ширину слоя
			uint16_t getWidth() const;

			/// \details Возвращает высоту слоя
			uint16_t getHeight() const;

			/// \details Возвращает положение слоя по горизонтали
			uint16_t getXpos() const;

			/// \details Возвращает положение слоя по вертикали
			uint16_t getYpos() const;

			/// \details Возвращает true, если слой показан. false иначе
			bool isShowed() const;

			/*! \details
			 * Устанавливает флаг показа слоя
			 * \param isShowed флаг показа слоя
			 * \return Ссылку на себя
			 */
			ScreenLayer& setIsShowed(bool isShowed);

			/*! \details
			 * Задает ширину слоя
			 * \param height Ширина слоя
			 * \return Ссылку на себя
			 */
			ScreenLayer& setWidth(uint16_t width);

			/*! \details
			 * Задает высоту слоя
			 * \param height Высота слоя
			 * \return Ссылку на себя
			 */
			ScreenLayer& setHeight(uint16_t height);

			/*! \details
			 * Задает положение слоя по горизонтали
			 * Началом координат принимается верхний левый угол экрана
			 * \param xpos Положение слоя по горизонтали
			 * \return Ссылку на себя
			 */
			ScreenLayer& setXpos(uint16_t xpos);

			/*! \details
			 * Задает положение слоя по вертикали
			 * Началом координат принимается верхний левый угол экрана
			 * \param ypos Положение слоя по вертикали
			 * \return Ссылку на себя
			 */
			ScreenLayer& setYpos(uint16_t ypos);

			const ScreenLayer& operator =(const ScreenLayer &layer);
	};
}

#endif
