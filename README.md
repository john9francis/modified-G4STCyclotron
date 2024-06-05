# Modified STCyclotron

This is a copy of the official Geant4 STCyclotron example, but modified to use any geometry.

# Changes to original
- STCyclotron.cc: instead of registering the STCyclotronDetectorConstruction, I registered my own class, "ModifiedDetConst"
- STCyclotronDetectorConstruction.hh: added the keyword `virtual` to the `SetFoilThickness(G4double)` function so that I could override it. The reason for this was because the original function references some of the tube's geometries like, "fPhysLayer_PART3" etc. Since these were initializes as null, it causes a seg fault. So this function needed to be rewritten to not reference these null pointers at all.

# Todo:
- [ ] Get it running outside a container so I can get an OGL viewer.
