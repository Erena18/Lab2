#include "Image.h"
#include <fstream>

Image::Image(int width, int height)
    : width(width), height(height)
{
    data.resize(height, std::vector<Pixel>(width));
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

void Image::generateTestImage()
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            data[y][x].r = x % 256;
            data[y][x].g = y % 256;
            data[y][x].b = (x + y) % 256;
        }
    }
}

void Image::invertBlock(int startRow, int endRow)
{
    for(int y = startRow; y < endRow; y++)
    {
        for(int x = 0; x < width; x++)
        {
            data[y][x].r = 255 - data[y][x].r;
            data[y][x].g = 255 - data[y][x].g;
            data[y][x].b = 255 - data[y][x].b;
        }
    }
}

void Image::save(const std::string& filename)
{
    std::ofstream file(filename, std::ios::binary);

    file << "P6\n";
    file << width << " " << height << "\n255\n";

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            file.write((char*)&data[y][x], 3);
        }
    }

    file.close();
}