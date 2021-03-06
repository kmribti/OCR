/* 
 * File:   base_test_segmentation.h
 * Author: clinm
 *
 * Created on 25 mai 2016, 15:51
 */

#ifndef BASE_TEST_SEGMENTATION_H
#define	BASE_TEST_SEGMENTATION_H

#include <stdlib.h>
#include <iostream>
#include <assert.h> 
#include <iostream>
#include <iomanip>
using namespace std;

#include "CImg.h"
using namespace cimg_library;

#include "overlappingSegmentation.h"
#include "image_io.h"
#include "preprocessing.h"
using namespace overlappingSegmentation;

#define FOLDER "./Images_Tests/segmentation/"

using namespace std;

#define DEBUG_NONE 0
#define DEBUG_FEW 1
#define DEBUG_LOT 2
#define DEBUG_DISPLAY 3

#define DEBUG_LEVEL DEBUG_NONE

#define debug(level, content)       \
    if(level <= DEBUG_LEVEL){         \
        cout << content;            \
    }                               



#if DEBUG_LEVEL == DEBUG_DISPLAY

#define display(img) image_io::displayImage(img);

#else

#define display(img)

#endif

#define printColumns(size, content) cout << setfill(' ') << setw(size) << setprecision(4) << content;


#endif	/* BASE_TEST_SEGMENTATION_H */

/**
 *  Fonts' name. When adding a font, you have to make sure to provide one image per serie
 */
string fonts[] = {"anonymousPro", "arial", "calibri", "consolas", "comicSansMS", 
							"droidSerif", "impact", "roboto", 
							"timesNewRoman", "ubuntu", "VT323", "architectDaughter", "corsiva", "courgette","coveredByYourGrace", 
						"dancingScript", "indieFlower", "lobster", "shadowsIntoLight"};

#define NBFONTS 19


string fontsNonCursive[] = {"anonymousPro", "arial", "calibri", "consolas", "comicSansMS", 
							"droidSerif", "impact", "roboto", 
							"timesNewRoman", "ubuntu", "VT323"};

#define NBFONTS_NON_CURSIVE 11


string fontsCursive[] = {"architectDaughter", "corsiva", "courgette","coveredByYourGrace", 
						"dancingScript", "indieFlower", "lobster", "shadowsIntoLight"};
#define NBFONTS_CURSIVE 8
