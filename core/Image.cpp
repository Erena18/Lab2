#include "Image.h"

Image::Image(int w,int h)
{
    data = cv::Mat(h,w,CV_8UC3);
}

bool Image::load(const std::string& path)
{
    data = cv::imread(path);
    return !data.empty();
}

void Image::save(const std::string& path)
{
    cv::imwrite(path,data);
}

int Image::height() const { return data.rows; }
int Image::width() const { return data.cols; }

void Image::generateTestImage(int w,int h)
{
    data = cv::Mat(h,w,CV_8UC3);

    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            data.at<cv::Vec3b>(y,x) = cv::Vec3b(x%256,y%256,(x+y)%256);
        }
    }
}

void Image::invertBlock(int startRow,int endRow)
{
    for(int y=startRow;y<endRow;y++)
        for(int x=0;x<data.cols;x++)
        {
            cv::Vec3b& p = data.at<cv::Vec3b>(y,x);
            p[0] = 255 - p[0];
            p[1] = 255 - p[1];
            p[2] = 255 - p[2];
        }
}