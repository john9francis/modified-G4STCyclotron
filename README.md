# Modified STCyclotron

This is a copy of the official Geant4 STCyclotron example, but modified to use any geometry.

# Changes to original
- New files: "modDetConst.hh" and "modDetConst.cc" define a modified detector construction that can be customized as desired. They still include the target and the foil, only because these geometries are basically required for the app to work. So many parts of the program depend on these two geometries including the graphs produced and the messengers.
  - This new class defines the tube part4 outer radius and the tube part 4 length to 1 m each. The reason for this is that when modifying the target geometry, the program throws an error if the target is bigger than the tube it's in. Even though tube part 4 doesn't exist in the world, these member variables still restrict the size of the target. Setting them both to 1 m gives the target sufficient freedom to be modified.
- STCyclotron.cc: instead of registering the STCyclotronDetectorConstruction, I registered my own class, "ModifiedDetConst"
- STCyclotronDetectorConstruction.hh: added the keyword `virtual` to the `SetFoilThickness(G4double)` function so that I could override it. The reason for this was because the original function references some of the tube's geometries like, "fPhysLayer_PART3" etc. Since these were initialized as null, it causes a seg fault. So this function needed to be rewritten to not reference these null pointers at all.

# Todo:
- [x] Get it running outside a container so I can get an OGL viewer.
- [x] Dockerize it. update: docker image can be found [here](https://hub.docker.com/repository/docker/john9francis/modified_stcyclotron)


# Acknowledgments
- This software contains official [Geant4](https://geant4.web.cern.ch/) software and should only be used according to it's license. 
