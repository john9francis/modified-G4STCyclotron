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

  // returns the start of the target position.
  // this function is for the depth graph to start at 0.
  G4double GetTargetStartZ();

private:
  void SetTargetZ(G4double newZ);
  void SetFoilZ(G4double newZ);

  ModifiedDetMessenger* fModDetMessenger;

  friend class ModifiedDetMessenger;
};


#endif