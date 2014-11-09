#include "stdafx.h"
#include "trg.hpp"
#include <fstream>
#include <sstream>
#include <string>
#define DLLEXPORT extern "C" __declspec(dllexport)

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
// section added for DLL usage

char * toCharArr(std::string s) {
	static char * converted;
	delete[] converted;
	converted = new char[s.length()];
	for (size_t i = 0; i < s.length(); i++)
		converted[i] = s[i];
	return converted;
}

char * convertResults(std::vector<trg::Rect> r) {
	// get the results ready for export
	std::stringstream ss;
	for (size_t i = 0; i < r.size(); i++){
		ss << r[i].x1 << "," << r[i].y1 << "," << r[i].x2 << "," << r[i].y2 << ",";
	}
	std::string rs = ss.str();
	rs = rs.substr(0, rs.length() - 1);// remove trailing comma
	//return (char *)rs.c_str();
	return toCharArr(rs);
}

DLLEXPORT char* getTextBBoxesFromFile(char* path, int w, int h) {
	size_t picWidth = w;
	size_t picHeight = h;
	char *picName = path;
	std::vector<char> buf(picWidth * picHeight * 3);

	// read the file
	std::filebuf fb;
	fb.open(path, std::ios_base::in | std::ios_base::binary);
	fb.sgetn((char*)&buf[0], buf.size() * sizeof(buf[0]));

	// do the image processing
	std::vector<std::vector<trg::Rgb>> a (picHeight, std::vector<trg::Rgb>(picWidth, {0, 0, 0}));
	for (size_t y = 0; y < picHeight; ++y) {
	    for (size_t x = 0; x < picWidth; ++x) {
	        size_t pos = 3 * y * picWidth + 3 * x;
	        trg::Rgb pixel = {buf[pos], buf[pos + 1], buf[pos + 2]};
	        a[y][x] = pixel;
	    }
	}
	std::vector<trg::Rect> r = trg::get_textlike_regions(a);

	return convertResults(r);
}

DLLEXPORT char* getTextBBoxesFromBytes(char* b, int w, int h) {
	std::vector<std::vector<trg::Rgb>> a(h, std::vector<trg::Rgb>(w, { 0, 0, 0 }));

	for (size_t y = 0; y < h; ++y) {
		for (size_t x = 0; x < w; ++x) {
			size_t pos = 3 * y * w + 3 * x;
			trg::Rgb pixel = { b[pos], b[pos + 1], b[pos + 2] };
			a[y][x] = pixel;
		}
	}
	std::vector<trg::Rect> r = trg::get_textlike_regions(a);

	return convertResults(r);
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------