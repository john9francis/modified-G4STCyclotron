#ifndef ModifiedDetConst_HH
#define ModifiedDetConst_HH 1

#include "STCyclotronDetectorConstruction.hh"
#include "STCyclotronDetectorMessenger.hh"


class ModifiedDetConst : public STCyclotronDetectorConstruction {
public:
  ModifiedDetConst() : STCyclotronDetectorConstruction() { 
    G4cout << "Hello Modified Detector Construction" << G4endl;

    // modify detector messenger to track this instead of the STCyclotron det cons.
    delete fDetectorMessenger;
    fDetectorMessenger = new STCyclotronDetectorMessenger(this);
  }

  G4VPhysicalVolume* Construct() override;
};


#endif