#ifndef ModifiedDetConst_HH
#define ModifiedDetConst_HH 1

#include "STCyclotronDetectorConstruction.hh"
#include "STCyclotronDetectorMessenger.hh"

class ModifiedDetMessenger;

class ModifiedDetConst : public STCyclotronDetectorConstruction {
public:
  ModifiedDetConst();
  ~ModifiedDetConst();

  G4VPhysicalVolume* Construct() override;

  void SetFoilThickness(G4double foilThickness) override;

private:
  void SetTargetZ(G4double newZ);
  void SetFoilZ(G4double newZ);

  ModifiedDetMessenger* fModDetMessenger;

  friend class ModifiedDetMessenger;
};


#endif