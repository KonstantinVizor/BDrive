#include "../../inc/render/BaseRender.h"

BDrive::Render::BaseRender::BaseRender(RenderType type) :
					_type(type)
{}

BDrive::Render::BaseRender& BDrive::Render::BaseRender::setType(RenderType type)
{
	_type = type;
	return *this;
}

BDrive::Render::RenderType BDrive::Render::BaseRender::getType() const
{
	return _type;
}
