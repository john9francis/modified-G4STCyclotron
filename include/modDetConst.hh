#ifndef ModifiedDetConst_HH
#define ModifiedDetConst_HH 1

#include "STCyclotronDetectorConstruction.hh"

class ModifiedDetConst : public STCyclotronDetectorConstruction {
public:
  ModifiedDetConst() : STCyclotronDetectorConstruction() { 
    G4cout << "Hello Modified Detector Construction" << G4endl;
  }
};


#endif