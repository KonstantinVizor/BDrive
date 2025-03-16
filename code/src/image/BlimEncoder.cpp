#include "../../inc/image/BlimEncoder.h"

void BDrive::BlimEncoder::_createAlphabets(const Image &image)
{
	std::map<uint64_t, uint32_t> rMap, gMap, bMap, alphaMap;
	Color color;
	Haffman haffman;
	for (uint16_t i = 0; i < image.getHeight(); i++)
		for (uint16_t j = 0; j < image.getWidth(); j++)
		{
			color = image.getPixel(i, j);
			if (rMap.find(color.getR()) == rMap.end())
				rMap[color.getR()] = 1;
			else
				rMap[color.getR()]++;
			if (gMap.find(color.getG()) == gMap.end())
				gMap[color.getG()] = 1;
			else
				gMap[color.getG()]++;
			if (bMap.find(color.getB()) == bMap.end())
				bMap[color.getB()] = 1;
			else
				bMap[color.getB()]++;
			if (alphaMap.find(color.getAlpha()) == alphaMap.end())
				alphaMap[color.getAlpha()] = 1;
			else
				alphaMap[color.getAlpha()]++;
		}
	_rAlphabet = haffman.createAlphabet(rMap);
	_gAlphabet = haffman.createAlphabet(gMap);
	_bAlphabet = haffman.createAlphabet(bMap);
	_alphaAlphabet = haffman.createAlphabet(alphaMap);
}

void BDrive::BlimEncoder::_writeHeader(uint8_t headerString[5],
					uint16_t height,
					uint16_t width,
					BitWriter &writer) const
{
	for (uint16_t i = 0; i < 5; i++)
		writer.write(headerString[i], 8);
	writer.write(height, 16);
	writer.write(width, 16);
	writer.write((uint16_t)_rAlphabet.size(), 16);
	writer.write((uint16_t)_gAlphabet.size(), 16);
	writer.write((uint16_t)_bAlphabet.size(), 16);
	writer.write((uint16_t)_alphaAlphabet.size(), 16);
	for (Haffman::Alphabet::const_iterator it = _rAlphabet.begin(); it != _rAlphabet.end(); it++)
	{
		writer.write((uint8_t)it->first, 8);
		writer.write(it->second.second, 8);
		writer.write(it->second.first, it->second.second);
	}
	for (Haffman::Alphabet::const_iterator it = _gAlphabet.begin(); it != _gAlphabet.end(); it++)
	{
		writer.write((uint8_t)it->first, 8);
		writer.write(it->second.second, 8);
		writer.write(it->second.first, it->second.second);
	}
	for (Haffman::Alphabet::const_iterator it = _bAlphabet.begin(); it != _bAlphabet.end(); it++)
	{
		writer.write((uint8_t)it->first, 8);
		writer.write(it->second.second, 8);
		writer.write(it->second.first, it->second.second);
	}
	for (Haffman::Alphabet::const_iterator it = _alphaAlphabet.begin(); it != _alphaAlphabet.end(); it++)
	{
		writer.write((uint8_t)it->first, 8);
		writer.write(it->second.second, 8);
		writer.write(it->second.first, it->second.second);
	}
}

void BDrive::BlimEncoder::_writeData(const Image &image, BitWriter &writer) const
{
	Color color;
	for (uint16_t i = 0; i < image.getHeight(); i++)
		for (uint16_t j = 0; j < image.getWidth(); j++)
		{
			color = image.getPixel(i, j);
			writer.write(_rAlphabet.at(color.getR()).first, _rAlphabet.at(color.getR()).second);
			writer.write(_gAlphabet.at(color.getG()).first, _gAlphabet.at(color.getG()).second);
			writer.write(_bAlphabet.at(color.getB()).first, _bAlphabet.at(color.getB()).second);
			writer.write(_alphaAlphabet.at(color.getAlpha()).first, _alphaAlphabet.at(color.getAlpha()).second);
		}
}

void BDrive::BlimEncoder::encode(const std::string &filename, const Image &image)
{
	uint8_t headerString[5] = "BLIM";
	BitWriter writer(filename);
	_createAlphabets(image);
	_writeHeader(headerString, image.getHeight(), image.getWidth(), writer);
	_writeData(image, writer);
	writer.close();
}

const BDrive::BlimEncoder& BDrive::BlimEncoder::operator =([[maybe_unused]]const BlimEncoder &encoder)
{
	return *this;
}
