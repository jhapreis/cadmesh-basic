#include "basic.hh"

int main(int argc, char** argv){

    auto run_manager = new G4RunManager();

    auto detector_construction = new DetectorConstruction(argv[1]);
    run_manager->SetUserInitialization(detector_construction);

    auto physics_list = new G4VModularPhysicsList();
    run_manager->SetUserInitialization(physics_list);

    auto primary_generator_action = new PrimaryGeneratorAction();
    run_manager->SetUserAction(primary_generator_action);

    run_manager->Initialize();

    auto vis_manager = new G4VisExecutive();
    vis_manager->Initialize();

    auto session = G4UImanager::GetUIpointer();

    // Source //
    session->ApplyCommand("/gps/pos/type Volume");
    session->ApplyCommand("/gps/pos/shape Para");
    session->ApplyCommand("/gps/pos/confine world_physical");
    session->ApplyCommand("/gps/ang/type iso");
    session->ApplyCommand("/gps/pos/halfx 2 m");
    session->ApplyCommand("/gps/pos/halfy 2 m");
    session->ApplyCommand("/gps/pos/halfz 2 m");

    // Run //
    auto ui = new G4UIExecutive(argc, argv);
    session->ApplyCommand("/control/execute macros/init_vis.mac");
    ui->SessionStart();

    delete session;
    delete ui;
}
