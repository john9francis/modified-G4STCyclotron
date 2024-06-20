#include "modDetMessenger.hh"

ModifiedDetMessenger::ModifiedDetMessenger(ModifiedDetConst* pModDet) : fModDet(pModDet){
  fMoveDetectors = new G4UIdirectory("/moveDetectors/");
  fMoveDetectors->SetGuidance("Move the z distance \
  of the target or foil. NOTE: This feature is \
  modified from the original stcyclotron app.");

  fSetTargetZCmd = new G4UIcmdWithADoubleAndUnit("/moveDetectors/setTargetZ", this);
  fSetTargetZCmd->SetGuidance("Set the z position of the target. e.g. 5 cm.");
  fSetTargetZCmd->SetParameterName("Position", false);
  fSetTargetZCmd->SetDefaultUnit("mm");

  fSetFoilZCmd = new G4UIcmdWithADoubleAndUnit("/moveDetectors/setFoilZ", this);
  fSetFoilZCmd->SetGuidance("Set the z position of the foil. e.g. 5 cm.");
  fSetFoilZCmd->SetParameterName("Position", false);
  fSetFoilZCmd->SetDefaultUnit("mm");
}

ModifiedDetMessenger::~ModifiedDetMessenger(){
  delete fMoveDetectors;
  delete fSetTargetZCmd;
  delete fSetFoilZCmd;
}

void ModifiedDetMessenger::SetNewValue(G4UIcommand* cmd, G4String newValue){
  if (cmd == fSetTargetZCmd){
    G4double newZ = fSetTargetZCmd->GetNewDoubleValue(newValue);
    fModDet->SetTargetZ(newZ);

    // move the analysis graphs accordingly
  }

  if (cmd == fSetFoilZCmd){
    G4double newZ = fSetFoilZCmd->GetNewDoubleValue(newValue);
    fModDet->SetTargetZ(newZ);
  
    // move the analysis graphs accordingly
  }
}