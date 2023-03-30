// GEANT4 //
#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4TessellatedSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

#include "G4VModularPhysicsList.hh"
#include "G4Gamma.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4SystemOfUnits.hh"

#include "CADMesh.hh"


class DetectorConstruction : public G4VUserDetectorConstruction{
    private:
        G4String filename;

    public:
        DetectorConstruction(G4String const& filename);
        ~DetectorConstruction();
        G4VPhysicalVolume* Construct();
};


class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
    private:
        G4GeneralParticleSource* particle_gun;

    public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction();
        void GeneratePrimaries(G4Event* event);
};
