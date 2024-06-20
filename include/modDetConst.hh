#ifndef ModifiedDetConst_HH
#define ModifiedDetConst_HH 1

#include "STCyclotronDetectorConstruction.hh"
#include "STCyclotronDetectorMessenger.hh"
#include "modDetMessenger.hh"

class ModifiedDetConst : public STCyclotronDetectorConstruction {
public:
  ModifiedDetConst();
  ~ModifiedDetConst();

  G4VPhysicalVolume* Construct() override;

  void SetFoilThickness(G4double foilThickness) override;
private:
  ModifiedDetMessenger* fModDetMessenger;
};


#endif