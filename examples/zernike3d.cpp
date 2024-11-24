/*
                          3D Zernike Moments
    Copyright (C) 2003 by Computer Graphics Group, University of Bonn
           http://www.cg.cs.uni-bonn.de/project-pages/3dsearch/

Code by Marcin Novotni:     marcin@cs.uni-bonn.de

for more information, see the paper:

@inproceedings{novotni-2003-3d,
    author = {M. Novotni and R. Klein},
    title = {3{D} {Z}ernike Descriptors for Content Based Shape Retrieval},
    booktitle = {The 8th ACM Symposium on Solid Modeling and Applications},
    pages = {216--225},
    year = {2003},
    month = {June},
    institution = {Universit\"{a}t Bonn},
    conference = {The 8th ACM Symposium on Solid Modeling and Applications, June 16-20, Seattle, WA}
}
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                License                                    *
 *                                                                           *
 *  This library is free software; you can redistribute it and/or modify it  *
 *  under the terms of the GNU Library General Public License as published   *
 *  by the Free Software Foundation, version 2.                              *
 *                                                                           *
 *  This library is distributed in the hope that it will be useful, but      *
 *  WITHOUT ANY WARRANTY; without even the implied warranty of               *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU        *
 *  Library General Public License for more details.                         *
 *                                                                           *
 *  You should have received a copy of the GNU Library General Public        *
 *  License along with this library; if not, write to the Free Software      *
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                *
 *                                                                           *
\*===========================================================================*/

/*
    This is a demonstration of how the classes may be used to generate the
    3D Zernike descriptors from a given input binary file containing the
    voxel grid representation of the object.

    Notice that in the below case, the file contains a cubic grid, i.e. the
    x-, y-, and z-dimensions are equal (such setting should satisfy most needs).
*/

// ---- local includes ----
#include "ZernikeDescriptor.h"

// ---- std includes ----
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>


int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: ZernikeMoments <filename> <MaxOrder>\n";
        return 0;
    }

    std::string inputFile(argv[1]);
    int maxOrder = std::stoi(argv[2]);

    // Extract base filename without extension
    size_t lastDot = inputFile.find_last_of('.');
    // If not found, lastDot == std::string::npos --> take the whole string
    std::string baseName = inputFile.substr(0, lastDot);

    // Compute the zernike descriptors
    ZernikeDescriptor<double, float> zd(inputFile.c_str(), maxOrder);

    // Generate output .inv filename
    std::string invFileName = baseName + ".inv";
    std::cout << "Saving invariants file: " << invFileName << '\n';
    zd.SaveInvariants(invFileName.c_str());

    // Generate output .txt filename
    std::string invFileNameTXT = baseName + ".txt";
    std::cout << "Saving invariants file: " << invFileNameTXT << '\n';
    zd.SaveInvariantsTXT(invFileNameTXT.c_str());

    return 0;
}