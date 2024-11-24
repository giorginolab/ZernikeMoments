#include "ZernikeDescriptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main()
{
    // Define the dimensions of the voxel grid (a cube of 32x32x32 for simplicity)
    const int dim = 32;
    std::vector<double> voxels(dim * dim * dim, 0.0);

    // Define a sphere with radius 10 centered in the middle of the voxel grid
    const int radius = 10;
    const int center = dim / 2;

    for (int x = 0; x < dim; ++x)
    {
        for (int y = 0; y < dim; ++y)
        {
            for (int z = 0; z < dim; ++z)
            {
                int dx = x - center;
                int dy = y - center;
                int dz = z - center;
                if (dx * dx + dy * dy + dz * dz <= radius * radius)
                {
                    voxels[(z * dim + y) * dim + x] = 1.0;
                }
            }
        }
    }

    // Compute the Zernike descriptors for the sphere
    int maxOrder = 10; // Set the maximum order for Zernike moments
    ZernikeDescriptor<double, double> zd(voxels.data(), dim, maxOrder);

    // Save the invariants to a text file
    std::cout << "Zernike descriptors computed for a sphere of radius " << radius << " in a grid of size " << dim << "^3." << std::endl;

    auto invariants = zd.GetInvariants();
    for (const auto& value : invariants)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
