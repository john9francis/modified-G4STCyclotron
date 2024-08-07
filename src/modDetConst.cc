#include "modDetConst.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"

#include "G4UnitsTable.hh"
#include "G4RunManager.hh"

#include "G4AnalysisManager.hh"
#include "G4UImanager.hh"

#include "modDetMessenger.hh"

ModifiedDetConst::ModifiedDetConst() : STCyclotronDetectorConstruction() {
  G4cout << "Hello Modified Detector Construction" << G4endl;

  // Set all the lengths to very large so we don't have any restrictions
  fTube_outerRadius_PART4 = 1 * m;
  fTube_length_PART4 = 1 * m;

  fModDetMessenger = new ModifiedDetMessenger(this);
}

ModifiedDetConst::~ModifiedDetConst() {
  delete fModDetMessenger;
}

void ModifiedDetConst::SetTargetZ(G4double newZ){

  G4int worldBorder; // todo: Make sure it doesn't leave the world

  G4cout 
    << "Setting Target Z to: " 
    << G4BestUnit(newZ, "Length")
    << G4endl;

  fTarget_z_position = newZ;
  fPhysTarget->SetTranslation(G4ThreeVector(0, 0, newZ));

  G4cout 
    << "The target's Z position is now: "
    << G4BestUnit(fPhysTarget->GetObjectTranslation().getZ(), "Length")
    << G4endl;

  G4RunManager::GetRunManager() -> GeometryHasBeenModified();
  G4cout << "... Geometry is notified .... " << G4endl;


  G4cout
    << "The actual fTarget_z_position value is: "
    << fTarget_z_position
    << G4endl;

  G4cout 
    << "The target position is now: "
    << "Starting: "
    << fTarget_z_position - fTarget_thickness
    << " Ending: "
    << fTarget_z_position + fTarget_thickness
    << G4endl;


  // // move the analysis graphs
  // auto analysisManager = G4AnalysisManager::Instance();
  
  // // Reference:
  // // /analysis/h1/set 4  30  185. 188. mm	#depth of isotope creation in the target.
  // // /analysis/h2/setX 3  100 185. 188. mm
  // // /analysis/h2/setY 3  100 0. 19. MeV     #depth = f(energy (MeV))
  // analysisManager->SetH1(4, 30, fTarget_z_position - fTarget_thickness, fTarget_z_position + fTarget_thickness, "mm");
  // analysisManager->SetH2(3, 100, fTarget_z_position - fTarget_thickness, fTarget_z_position + fTarget_thickness,
  //   100, 0, 19, "mm", "MeV");

}

void ModifiedDetConst::SetFoilZ(G4double newZ){

  G4int worldBorder; // todo: Make sure it doesn't leave the world

  G4cout 
    << "Setting Foil Z to: " 
    << G4BestUnit(newZ, "Length")
    << G4endl;

  fPhysFoil->SetTranslation(G4ThreeVector(0, 0, newZ));

  G4cout
    << "The foil's Z position is now: "
    << G4BestUnit(fPhysFoil->GetObjectTranslation().getZ(), "Length")
    << G4endl;

  G4RunManager::GetRunManager() -> GeometryHasBeenModified();
  G4cout << "... Geometry is notified .... " << G4endl;
}

G4double ModifiedDetConst::GetTargetStartZ(){
  return fTarget_z_position - 0.5 * fTarget_thickness;
}


G4VPhysicalVolume* ModifiedDetConst::Construct(){
  //Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  
  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = true;


  //Create the world
  G4double world_hx = 1.*m;
  G4double world_hy = 1.*m;
  G4double world_hz = 1.*m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");

  G4Box* solidWorld 
    = new G4Box("World",
		world_hx, 
		world_hy, 
		world_hz);
  
  fLogicWorld
    = new G4LogicalVolume(solidWorld,
			  world_mat,
			  "World");

  G4VPhysicalVolume* physWorld 
    = new G4PVPlacement(0,                     //no rotation
			G4ThreeVector(),       //at (0,0,0)
			fLogicWorld,            //its logical volume
			"World",               //its name
			0,                     //its mother  volume
			false,                 //no boolean operation
			0);                    //copy number



  /* TARGET AND FOIL */

  //Overall parameters
  G4double startAngle     = 0.*deg;
  G4double spanningAngle  = 360.*deg;

  //Initialization of messenger parameters
  fTarget_diameter = 7.*mm;
  fDensity_target = 8.9*g/cm3;
  fTarget_thickness = 0.35*mm;
  fFoil_thickness = 0.000001*mm;
  fDensity_foil = 2.7*g/cm3;

  /* TARGET */
  fTarget_Material = nist->FindOrBuildMaterial("G4_Ti");

  G4double target_innerRadius     = 0.*mm;
  G4double target_outerRadius     = 0.5*fTarget_diameter;
  G4double target_hz              = 0.5*fTarget_thickness;
 
  // target position same as original
  fTarget_z_position = 186.24500099999997 * mm;

  fSolidTarget 
    = new G4Tubs("Target",
		 target_innerRadius,
		 target_outerRadius,
		 target_hz,
		 startAngle,
		 spanningAngle);

  fTargetVolume = fSolidTarget->GetCubicVolume();
  
  fLogicTarget
    = new G4LogicalVolume(fSolidTarget,
			  fTarget_Material,
			  "Target");

  fPhysTarget
    = new G4PVPlacement(0,                                                  
			G4ThreeVector(0.*mm,0.*mm, fTarget_z_position),      
			fLogicTarget,                                       
			"Target",                                          
			fLogicWorld,                                 
			false,                                           
			0,                                               
			checkOverlaps);    


  /* FOIL */
  fFoil_Material = nist->FindOrBuildMaterial("G4_Ti");
  
  G4double foil_innerRadius    = 0.*mm;
  G4double foil_outerRadius    = 16.*mm;
  
  // foil position same as original
  fZ_foil_position = 136.6000005 * mm;

  fSolidFoil 
    = new G4Tubs("Foil",
		 foil_innerRadius,
		 foil_outerRadius,
		 0.5*fFoil_thickness,
		 startAngle,
		 spanningAngle);
  
  fFoilVolume = fSolidFoil->GetCubicVolume();
  
  fLogicFoil
    = new G4LogicalVolume(fSolidFoil,
			  fFoil_Material,
			  "Foil");
  
  fPhysFoil
    = new G4PVPlacement(0,                                    
			G4ThreeVector(0.*mm,0.*mm,fZ_foil_position),   
			fLogicFoil,                           
			"Foil",                              
			fLogicWorld,                          
			false,                               
			0,                                    
			checkOverlaps);                       
                                 

  // For G4Region for physics lists
  if(!fRegionTarget)
    {
      fRegionTarget = new G4Region("Target");
      fLogicTarget -> SetRegion(fRegionTarget);
      fRegionTarget -> AddRootLogicalVolume(fLogicTarget);
    }
  if(!fRegionFoil&&fPhysFoil!=nullptr)
    {
      fRegionFoil = new G4Region("Foil");
      fLogicFoil -> SetRegion(fRegionFoil);
      fRegionFoil -> AddRootLogicalVolume(fLogicFoil);
    }

  G4cout << "Modified Detectors sucessfully constructed" << G4endl;
  return physWorld;
}

void ModifiedDetConst::SetFoilThickness(G4double foilThickness){
  G4cout << "Setting Modified Foil Thickness" << G4endl;

  if(fFoil_thickness != foilThickness){
    //Change the thickness
    if(fSolidFoil) fSolidFoil->SetZHalfLength(0.5*foilThickness*mm);
    G4cout << "The new thickness of the foil is " << fFoil_thickness << " mm." << G4endl;
  }     
}