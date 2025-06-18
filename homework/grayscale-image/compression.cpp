#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image)
{
    std::vector<std::pair<uint8_t, uint8_t>> v;
    v.reserve(width * height);
    
    uint8_t pixelPrev{0};
    uint8_t n{0};

    for(const auto& row : image)
    {
        pixelPrev = row[0];
        n = 0;

        for(std::size_t i = 0; i < row.size(); ++i)
        {
            if(pixelPrev == row[i])
            {
                n++;
            }

            if((pixelPrev != row[i]) || ((i + 1) == row.size()))
            {
                v.emplace_back(pixelPrev, n);
                pixelPrev = row[i];
                n = 1;
            }
        }
    }

    v.shrink_to_fit();
    
    return v;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& v)
{
    std::array<std::array<uint8_t, width>, height> image;

    uint8_t n{0};
    size_t rowNum{0};

    for(const auto& p : v)
    {
        for(size_t i = 0; i < p.second; ++i)
        {
            image.at(rowNum).at(n+i) = p.first;  
        }

        n += p.second;
        if(n == width)
        {
            ++rowNum;
            n = 0;
        }
    }

    return image;
}