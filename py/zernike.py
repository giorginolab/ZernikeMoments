import numpy as np

def generate_sphere_voxel_grid(dim, radius):
    # Create an empty voxel grid with dimensions dim x dim x dim
    voxels = np.zeros((dim, dim, dim), dtype=np.float32)
    
    # Define the center of the sphere
    center = dim // 2

    # Populate the voxel grid with a sphere of given radius
    for x in range(dim):
        for y in range(dim):
            for z in range(dim):
                dx = x - center
                dy = y - center
                dz = z - center
                if dx * dx + dy * dy + dz * dz <= radius * radius:
                    voxels[x, y, z] = 1.0

    return voxels

def save_voxel_grid_as_binary(filename, voxel_grid):
    # Save the voxel grid to a binary file
    with open(filename, 'wb') as f:
        voxel_grid.tofile(f)

if __name__ == "__main__":
    # Define the dimensions and radius as used in the C++ test case
    dim = 32
    radius = 10

    # Generate the voxel grid containing a sphere
    voxel_grid = generate_sphere_voxel_grid(dim, radius)

    # Save the voxel grid to a binary file
    save_voxel_grid_as_binary("sphere_voxel_grid.bin", voxel_grid)

    print(f"Voxel grid with a sphere of radius {radius} saved to 'sphere_voxel_grid.bin'")
