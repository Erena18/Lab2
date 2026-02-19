#pragma once

#include <opencv2/opencv.hpp>
#include <string>


class Image
{
private:

    cv::Mat data; //хранение изображения в виде матрицы пикселей
public:

    Image() {};

    Image(int w,int h);

    bool load(const std::string& path);
    void save(const std::string& path);
    int height() const;
    int width() const;
    void generateTestImage(int w,int h);
    void invertBlock(int startRow,int endRow);
};