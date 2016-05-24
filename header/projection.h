/* 
 * File:   Projection.h
 * Author: clinm
 *
 * Created on 18 mai 2016, 10:06
 */

#ifndef PROJECTION_H
#define	PROJECTION_H

#include <iostream>
#include <vector>
#include "image_io.h"
#include "CImg.h"
#include <stdlib.h>

using namespace cimg_library;
using namespace std;

#define BLACK_PIXEL 0
#define WHITE_PIXEL 255

namespace projection {
    
    /**
     * Projects from left to right. Counts the number of white pixels starting
     * from the left
     * @param img The image to project
     * @return A vector where each entry corresponds to the number of white pixel
     *         before a non-white one.
     */
    vector<int> leftward(CImg<> img);
    
    /**
     * Displays the projection as an image. The number of white pixels are displayed
     * in black and the 'shadow' of the form remains in white
     * @param left      The left projection of the image
     * @param width     Its width (in order to keep the image's dimension
     * @return          An image representing the shadow
     */
    CImg<> leftwardToImg(vector<int> left, int width);
    
    /**
     * Projects from up to down. Counts the number of white pixels starting
     * from the top
     * @param img The image to project
     * @return A vector where each entry corresponds to the number of white pixel
     *         before a non-white one.
     */   
    vector<int> upward(CImg<> img);
  
    /**
     * Displays the projection as an image. The number of white pixels are displayed
     * in black and the 'shadow' of the form remains in white
     * @param left      The up projection of the image
     * @param width     Its width (in order to keep the image's dimension
     * @return          An image representing the shadow
     */
    CImg<> upwardToImg(vector<int> top, int height);
 
    /**
     * Give the first index of the vector which is not equal to 'value'. 
     * If beginning is set to 'TRUE', index is computed from the beginning.
     * If beginning is set to 'FALSE', index is computed from the end
     * @param projection    Result of a projection on one axis
     * @param value         Value
     * @param beginning     TRUE = beginning, FALSE = end
     * @return  The index of the first value non equal to 'value'
     */
    int firstNonEqual(vector<int> projection, int value, bool beginning = true);
    
    /**
     * Reduces the image to its core content. Remove all unecessary white borders
     * @param img The image to reduce
     * @return The same image without the white borders
     */
    CImg<> reduce(CImg<> img);
    
    /**
     *  Split the given text into lines 
     * @param text      The text to split
     * @param lines     The line extracted
     */
    void splitLines(const CImg<>& text, vector< CImg<>* >& lines);
    
    /**
     * Given a line split into characters
     * @param line         The line to split
     * @param characters    List of characters found
     */
    void splitCharacters(const CImg<>& line, vector< CImg<>* >& characters);
};

#endif	/* PROJECTION_H */
