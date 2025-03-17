#include "../../inc/image/ImageIO.h"
//#include "../../libs/oiio/OpenImageIO/imageio.h"

BDrive::Image BDrive::ImageIO::read(const std::string &filename) const
{
	BDrive::Image result;
//	BDrive::Color color;
//	uint32_t width, height, channels;
//	uint32_t counter = 0;
//	std::unique_ptr<OIIO::ImageInput> input = OIIO::ImageInput::open(filename);
//	width = input->spec().width;
//	height = input->spec().height;
//	channels = input->spec().nchannels;
//	result = BDrive::Image(height, width);
//	std::vector<uint8_t> pixels(width * height * channels);
//	input->read_image(0, 0, 0, channels, OIIO::TypeDesc::UINT8, pixels.data());
//	input->close();
//	for (uint16_t i = 0; i < height; i++)
//		for (uint16_t j = 0; j < width; j++)
//		{
//			color.setR(pixels[counter]);	
//			color.setG(pixels[counter + 1]);	
//			color.setB(pixels[counter + 2]);	
//			if (channels == 4)
//				color.setAlpha(pixels[counter + 3]);	
//			else
//				color.setAlpha(255);
//			counter += channels;
//			result.setPixel(i, j, color);
//		}
	return result;
}

void BDrive::ImageIO::write(const std::string &filename, const Image &image) const
{
//	OIIO::ImageSpec spec(image.getWidth(),image.getHeight(), 4);
//	std::unique_ptr<OIIO::ImageOutput> output = OIIO::ImageOutput::create(filename);
//	output->open(filename, spec);
//	std::vector<uint8_t> pixels(image.getHeight() * image.getWidth() * 4);	
//	Color color;
//	uint32_t counter = 0;
//	for (uint16_t i = 0; i < image.getHeight(); i++)
//		for (uint16_t j = 0; j < image.getWidth(); j++)
//		{
//			color = image.getPixel(i, j);
//			pixels[counter++] = color.getR();
//			pixels[counter++] = color.getG();
//			pixels[counter++] = color.getB();
//			pixels[counter++] = color.getAlpha();
//		}
//	output->write_image(OIIO::TypeDesc::UINT8, pixels.data());
//	output->close();
}

const BDrive::ImageIO& BDrive::ImageIO::operator =([[maybe_unused]] const ImageIO &)
{
	return *this;
}
