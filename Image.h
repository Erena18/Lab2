#pragma once

#include <vector>
#include <string>

struct Pixel
{
    unsigned char r, g, b;
};

class Image
{
private:

    int width;
    int height;

    std::vector<std::vector<Pixel>> data;

public:

    Image(int width, int height);

    int getWidth() const;
    int getHeight() const;

    void generateTestImage();

    void invertBlock(int startRow, int endRow);

    void save(const std::string& filename);
};