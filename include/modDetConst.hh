#ifndef ModifiedDetConst_HH
#define ModifiedDetConst_HH 1

#include "STCyclotronDetectorConstruction.hh"
#include "STCyclotronDetectorMessenger.hh"


class ModifiedDetConst : public STCyclotronDetectorConstruction {
public:
  ModifiedDetConst();

  G4VPhysicalVolume* Construct() override;

  void SetFoilThickness(G4double foilThickness);
  
};


#endif