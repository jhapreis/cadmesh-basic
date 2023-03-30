#include "basic.hh"


DetectorConstruction::DetectorConstruction(G4String const& filename)
:
filename(filename)
{

}

DetectorConstruction::~DetectorConstruction() = default;

G4VPhysicalVolume* DetectorConstruction::Construct(){
    // Materials //
    G4NistManager * nist_manager = G4NistManager::Instance();
    G4Material * air = nist_manager->FindOrBuildMaterial("G4_AIR");
    G4Material * water = nist_manager->FindOrBuildMaterial("G4_WATER");

    // World //
    auto world_solid = new G4Box("world_solid", 2000*mm, 200*cm, 2*m);

    auto world_logical = new G4LogicalVolume(world_solid, air, "world_logical", nullptr, nullptr, nullptr);

    world_logical->SetVisAttributes(G4VisAttributes::GetInvisible());

    auto world_physical = new G4PVPlacement(nullptr, G4ThreeVector(), world_logical, "world_physical", nullptr, false, 0);

    auto cow_mesh = CADMesh::TessellatedMesh::FromOBJ(filename);
    cow_mesh->SetScale(500);

    auto cow_logical = new G4LogicalVolume( cow_mesh->GetSolid(), water, "logical", nullptr, nullptr, nullptr);

    new G4PVPlacement(nullptr, G4ThreeVector(-500, -500, 1000), cow_logical, "physical", world_logical, false, 0);

    return world_physical;
};



PrimaryGeneratorAction::PrimaryGeneratorAction(){
    particle_gun = new G4GeneralParticleSource();
    particle_gun->SetParticleDefinition(G4Gamma::Definition());
};

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
    delete particle_gun;
};

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event){
    particle_gun->GeneratePrimaryVertex(event);
};
