# Notes added by Toni

The `examples/main.cpp` file compiles into a `zernike3d` executable which is a front-end. 
The code is a header library templated for data types. For example,  ZernikeDescriptor<double, float>` 
means use double internally, but read floats from file (elsewhere?).

The grid file is a dump of floating point values in native endianness of a CUBIC grid (i.e. three
equal axes). The size is determined automatically in ReadGrid. The function also converts from 
type TIn to T.



