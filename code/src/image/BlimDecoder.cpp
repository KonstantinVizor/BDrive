#include "../../inc/image/BlimDecoder.h"
#include "../../libs/bitIO/inc/BitReader.h"
#include <exception>

void BDrive::BlimDecoder::_readHeader(BitReader &reader)
{
	uint8_t headerString[5] = "BLIM";
	std::pair<long, int> readed;
	for (int i = 0; i < 5; i++)
		if ((char)reader.read(8).first != headerString[i])
			throw std::exception();	
	readed = reader.read(16);
	_height = readed.first;
	readed = reader.read(16);
	_width = readed.first;
	readed = reader.read(16);
	_rCount = readed.first;
	readed = reader.read(16);
	_gCount = readed.first;
	readed = reader.read(16);
	_bCount = readed.first;
	readed = reader.read(16);
	_alphaCount = readed.first;

}

#include <iostream>
#include <bitset>

void BDrive::BlimDecoder::_readAlphabet(std::map<uint8_t, uint64_t> &alphabet, uint16_t count, BitReader &reader)
{
	std::pair<long, int> readed;
	uint8_t chanel;
	std::cout << "Start reading alphabet\n";
	std::cout << count << "\n";
	for (uint16_t i = 0; i < count; i++)
	{
		readed = reader.read(8);
		chanel = readed.first;
		readed = reader.read(8);
		readed = reader.read(readed.first);
		alphabet[chanel] = readed.first;
	}
	std::cout << "Alphabet read\n";
	for (std::map<uint8_t, uint64_t>::const_iterator it = alphabet.begin(); it !=alphabet.end(); it++)
	{
		std::cout << it->first << "\t" << std::bitset<100>(it->second) << "\n";
	}
	std::cout << "\n";
}

uint8_t BDrive::BlimDecoder::_readHaffmanCode(const std::map<uint8_t, uint64_t> &alphabet, BitReader &reader)
{
	std::cout << "Start readding haffman\n";

	for (std::map<uint8_t, uint64_t>::const_iterator it = alphabet.begin(); it !=alphabet.end(); it++)
	{
		std::cout << it->first << "\t" << std::bitset<100>(it->second) << "\n";
	}
	std::cout << "\n";
	std::pair<long, int> readed;
	uint64_t chanel = 0;
	do
	{
		readed = reader.read(1);
		chanel <<= 1;
		chanel |= readed.first & 0b1;
		std::cout << std::bitset<100>(chanel) << "\n";
	} while (alphabet.find(chanel) == alphabet.end());	
//	std::cout << std::bitset<10>(chanel) << "\t" << (int)alphabet.find(chanel)->first << "\n";
	std::cout << "Haffman read\n";
	return alphabet.find(chanel)->first;
}

BDrive::Image BDrive::BlimDecoder::_readImage(uint16_t height, uint16_t width, BitReader &reader)
{
	Image result(height, width);
	Color color;
	std::cout << "Start reading image\n";
	for (uint16_t i = 0; i < _height; i++)
		for (uint16_t j = 0; j < _width; j++)
		{
			color.setR(_readHaffmanCode(_rAlphabet, reader));
			color.setG(_readHaffmanCode(_gAlphabet, reader));
			color.setB(_readHaffmanCode(_bAlphabet, reader));
			color.setAlpha(_readHaffmanCode(_alphaAlphabet, reader));
			result.setPixel(i, j, color);
		}
	std::cout << "Image read\n";
	return result;
}

BDrive::Image BDrive::BlimDecoder::decode(const std::string &filename)
{
	BitReader reader(filename);
	Image result;
	_readHeader(reader);
	_readAlphabet(_rAlphabet, _rCount, reader);
	_readAlphabet(_gAlphabet, _gCount, reader);
	_readAlphabet(_bAlphabet, _bCount, reader);
	_readAlphabet(_alphaAlphabet, _alphaCount, reader);
	result = _readImage(_height, _width, reader);
	reader.close();
	return result;
}

const BDrive::BlimDecoder& BDrive::BlimDecoder::operator =([[maybe_unused]]const BlimDecoder &decoder)
{
	return *this;
}
