# Marching Cubes for MRI Brain Images
## Marching Cubes for Medical Image Processing Course CS736
Authors
- Bijoy Singh Kochar 
- Meet Shah
- Nishanth Koushik

Instructor
- Prof. Suyash Awate

A course project implementation of [Marching Cube](http://www.eecs.berkeley.edu/~jrs/meshpapers/LorensenCline.pdf)

## MARCHING CUBES: A HIGH RESOLUTION 3D SURFACE CONSTRUCTION ALGORITHM
Authors
- William E. Lorensen
- Harvey E. Cline

### Abstract
We present a new algorithm, called marching cubes, that
creates triangle models of constant density surfaces from 3D
medical data. Using a divide-and-conquer approach to generate
inter-slice connectivity, we create a case table that
defines triangle topology. The algorithm processes the 3D
medical data in scan-line order and calculates triangle vertices
using linear interpolation. We find the gradient of the original
data, normalize it, and use it as a basis for shading the
models. The detail in images produced from the generated
surface models is the result of maintaining the inter-slice
connectivity, surface data, and gradient information present
in the original 3D data. Results from computed tomography
(CT), magnetic resonance (MR), and single-photon emission
computed tomography (SPECT) illustrate the quality and
functionality of marching cubes. We also discuss improvements
that decrease processing time and add solid modeling
capabilities

## References
[Paper](http://www.eecs.berkeley.edu/~jrs/meshpapers/LorensenCline.pdf)
[Paul Bourke](http://paulbourke.net/geometry/polygonise/)
[Simpler 2D Versions](http://users.polytech.unice.fr/~lingrand/MarchingCubes/algo.html)