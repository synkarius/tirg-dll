#include "stdafx.h"
#include "trg.hpp"
#define DLLEXPORT extern "C" __declspec(dllexport)

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
// section added for DLL usage
DLLEXPORT char* getTextBBoxes(char* path, int w, int h) {
	//    size_t picWidth = w;
	//    size_t picHeight = h;
	//    char *picName = path;
	//
	//    char buf[picWidth * picHeight * 3];
	//    FILE *fp = fopen(picName, "rb");
	//    fread(buf, 1, sizeof(buf), fp);
	//    fclose(fp);
	//
	//    //std::vector<std::vector<trg::Rgb> > a(picHeight, picWidth);
	//    std::vector<std::vector<trg::Rgb>> a (picHeight, std::vector<trg::Rgb>(picWidth, {0, 0, 0}));
	//
	//    for (size_t y = 0; y < picHeight; ++y) {
	//        for (size_t x = 0; x < picWidth; ++x) {
	//            size_t pos = 3 * y * picWidth + 3 * x;
	//            trg::Rgb pixel = {buf[pos], buf[pos + 1], buf[pos + 2]};
	//            a[y][x] = pixel;
	//        }
	//    }
	//
	//    std::vector<trg::Rect> r = trg::get_textlike_regions(a);
	//
	//
	//    printf("Detected %d region(s):\n", r.size());
	//    if (!r.empty()) {
	//        for (size_t i = 0; i < r.size(); ++i) {
	//            printf("%3d. (%d, %d) (%d, %d)\n", i + 1, r[i].x1, r[i].y1, r[i].x2, r[i].y2);
	//        }
	//    }


	return path;
}

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
int main1() {

	const size_t picWidth = 300;
	const size_t picHeight = 225;
	const char *picName = "222t.png";

	char buf[picWidth * picHeight * 3];
	FILE *fp;
	errno_t errorCode = fopen_s(&fp, picName, "rb");
	fread(buf, 1, sizeof(buf), fp);
	fclose(fp);

	//std::vector<std::vector<trg::Rgb> > a(picHeight, picWidth);
	std::vector<std::vector<trg::Rgb>> a(picHeight, std::vector<trg::Rgb>(picWidth, { 0, 0, 0 }));

	for (size_t y = 0; y < picHeight; ++y) {
		for (size_t x = 0; x < picWidth; ++x) {
			size_t pos = 3 * y * picWidth + 3 * x;
			trg::Rgb pixel = { buf[pos], buf[pos + 1], buf[pos + 2] };
			a[y][x] = pixel;
		}
	}

	std::vector<trg::Rect> r = trg::get_textlike_regions(a);

	puts("====================================");
	puts(picName);
	puts("====================================");
	printf("Detected %d region(s):\n", r.size());
	puts("====================================");
	if (!r.empty()) {
		for (size_t i = 0; i < r.size(); ++i) {
			printf("%3d. (%d, %d) (%d, %d)\n", i + 1, r[i].x1, r[i].y1, r[i].x2, r[i].y2);
		}
	}
	else
		printf("...Nothing to report...\n");
	puts("====================================");
	puts("Press any key to exit...");
	getchar();
	return 0;
}