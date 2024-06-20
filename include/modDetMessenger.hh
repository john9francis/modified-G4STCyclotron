// Goal: allow to move the target and foil's Z around.
// At the same time adjust the output graphs.

#ifndef MOD_DET_MESSENGER_HH
#define MOD_DET_MESSENGER_HH

#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

class ModifiedDetConst;

class ModifiedDetMessenger : public G4UImessenger {
public:
  ModifiedDetMessenger(ModifiedDetConst*);
  ~ModifiedDetMessenger();

  void SetNewValue(G4UIcommand*, G4String) override;

private:
  ModifiedDetConst* fModDet;

  G4UIdirectory* fMoveDetectors;

  G4UIcmdWithADoubleAndUnit* fSetTargetZCmd;
  G4UIcmdWithADoubleAndUnit* fSetFoilZCmd;
};

#endif