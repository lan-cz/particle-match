//
// Created by rokas on 17.9.11.
//

#pragma once


#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

class AffineTransformation {
public:
    cv::Mat T;
    int id;
};


